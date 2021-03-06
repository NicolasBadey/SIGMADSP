
#include "sigmadspfiles.h" 
#ifdef DSP_GENERIC_OK

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>   //need pow(10,x) for dB conversion

#define textFileLineSize 512
static char textFileLine[textFileLineSize]; // buffer for reading 1 line of the text file

static FILE* dspOutputFile = NULL;
static FILE* dspInputFile = NULL;

void dspPresetWriteFilters(char * filtname, dspFilter_t *f, int max){
    long i;
    for (i=0; i< max; i++)
        if ((i == 0)||(f[i].ftype != FNONE)) {
            if (f[i].ftype == FNONE)
                fprintf(dspOutputFile,"%s NONE\n",filtname);
            else {
                fprintf(dspOutputFile,"%s %s %d %d %d %5.1f",filtname,
                        dspFilterNames[ f[i].ftype ],
                        f[i].bypass,
                        f[i].invert,
                        f[i].locked,
                        f[i].freq );
                if(dspFilterNeedQ(f[i].ftype))
                    fprintf(dspOutputFile," %3.2f",f[i].Q);
                if (dspFilterNeedGain(f[i].ftype))
                    fprintf(dspOutputFile," %f",f[i].gain);
                fprintf(dspOutputFile,"\n"); }
        }
}

// save a table of preset (numberOfPresets>0)
void dspPresetWriteTextfile(dspPreset_t * p, int numberOfPresets, char * filename){

    dspOutputFile = fopen( filename, "w" );
    if( dspOutputFile == NULL ) {
      fprintf(stderr,"Error: Failed to create %s.\n",filename);
      fclose(dspOutputFile);
      return ; }
    fprintf(stderr,"saving %d presets\n",numberOfPresets);
    int num;
    for ( num=0; num < numberOfPresets; num++) {
        dspPresetChecksumUpdate(p);
        if (p->presetNumber == 0) p->presetNumber = num+1;
        if (num == 0)
             fprintf(dspOutputFile,"PRESET %d INPUTS %d, OUTPUTS %d, FILTERBANKSIZEMAX %d\n",p->presetNumber, p->numberOfInputs, p->numberOfOutputs, p->filterBankSize);
        else fprintf(dspOutputFile,"PRESET %d\n", p->presetNumber);
        int ch;
        DSP_FOR_ALL_CHANNELS(p,ch) {
            if (ch < p->numberOfInputs)
                 fprintf(dspOutputFile,"INPUT  %d / %d\n",ch+1, p->numberOfInputs);
            else fprintf(dspOutputFile,"OUTPUT %d / %d\n",ch+1 - p->numberOfInputs, p->numberOfOutputs);
            fprintf(dspOutputFile,"MIXER  ");
            int i;
            for (i=0; i< p->numberOfInputs; i++)
                fprintf(dspOutputFile,"%f ",p->fb[ch].mixer[i]);
            fprintf(dspOutputFile,"\n");
            fprintf(dspOutputFile,"GAIN   %f\n",p->fb[ch].gain);
            if (p->fb[ch].mute) fprintf(dspOutputFile,"MUTED\n");
            if (p->fb[ch].invert) fprintf(dspOutputFile,"INVERTED\n");
            if (ch >= p->numberOfInputs) // only for outputs
                fprintf(dspOutputFile,"DELAY  %f\n",p->fb[ch].delayMicroSec);
            if (filterHPAddr[ch])
                dspPresetWriteFilters("FILTHP", &p->fb[ch].filterHP[0], FILTER_HIPASS_SIZE);
            if (filterLPAddr[ch])
                dspPresetWriteFilters("FILTLP", &p->fb[ch].filterLP[0], FILTER_LOPASS_SIZE);
            dspPresetWriteFilters("FILTER",  &p->fb[ch].filter[0], p->fb[ch].numberOfFilters);
        }
        dspPresetChecksumUpdate(p);
        fprintf(dspOutputFile,"CHECKSUM %ld PRESET %d\n\n",p->checksum, p->presetNumber);
        p++;
    }
    fclose(dspOutputFile);
}


static long dspOpenInputFile(char *filename){
    dspInputFile = fopen( filename, "r" );
    if (dspInputFile == NULL) {
        fprintf(stderr,"Error: Failed to open file %s.\n",filename); return 0; }
    if(fseek( dspInputFile, 0, SEEK_END ) ) {
        fprintf(stderr,"Error: Failed to discover file size %s.\n", filename);
        fclose(dspInputFile);  return 0; }
    long fileSize = ftell( dspInputFile );
    if(fseek( dspInputFile, 0, SEEK_SET ) ) {
        fprintf(stderr,"Error: Failed to input file pointer %ld.\n",fileSize);
        fclose(dspInputFile);  return 0; }
    return fileSize;
}


void dspPresetReadFilters(char * s, dspFilter_t *f){
    char * NONE   = "NONE";
    char *err;
    //printf("%s\n",s);
    s+= 7; // skip word FILTER and space separator
    if (strstr(textFileLine, NONE) )
        *f = dspFilterNone;
    else {
        long ftype = dspFilterNameSearch(s);
        if (ftype) {
            f->ftype  = ftype;
            s += 6; // skip filter name+space
            f->bypass = strtol(s, &err,10); s=err;
            f->invert = strtol(s, &err,10); s=err;
            f->locked = strtol(s, &err,10); s=err;
            f->freq   = strtof(s, &err); s=err;
            if(dspFilterNeedQ(ftype)) {
                f->Q = strtof(s, &err); s=err; }
            if (dspFilterNeedGain(ftype))
                f->gain = strtof(s, &err);
          }
    }

}

// read a text file containing preset, read a maximum quantity of "numberOfPresets"
// if "numberOfPresets" is negative (eg -3) then read only 1 preset and search for index number 3
long dspPresetReadTextfile(dspPreset_t * p, long numberOfPresets, char * filename){
    long check = 1;
    long numPreset = 0;
    long increment = 0;
    if (numberOfPresets < 0) {
        numPreset = -numberOfPresets;
        numberOfPresets = 1; }
    long i;
    for (i=0; i< numberOfPresets; i++)  dspPresetReset(&p[i], 0);

    char * PRESET = "PRESET ";
    char * INPUT  = "INPUT ";
    char * OUTPUT = "OUTPUT ";  // always after inputs
    char * MIXER  = "MIXER ";
    char * GAIN   = "GAIN ";
    char * DELAY  = "DELAY ";
    char * MUTED  = "MUTED";
    char * INVERTED = "INVERTED";
    char * FILTER = "FILTER ";
    char * FILTHP = "FILTHP ";
    char * FILTLP = "FILTLP ";
    char * CHECKSUM = "CHECKSUM ";  // indicate the end of a preset definition

    if (dspOpenInputFile(filename)) {
    fprintf(stderr,"reading preset file\n");
    long ch = 0; long filter = 0; long filterHP = 0; long filterLP = 0;
    char *s; char *err;
    // read one full line from the file and search for unic key words
    while (fgets(textFileLine, sizeof(textFileLine)-1, dspInputFile)) {
        if (p->presetNumber != 0)
            if (ch< DSP_IO_TOTAL) {
                if ( ( s= strstr(textFileLine, FILTER) ) ) {
                    if (filter < filterBankSize[ch]) {
                        dspPresetReadFilters(s, &p->fb[ch].filter[filter]);
                        filter++; filterHP = 0; filterLP = 0;
                        continue; }
                } else
                if ( ( s= strstr(textFileLine, FILTHP) ) ) {
                    if (filterHP < FILTER_HIPASS_SIZE) {
                        dspPresetReadFilters(s, &p->fb[ch].filterHP[filterHP]);
                        filterHP++; filter = 0; filterLP = 0;
                        continue; }
                }else
                if ( ( s= strstr(textFileLine, FILTLP) ) ) {
                    if (filterLP < FILTER_LOPASS_SIZE) {
                        dspPresetReadFilters(s,&p->fb[ch].filterLP[filterLP]);
                        filterLP++; filter = 0; filterHP = 0;
                        continue; }
                }
            } // ch< DSP_IO_TOTAL
        filter = 0; filterLP = 0; filterHP = 0;
        if ( ( s= strstr(textFileLine, PRESET) ) ) {
            s+= 6;
            if ((numPreset != 0) && (p->presetNumber == numPreset)) break;  // too much preset and we are done
            int preset = strtol(s, &err, 10);
            printf("preset %d\n",preset);
            increment++;
            if ((numPreset == 0)&&(increment > numberOfPresets)) break; // too much preset and we are done
            if ((numPreset == 0)&&(increment > 1)) p++;
            if ((numPreset == 0)||(numPreset == preset))
                 dspPresetReset(p, preset);
            ch = 0;
        } else
            if (p->presetNumber != 0) {

                if ( ( s= strstr(textFileLine, CHECKSUM) ) ) {
                    s+= 8;
                    ch = 0;
                    p->checksum = strtol(s, &err, 10);
                    printf("checksum %ld\n",p->checksum);
                    if (dspPresetChecksumVerify(p) == 0) {
                            printf("checksum FALSE\n\n");
                            check = 0; p->checksum = 0; }
                    if ((numPreset != 0) && (p->presetNumber == numPreset)) break;  // preset requested is found
                    if ((numPreset == 0) && (increment >= numberOfPresets)) break;  // enough preset loaded
                } else
                if ( ( s= strstr(textFileLine, INPUT) ) ) {
                    s+= 5;
                    ch = strtol(s, &err, 10) -1;
                    //printf("input %d\n",ch);
                } else
                if ( ( s= strstr(textFileLine, OUTPUT) ) ) { // output expected to always come after inputs
                    s+= 6;
                    ch = strtol(s, &err, 10) - 1 + DSP_INPUTS;
                    //printf("output %d\n",ch);
               } else
                    if (ch< DSP_IO_TOTAL) {
                        if ( ( s= strstr(textFileLine, MIXER) ) ) {
                            s+= 5;
                            //printf("mixer\n");
                            int i;
                            for (i=0; i < DSP_INPUTS; i++) {
                                p->fb[ch].mixer[i] = strtof(s, &err); s=err;  }
                        } else
                        if ( ( s= strstr(textFileLine, GAIN) ) ) {
                            s+= 4;
                            p->fb[ch].gain = strtof(s, &err);
                            //printf("gain %f\n",p->fb[ch].gain);
                        } else
                        if ( ( s= strstr(textFileLine, MUTED) ) ) {
                            p->fb[ch].mute = 1;
                        } else
                        if ( ( s= strstr(textFileLine, INVERTED) ) ) {
                            p->fb[ch].invert = 1;
                        } else
                        if ( ( s= strstr(textFileLine, DELAY) ) ) {
                            s+= 5;
                            p->fb[ch].delayMicroSec = strtof(s, &err);
                            //printf("delay %f\n",p->fb[ch].delayMicroSec);
                        }
                   } // ch< DSP_IO_TOTAL
            }
    } // while
    fclose(dspInputFile);
    }

    return check;
}


static long miniParseSimpleValue(char * function, long *x, long*y, float *val){
    char * s1;
    char * s2;
    char * s3;

    if ((s1 = strstr(textFileLine, function))){
        int len = strlen(function);
        s1 += len;
        *x = strtol(s1, &s2, 10);   // get first value
        s2++;   // skip the "_" underscore caracter
        *y = strtol(s2, &s3, 10);   // get second one
        // read the next line, expected to be <dec>
        if (fgets(textFileLine, sizeof(textFileLine)-1, dspInputFile)){
            if ((s1 = strstr(textFileLine, "<dec>"))) {
                s1 += 5; // skip <dec>
                *val = strtof(s1, &s3); }
            return 1;
        }
    }
    return 0;
}

const char * miniFilterNames[] = {
   "PK", "APF", "SH", "SL",
   "BWLPF_1", "BWLPF_2", "BWLPF_3", "BWLPF_4", "BWLPF_5", "BWLPF_6", "BWLPF_7", "BWLPF_8",
   "BWHPF_1", "BWHPF_2", "BWHPF_3", "BWHPF_4", "BWHPF_5", "BWHPF_6", "BWHPF_7", "BWHPF_8",
   "LRLPF_2", "LRLPF_4", "LRLPF_8", "LRHPF_2", "LRHPF_4", "LRHPF_8",
   "BSLPF"
};

const enum filterTypes miniFilterMap[] = {
        FPEAK, FAP2, FHS2, FLS2,
        FLP1,LPBU2,LPBU3,LPBU4,FNONE,LPBU6,FNONE,LPBU8,
        FHP1,HPBU2,HPBU3,HPBU4,FNONE,HPBU6,FNONE,HPBU8,
        LPLR2,LPLR4,LPLR8,HPLR2,HPLR4,HPLR8,
        LPBE2
};

static enum filterTypes miniSearchFilter(char *s){
    unsigned int n = sizeof(miniFilterNames)/sizeof(miniFilterNames[0]);
    unsigned int i;
    for (i=0; i<n; i++)
        if (strcmp(s,miniFilterNames[i])==0) return miniFilterMap[i];
    return FNONE;
}

static long miniParseFilter(char * function, long *x, long*y, dspFilter_t* filter){

    char * s1;
    char * s2;
    char * s3;

    if ((s1 = strstr(textFileLine, function))){
        s1 += strlen(function);
        *x = strtol(s1, &s2, 10);
        s2++; // skip "_"
        *y = strtol(s2, &s3, 10);
        *filter = dspFilterNone;
        while (fgets(textFileLine, sizeof(textFileLine)-1, dspInputFile)) {
            if ((s1 = strstr(textFileLine, "<freq>"))) {
                s1 += 6;
                filter->freq = strtof(s1, &s3);
                continue; }
            if ((s1 = strstr(textFileLine, "<q>" ))) {
                s1 += 3;
                filter->Q = strtof(s1, &s3);
                continue; }
            if ((s1 = strstr(textFileLine, "<boost>" ))) {
                s1 += 7;
                float gain = strtof(s1, &s3); // value is in dB
                gain = pow(10.0, gain/20.0);
                filter->gain = gain;
                continue; }
            if ((s1 = strstr(textFileLine, "<type>" ))) {
                s1 += 6;
                s2 = strstr(s1,"</type>");
                *s2 = (char)0;
                filter->ftype = miniSearchFilter(s1);
                continue; }
            if ((s1 = strstr(textFileLine, "<bypass>" ))) {
                s1 += 8;
                filter->bypass = strtol(s1, &s3, 10);
                continue;}
            if ((s1 = strstr(textFileLine, "</filter>" ))) {
                if ((filter->ftype == FPEAK) && (filter->gain == 1.0) ) filter->ftype = FNONE;
                if (filter->ftype == FNONE) *filter = dspFilterNone;
                return 1; }
        }
    }
    return 0;
}


static long miniParseLine(dspPreset_t * p){
    char * dgain        = "<item name=\"DGain_";
    char * status       = "_status";
    char * mixer        = "<item name=\"MixerNxMSmoothed1_";
    char * delay        = "<item name=\"Delay_";
    char * polarity_in  = "<item name=\"polarity_in_1_";
    char * polarity_out = "<item name=\"polarity_out_1_";
    char * PEQ          = "<filter name=\"PEQ_";
    char * BPF          = "<filter name=\"BPF_";

    long x; long y; float val;
    dspFilter_t filter;

    if (strstr(textFileLine, status)) { //
        if (miniParseSimpleValue(dgain, &x, &y, &val)){ // DGain_1_0_status : x = 1..12, y=0
            if (x <= DSP_INPUTS)  p->fb[x-1].mute = (val == 1.0) ? 1 : 0;
            else
                if (x>=5) {
                    x -=5;
                    if (x < DSP_OUTPUTS) p->fb[DSP_OUTPUTS + x].mute = (val == 1.0) ? 1 : 0; } // val=1=muted, val=2=ok
        }
        if (miniParseSimpleValue(mixer, &x, &y, &val)){ // MixerNxMSmoothed1_0_1_status : x = input 0..3, y = output 0..7
            if ( (x < DSP_INPUTS) & (y < DSP_OUTPUTS) )
                p->fb[DSP_INPUTS + y].mixer[x] = (val == 1.0) ? 1.0 : 0.0;
            //printf("mixer %2d-%2d = %f\n",x,y,val);
        }
    } else {
        if (miniParseSimpleValue(dgain, &x, &y, &val)){ // DGain_1_0 : x = 1..12
            val = pow(10.0, val/20.0);
            if (x <= DSP_INPUTS) p->fb[x-1].gain = val;
            else if (x>=5) {
                    x -= 5;
                    if (x < DSP_OUTPUTS) p->fb[DSP_OUTPUTS + x].gain = val;  }
            //printf("dgain %2d-%2d = %f\n",x,y,val);
        }
        if (miniParseSimpleValue(mixer, &x, &y, &val)){ // MixerNxMSmoothed1_0_0 : x = input 0..3, y = output 0..7
            val = pow(10.0, val/20.0);
            if ( (x < DSP_INPUTS) & (y < DSP_OUTPUTS) )
                p->fb[DSP_INPUTS + y].mixer[x] *= val;
            //printf("mixer %2d-%2d = %f\n",x,y,val);
        }
        if (miniParseSimpleValue(delay, &x, &y, &val)){ // Delay_5_0 : x=5..12
            if (x>=5) {
                x -= 5;
                if ( x < DSP_OUTPUTS ) p->fb[DSP_OUTPUTS + x].delayMicroSec = val*10.0;}
            //printf("delay %2d-%2d = %f\n",x,y,val);
        }
        if (miniParseSimpleValue(polarity_in, &x, &y, &val)){ // polarity_in_1_0 : x = 0..3
            if ( x < DSP_INPUTS ) p->fb[x].invert = val;
            //printf("polarity %2d-%2d = %f\n",x,y,val);
        }
        if (miniParseSimpleValue(polarity_out, &x, &y, &val)){ // polarity_out_1_4 : x = 4..11
            if (x >= 4) {
                x -= 4;
                if (x < DSP_OUTPUTS) p->fb[DSP_OUTPUTS + x].invert = val; }
            //printf("polarity %2d-%2d = %f\n",x,y,val);
        }
        // x=1..12, y=1..10
        if (miniParseFilter(PEQ, &x, &y, &filter)) { // PEQ_1_1 : x=1..12, y=1..10
            if ((x <= DSP_INPUTS) && (y <= (filterBankSize[x-1])))
                    p->fb[x-1].filter[y-1] = filter;    // start at 3rd filter bin, to leave space for crossover
            else if (x>=5) {
                x -= 5;
                if (( x < DSP_OUTPUTS ) && (y <= (filterBankSize[DSP_OUTPUTS + x])))
                    p->fb[DSP_OUTPUTS+x].filter[y-1] = filter; }
            //printf("filter %2d-%2d f=%5.0f, Q=%8f, g=%5f, byp=%d, type=%s\n",x,y,filter.freq, filter.Q, filter.boost, filter.bypass, miniFilterNames[filter.type]);
        }
        if (miniParseFilter(BPF,&x,&y, &filter) ) { // x=1..12, y=1 or 5
            if (dspFilterIsLP(filter.ftype)) {
                if (filterLPAddr[x-1])
                    p->fb[x-1].filterLP[0] = filter;
                else {
                    int i;
                    for (i=p->fb[x-1].numberOfFilters-1;i>0;i--)
                        p->fb[x-1].filter[i] = p->fb[x-1].filter[i-1]; // shift all filters to right to instert low pass
                    p->fb[x-1].filter[0] = filter;
                }
            }
            if (dspFilterIsHP(filter.ftype)) {
                if (filterHPAddr[x-1])
                    p->fb[x-1].filterHP[0] = filter;
                else {
                    int i;
                    for (i=p->fb[x-1].numberOfFilters-1;i>0;i--)
                        p->fb[x-1].filter[i] = p->fb[x-1].filter[i-1]; // shift all filters to right to instert High pass
                    p->fb[x-1].filter[0] = filter;
                }
                //printf("filter %2d-%2d f=%5.0f, Q=%8f, g=%5f, byp=%d, type=%s\n",x,y,filter.freq, filter.Q, filter.boost, filter.bypass, miniFilterNames[filter.type]);
            }
        }
    }//else status

return 0;
}

long miniParseFile(dspPreset_t * p, long preset, char * filename){
    long check = 0;
    char * xmlfirstline = "<setting version=";
    dspPresetReset(p, 0);
    if (dspOpenInputFile(filename)) {
        if (fgets(textFileLine, sizeof(textFileLine)-1, dspInputFile))
            if (strstr( textFileLine, xmlfirstline)) {
                check = 1;
                while (fgets(textFileLine, sizeof(textFileLine)-1, dspInputFile))
                    if (miniParseLine(p)) { check = 0; break; }
                if (check) {
                    dspPresetChecksumUpdate(p);
                    p->presetNumber = preset;}
            }
        fclose(dspInputFile);
    }
    return check;
}
#endif

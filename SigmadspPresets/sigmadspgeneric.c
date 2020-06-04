/*
 * sigmadspgeneric.c
 *
 *  Created on: 14 may 2020
 *      Author: fabriceo
 *
 */

#include "sigmadspgeneric.h" // this also includes the generic_PARAM.h file from sigmastudio
#ifdef DSP_GENERIC_OK

const long mixerInAddr  = DSP_MIXER_IN_ADDR;
const long mixerOutAddr = DSP_MIXER_OUT_ADDR;
const long gainInAddr   = DSP_GAIN_IN_ADDR;
const long gainOutAddr  = DSP_GAIN_OUT_ADDR;
const long delayOutAddr = DSP_DELAY_OUT_ADDR;
#ifdef DSP_DELAY_SUB_ADDR
const long delaySubAddr = DSP_DELAY_SUB_ADDR;
#else
const long delaySubAddr = 0;
#endif

// inventory of the number of generic filter banks with name FILTERX when X is between 1 and 16 max in this version
const long filterBankAddr[16] = {
#ifdef  MOD_BOARD1_FILTER1_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTER1_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTER2_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTER2_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTER3_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTER3_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTER4_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTER4_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTER5_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTER5_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTER6_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTER6_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTER7_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTER7_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTER8_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTER8_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTER9_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTER9_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTER10_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTER10_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTER11_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTER11_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTER12_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTER12_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTER13_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTER13_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTER14_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTER14_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTER15_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTER15_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTER16_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTER16_ALG0_STAGE0_B2_ADDR
#else
        0
#endif
};

const long filterBankSize[16] = {
#ifdef  MOD_BOARD1_FILTER1_COUNT
        MOD_BOARD1_FILTER1_COUNT / 5,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTER2_COUNT
        MOD_BOARD1_FILTER2_COUNT / 5,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTER3_COUNT
        MOD_BOARD1_FILTER3_COUNT / 5,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTER4_COUNT
        MOD_BOARD1_FILTER4_COUNT / 5,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTER5_COUNT
        MOD_BOARD1_FILTER5_COUNT / 5,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTER6_COUNT
        MOD_BOARD1_FILTER6_COUNT / 5,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTER7_COUNT
        MOD_BOARD1_FILTER7_COUNT / 5,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTER8_COUNT
        MOD_BOARD1_FILTER8_COUNT / 5,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTER9_COUNT
        MOD_BOARD1_FILTER9_COUNT / 5,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTER10_COUNT
        MOD_BOARD1_FILTER10_COUNT / 5,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTER11_COUNT
        MOD_BOARD1_FILTER11_COUNT / 5,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTER12_COUNT
        MOD_BOARD1_FILTER12_COUNT / 5,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTER13_COUNT
        MOD_BOARD1_FILTER13_COUNT / 5,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTER14_COUNT
        MOD_BOARD1_FILTER14_COUNT / 5,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTER15_COUNT
        MOD_BOARD1_FILTER15_COUNT / 5,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTER16_COUNT
        MOD_BOARD1_FILTER16_COUNT / 5
#else
        0
#endif
};

const long filterHPAddr[16] = {
#ifdef  MOD_BOARD1_FILTHP1_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTHP1_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTHP2_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTHP2_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTHP3_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTHP3_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTHP4_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTHP4_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTHP5_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTHP5_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTHP6_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTHP6_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTHP7_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTHP7_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTHP8_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTHP8_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTHP9_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTHP9_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTHP10_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTHP10_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTHP11_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTHP11_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTHP12_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTHP12_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTHP13_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTHP13_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTHP14_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTHP14_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTHP15_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTHP15_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTHP16_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTHP16_ALG0_STAGE0_B2_ADDR
#else
        0
#endif
};

const long filterLPAddr[16] = {
#ifdef  MOD_BOARD1_FILTLP1_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTLP1_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTLP2_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTLP2_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTLP3_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTLP3_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTLP4_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTLP4_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTLP5_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTLP5_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTLP6_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTLP6_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTLP7_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTLP7_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTLP8_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTLP8_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTLP9_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTLP9_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTLP10_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTLP10_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTLP11_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTLP11_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTLP12_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTLP12_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTLP13_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTLP13_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTLP14_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTLP14_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTLP15_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTLP15_ALG0_STAGE0_B2_ADDR,
#else
        0,
#endif
#ifdef  MOD_BOARD1_FILTLP16_ALG0_STAGE0_B2_ADDR
        MOD_BOARD1_FILTLP16_ALG0_STAGE0_B2_ADDR
#else
        0
#endif
};

#endif //DSP_GENERIC_OK
/*
 * File:           \\VBOXSVR\VirtualBox_VMs\SigmaStudioProjects\ADAU1467\blink_1467\blink_1467_IC 1\blink_1467_IC_1.h
 *
 * Created:        Thursday, June 04, 2020 11:52:42 AM
 * Description:    blink_1467:IC 1 program data.
 *
 * This software is distributed in the hope that it will be useful,
 * but is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 * CONDITIONS OF ANY KIND, without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * This software may only be used to program products purchased from
 * Analog Devices for incorporation by you into audio products that
 * are intended for resale to audio product end users. This software
 * may not be distributed whole or in any part to third parties.
 *
 * Copyright ©2020 Analog Devices, Inc. All rights reserved.
 */
#ifndef __BLINK_1467_IC_1_H__
#define __BLINK_1467_IC_1_H__

#include "SigmaStudioFW.h"
#include "blink_1467_IC_1_REG.h"

#define DEVICE_ARCHITECTURE_IC_1                  "ADAU1467"
#define DEVICE_ADDR_IC_1                          0x0

/* DSP Ram Data */
#define DM1_DATA_SIZE_IC_1 96
#define DM1_DATA_ADDR_IC_1 24576
ADI_REG_TYPE DM1_DATA_Data_IC_1[DM1_DATA_SIZE_IC_1] = {
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
};

/* DSP Program Data */
#define PROGRAM_SIZE_IC_1 548
#define PROGRAM_ADDR_IC_1 49152
ADI_REG_TYPE Program_Data_IC_1[PROGRAM_SIZE_IC_1] = {
0x00, 0x00, 0x00, 0x02, 
0x0C, 0x00, 0xDC, 0xDC, 
0x0D, 0x00, 0xFF, 0xD2, 
0x0D, 0x00, 0xFF, 0xD0, 
0x0D, 0x00, 0xF4, 0x50, 
0x0D, 0x00, 0xF4, 0x00, 
0xC0, 0x00, 0x23, 0x80, 
0x80, 0x00, 0x00, 0x00, 
0xC0, 0x00, 0x23, 0x00, 
0x80, 0x00, 0x00, 0x00, 
0xC0, 0x00, 0x23, 0xC0, 
0x80, 0x00, 0x00, 0x10, 
0xC0, 0x00, 0x22, 0x00, 
0x80, 0x00, 0x00, 0x00, 
0x08, 0x80, 0xDC, 0xE0, 
0x0C, 0x00, 0xDC, 0xDC, 
0x0A, 0x21, 0x00, 0x12, 
0x08, 0x00, 0x00, 0x10, 
0x01, 0x00, 0x00, 0x14, 
0x06, 0x40, 0x50, 0x10, 
0xC0, 0x00, 0x20, 0x00, 
0x80, 0x00, 0x00, 0x27, 
0x0D, 0x00, 0xFF, 0xC1, 
0xC0, 0x00, 0x20, 0x00, 
0x80, 0x00, 0x00, 0x01, 
0x0D, 0x00, 0xF4, 0x62, 
0xC0, 0x00, 0x20, 0x00, 
0x80, 0x00, 0x00, 0x00, 
0x0D, 0x00, 0xF4, 0x62, 
0xC0, 0x00, 0x20, 0x00, 
0x80, 0x00, 0x00, 0x02, 
0x0D, 0x00, 0xFF, 0xD1, 
0x00, 0x00, 0x00, 0x03, 
0x0D, 0x00, 0xFF, 0xD2, 
0x00, 0x00, 0x00, 0x05, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x02, 0x01, 0x00, 0x22, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x08, 0x9E, 0xDC, 0xE0, 
0x08, 0x9C, 0x00, 0x10, 
0x00, 0x00, 0x00, 0x00, 
0xC0, 0x00, 0x00, 0x00, 
0x82, 0x4F, 0x00, 0x00, 
0x08, 0x8A, 0xDC, 0xE0, 
0x0A, 0x23, 0x00, 0x06, 
0x0A, 0x2B, 0x00, 0x07, 
0x00, 0x88, 0x20, 0x00, 
0x0A, 0xA7, 0x00, 0x05, 
0x00, 0x00, 0x00, 0x22, 
0xC0, 0x00, 0x2D, 0x30, 
0x80, 0x00, 0x50, 0x00, 
0x30, 0x00, 0xB4, 0x6A, 
0x00, 0x88, 0x20, 0x00, 
0xC0, 0x00, 0x28, 0x70, 
0x80, 0x00, 0x60, 0x00, 
0x02, 0x09, 0x00, 0x47, 
0x00, 0x8C, 0x11, 0x91, 
0x00, 0x00, 0x00, 0x24, 
0x00, 0x8C, 0x2A, 0x02, 
0x30, 0x00, 0xBC, 0xE9, 
0x00, 0x84, 0x0D, 0x9C, 
0x00, 0x20, 0x0B, 0x2D, 
0x00, 0x00, 0xC2, 0xF1, 
0x01, 0x00, 0x00, 0x45, 
0x06, 0x00, 0x50, 0x14, 
0x36, 0x40, 0x50, 0x15, 
0x26, 0x40, 0x40, 0x15, 
0x09, 0x2B, 0x00, 0x06, 
0x09, 0x2B, 0x00, 0x07, 
0x00, 0x00, 0x00, 0x00, 
0x0A, 0x23, 0x00, 0x08, 
0x0E, 0x0D, 0x00, 0x14, 
0x00, 0x84, 0x10, 0x0B, 
0x00, 0x86, 0x01, 0x00, 
0x0A, 0x35, 0xDC, 0x30, 
0x00, 0x88, 0x20, 0x03, 
0x00, 0x20, 0x06, 0x25, 
0x00, 0x88, 0x20, 0x00, 
0x00, 0x20, 0x02, 0x01, 
0x0B, 0x23, 0x00, 0x08, 
0x0E, 0x09, 0x00, 0x16, 
0x00, 0x88, 0x10, 0x0A, 
0x0A, 0x21, 0xDC, 0xDC, 
0x00, 0x20, 0x02, 0x05, 
0x00, 0x88, 0x20, 0x02, 
0x00, 0x20, 0x05, 0x02, 
0x05, 0x4C, 0x10, 0x2E, 
0x00, 0x00, 0x00, 0x02, 
0x0C, 0x00, 0xF5, 0xE0, 
0x06, 0x40, 0x10, 0x0E, 
0x00, 0x00, 0x00, 0x03, 
0x0A, 0x23, 0x00, 0x09, 
0x0E, 0x0D, 0x00, 0x18, 
0x00, 0x84, 0x10, 0x0B, 
0x00, 0x86, 0x01, 0x00, 
0x0A, 0x35, 0xDC, 0x30, 
0x00, 0x88, 0x20, 0x03, 
0x00, 0x20, 0x06, 0x25, 
0x00, 0x88, 0x20, 0x00, 
0x00, 0x20, 0x02, 0x01, 
0x0B, 0x23, 0x00, 0x09, 
0x0E, 0x09, 0x00, 0x1A, 
0x00, 0x88, 0x10, 0x0A, 
0x0A, 0x21, 0xDC, 0xDC, 
0x00, 0x20, 0x02, 0x05, 
0x00, 0x88, 0x20, 0x02, 
0x00, 0x20, 0x05, 0x02, 
0x05, 0x4C, 0x10, 0x3E, 
0x05, 0x0C, 0x10, 0x0E, 
0x0B, 0x21, 0x00, 0x1C, 
0x05, 0x4C, 0x10, 0x1E, 
0xC0, 0x00, 0x00, 0x00, 
0x82, 0x0F, 0x00, 0x1D, 
0x05, 0x0C, 0x10, 0x1E, 
0x00, 0x00, 0xD8, 0x40, 
0xC0, 0x00, 0x00, 0x00, 
0x82, 0x1E, 0x00, 0x00, 
0x04, 0x18, 0x88, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x06, 0x00, 0x18, 0x01, 
0x06, 0x40, 0x10, 0x4E, 
0x06, 0x20, 0x90, 0x4E, 
0x0D, 0x82, 0xF5, 0x27, 
0x08, 0x9C, 0x00, 0x10, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x2E, 0x01, 
0x00, 0x00, 0x00, 0x00, 
0x09, 0x9C, 0x00, 0x10, 
0x00, 0x00, 0x00, 0x02, 
0x0C, 0x10, 0xF4, 0x60, 
0x02, 0xC2, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
};

/* DSP Parameter (Coefficient) Data */
#define PARAM_SIZE_IC_1 140
#define PARAM_ADDR_IC_1 0
ADI_REG_TYPE Param_Data_IC_1[PARAM_SIZE_IC_1] = {
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x0C, 
0x00, 0x00, 0x00, 0x0C, 
0x00, 0x00, 0x00, 0x08, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x0D, 0xA7, 
0x01, 0x00, 0x00, 0x00, 
0x00, 0x80, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x01, 0x5E, 
0x01, 0x00, 0x00, 0x00, 
0x00, 0x80, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x02, 
0x00, 0x00, 0x00, 0x03, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
};


/* Register Default - IC 1.SOFT_RESET */
ADI_REG_TYPE R0_SOFT_RESET_IC_1_Default[REG_SOFT_RESET_IC_1_BYTE] = {
0x00, 0x00
};

/* Register Default - IC 1.SOFT_RESET */
ADI_REG_TYPE R1_SOFT_RESET_IC_1_Default[REG_SOFT_RESET_IC_1_BYTE] = {
0x00, 0x01
};

/* Register Default - IC 1.Reset Delay */
#define R2_RESET_DELAY_IC_1_ADDR 0x0
#define R2_RESET_DELAY_IC_1_SIZE 2
ADI_REG_TYPE R2_RESET_DELAY_IC_1_Default[R2_RESET_DELAY_IC_1_SIZE] = {
0x00, 0xFF
};

/* Register Default - IC 1.HIBERNATE */
ADI_REG_TYPE R3_HIBERNATE_IC_1_Default[REG_HIBERNATE_IC_1_BYTE] = {
0x00, 0x00
};

/* Register Default - IC 1.HIBERNATE */
ADI_REG_TYPE R4_HIBERNATE_IC_1_Default[REG_HIBERNATE_IC_1_BYTE] = {
0x00, 0x01
};

/* Register Default - IC 1.Hibernate Delay */
#define R5_HIBERNATE_DELAY_IC_1_ADDR 0x0
#define R5_HIBERNATE_DELAY_IC_1_SIZE 2
ADI_REG_TYPE R5_HIBERNATE_DELAY_IC_1_Default[R5_HIBERNATE_DELAY_IC_1_SIZE] = {
0x00, 0xFF
};

/* Register Default - IC 1.KILL_CORE */
ADI_REG_TYPE R6_KILL_CORE_IC_1_Default[REG_KILL_CORE_IC_1_BYTE] = {
0x00, 0x00
};

/* Register Default - IC 1.KILL_CORE */
ADI_REG_TYPE R7_KILL_CORE_IC_1_Default[REG_KILL_CORE_IC_1_BYTE] = {
0x00, 0x01
};

/* Register Default - IC 1.PLL_ENABLE */
ADI_REG_TYPE R8_PLL_ENABLE_IC_1_Default[REG_PLL_ENABLE_IC_1_BYTE] = {
0x00, 0x00
};

/* Register Default - IC 1.PLL_CTRL1 Register */
ADI_REG_TYPE R9_PLL_CTRL1_IC_1_Default[REG_PLL_CTRL1_IC_1_BYTE] = {
0x00, 0x02
};

/* Register Default - IC 1.PLL_CLK_SRC Register */
ADI_REG_TYPE R10_PLL_CLK_SRC_IC_1_Default[REG_PLL_CLK_SRC_IC_1_BYTE] = {
0x00, 0x01
};

/* Register Default - IC 1.MCLK_OUT Register */
ADI_REG_TYPE R11_MCLK_OUT_IC_1_Default[REG_MCLK_OUT_IC_1_BYTE] = {
0x00, 0x01
};

/* Register Default - IC 1.PLL_ENABLE Register */
ADI_REG_TYPE R12_PLL_ENABLE_IC_1_Default[REG_PLL_ENABLE_IC_1_BYTE] = {
0x00, 0x01
};

/* Register Default - IC 1.PLL Lock Delay */
#define R13_PLL_LOCK_DELAY_IC_1_ADDR 0x0
#define R13_PLL_LOCK_DELAY_IC_1_SIZE 2
ADI_REG_TYPE R13_PLL_LOCK_DELAY_IC_1_Default[R13_PLL_LOCK_DELAY_IC_1_SIZE] = {
0x00, 0xFF
};

/* Register Default - IC 1.POWER_ENABLE0 Register */
ADI_REG_TYPE R14_POWER_ENABLE0_IC_1_Default[REG_POWER_ENABLE0_IC_1_BYTE] = {
0x04, 0x00
};

/* Register Default - IC 1.POWER_ENABLE1 Register */
ADI_REG_TYPE R15_POWER_ENABLE1_IC_1_Default[REG_POWER_ENABLE1_IC_1_BYTE] = {
0x00, 0x00
};

/* Register Default - IC 1.MP6_MODE */
ADI_REG_TYPE R16_MP6_MODE_IC_1_Default[REG_MP6_MODE_IC_1_BYTE] = {
0x00, 0x07
};

/* Register Default - IC 1.MP7_MODE */
ADI_REG_TYPE R17_MP7_MODE_IC_1_Default[REG_MP7_MODE_IC_1_BYTE] = {
0x00, 0x07
};

/* Register Default - IC 1.MP6_PIN */
ADI_REG_TYPE R18_MP6_PIN_IC_1_Default[REG_MP6_PIN_IC_1_BYTE] = {
0x00, 0x08
};

/* Register Default - IC 1.MP7_PIN */
ADI_REG_TYPE R19_MP7_PIN_IC_1_Default[REG_MP7_PIN_IC_1_BYTE] = {
0x00, 0x08
};

/* Register Default - IC 1.SOUT_SOURCE0 */
ADI_REG_TYPE R20_SOUT_SOURCE0_IC_1_Default[REG_SOUT_SOURCE0_IC_1_BYTE] = {
0x00, 0x02
};

/* Register Default - IC 1.SOUT_SOURCE1 */
ADI_REG_TYPE R21_SOUT_SOURCE1_IC_1_Default[REG_SOUT_SOURCE1_IC_1_BYTE] = {
0x00, 0x02
};

/* Register Default - IC 1.SOUT_SOURCE2 */
ADI_REG_TYPE R22_SOUT_SOURCE2_IC_1_Default[REG_SOUT_SOURCE2_IC_1_BYTE] = {
0x00, 0x02
};

/* Register Default - IC 1.SOUT_SOURCE3 */
ADI_REG_TYPE R23_SOUT_SOURCE3_IC_1_Default[REG_SOUT_SOURCE3_IC_1_BYTE] = {
0x00, 0x02
};

/* Register Default - IC 1.SOUT_SOURCE4 */
ADI_REG_TYPE R24_SOUT_SOURCE4_IC_1_Default[REG_SOUT_SOURCE4_IC_1_BYTE] = {
0x00, 0x02
};

/* Register Default - IC 1.SOUT_SOURCE5 */
ADI_REG_TYPE R25_SOUT_SOURCE5_IC_1_Default[REG_SOUT_SOURCE5_IC_1_BYTE] = {
0x00, 0x02
};

/* Register Default - IC 1.SOUT_SOURCE6 */
ADI_REG_TYPE R26_SOUT_SOURCE6_IC_1_Default[REG_SOUT_SOURCE6_IC_1_BYTE] = {
0x00, 0x02
};

/* Register Default - IC 1.SOUT_SOURCE7 */
ADI_REG_TYPE R27_SOUT_SOURCE7_IC_1_Default[REG_SOUT_SOURCE7_IC_1_BYTE] = {
0x00, 0x02
};

/* Register Default - IC 1.SOUT_SOURCE8 */
ADI_REG_TYPE R28_SOUT_SOURCE8_IC_1_Default[REG_SOUT_SOURCE8_IC_1_BYTE] = {
0x00, 0x02
};

/* Register Default - IC 1.SOUT_SOURCE9 */
ADI_REG_TYPE R29_SOUT_SOURCE9_IC_1_Default[REG_SOUT_SOURCE9_IC_1_BYTE] = {
0x00, 0x02
};

/* Register Default - IC 1.SOUT_SOURCE10 */
ADI_REG_TYPE R30_SOUT_SOURCE10_IC_1_Default[REG_SOUT_SOURCE10_IC_1_BYTE] = {
0x00, 0x02
};

/* Register Default - IC 1.SOUT_SOURCE11 */
ADI_REG_TYPE R31_SOUT_SOURCE11_IC_1_Default[REG_SOUT_SOURCE11_IC_1_BYTE] = {
0x00, 0x02
};

/* Register Default - IC 1.SOUT_SOURCE12 */
ADI_REG_TYPE R32_SOUT_SOURCE12_IC_1_Default[REG_SOUT_SOURCE12_IC_1_BYTE] = {
0x00, 0x02
};

/* Register Default - IC 1.SOUT_SOURCE13 */
ADI_REG_TYPE R33_SOUT_SOURCE13_IC_1_Default[REG_SOUT_SOURCE13_IC_1_BYTE] = {
0x00, 0x02
};

/* Register Default - IC 1.SOUT_SOURCE14 */
ADI_REG_TYPE R34_SOUT_SOURCE14_IC_1_Default[REG_SOUT_SOURCE14_IC_1_BYTE] = {
0x00, 0x02
};

/* Register Default - IC 1.SOUT_SOURCE15 */
ADI_REG_TYPE R35_SOUT_SOURCE15_IC_1_Default[REG_SOUT_SOURCE15_IC_1_BYTE] = {
0x00, 0x02
};

/* Register Default - IC 1.SOUT_SOURCE16 */
ADI_REG_TYPE R36_SOUT_SOURCE16_IC_1_Default[REG_SOUT_SOURCE16_IC_1_BYTE] = {
0x00, 0x02
};

/* Register Default - IC 1.SOUT_SOURCE17 */
ADI_REG_TYPE R37_SOUT_SOURCE17_IC_1_Default[REG_SOUT_SOURCE17_IC_1_BYTE] = {
0x00, 0x02
};

/* Register Default - IC 1.SOUT_SOURCE18 */
ADI_REG_TYPE R38_SOUT_SOURCE18_IC_1_Default[REG_SOUT_SOURCE18_IC_1_BYTE] = {
0x00, 0x02
};

/* Register Default - IC 1.SOUT_SOURCE19 */
ADI_REG_TYPE R39_SOUT_SOURCE19_IC_1_Default[REG_SOUT_SOURCE19_IC_1_BYTE] = {
0x00, 0x02
};

/* Register Default - IC 1.SOUT_SOURCE20 */
ADI_REG_TYPE R40_SOUT_SOURCE20_IC_1_Default[REG_SOUT_SOURCE20_IC_1_BYTE] = {
0x00, 0x02
};

/* Register Default - IC 1.SOUT_SOURCE21 */
ADI_REG_TYPE R41_SOUT_SOURCE21_IC_1_Default[REG_SOUT_SOURCE21_IC_1_BYTE] = {
0x00, 0x02
};

/* Register Default - IC 1.SOUT_SOURCE22 */
ADI_REG_TYPE R42_SOUT_SOURCE22_IC_1_Default[REG_SOUT_SOURCE22_IC_1_BYTE] = {
0x00, 0x02
};

/* Register Default - IC 1.SOUT_SOURCE23 */
ADI_REG_TYPE R43_SOUT_SOURCE23_IC_1_Default[REG_SOUT_SOURCE23_IC_1_BYTE] = {
0x00, 0x02
};

/* Register Default - IC 1.SERIAL_BYTE_0_1 */
ADI_REG_TYPE R44_SERIAL_BYTE_0_1_IC_1_Default[REG_SERIAL_BYTE_0_1_IC_1_BYTE] = {
0x00, 0x22
};

/* Register Default - IC 1.SERIAL_BYTE_1_0 */
ADI_REG_TYPE R45_SERIAL_BYTE_1_0_IC_1_Default[REG_SERIAL_BYTE_1_0_IC_1_BYTE] = {
0x24, 0x00
};

/* Register Default - IC 1.SERIAL_BYTE_1_1 */
ADI_REG_TYPE R46_SERIAL_BYTE_1_1_IC_1_Default[REG_SERIAL_BYTE_1_1_IC_1_BYTE] = {
0x00, 0x22
};

/* Register Default - IC 1.SERIAL_BYTE_2_0 */
ADI_REG_TYPE R47_SERIAL_BYTE_2_0_IC_1_Default[REG_SERIAL_BYTE_2_0_IC_1_BYTE] = {
0x48, 0x00
};

/* Register Default - IC 1.SERIAL_BYTE_2_1 */
ADI_REG_TYPE R48_SERIAL_BYTE_2_1_IC_1_Default[REG_SERIAL_BYTE_2_1_IC_1_BYTE] = {
0x00, 0x22
};

/* Register Default - IC 1.SERIAL_BYTE_3_0 */
ADI_REG_TYPE R49_SERIAL_BYTE_3_0_IC_1_Default[REG_SERIAL_BYTE_3_0_IC_1_BYTE] = {
0x6C, 0x00
};

/* Register Default - IC 1.SERIAL_BYTE_3_1 */
ADI_REG_TYPE R50_SERIAL_BYTE_3_1_IC_1_Default[REG_SERIAL_BYTE_3_1_IC_1_BYTE] = {
0x00, 0x22
};

/* Register Default - IC 1.SERIAL_BYTE_4_1 */
ADI_REG_TYPE R51_SERIAL_BYTE_4_1_IC_1_Default[REG_SERIAL_BYTE_4_1_IC_1_BYTE] = {
0x00, 0x22
};

/* Register Default - IC 1.SERIAL_BYTE_5_0 */
ADI_REG_TYPE R52_SERIAL_BYTE_5_0_IC_1_Default[REG_SERIAL_BYTE_5_0_IC_1_BYTE] = {
0x24, 0x00
};

/* Register Default - IC 1.SERIAL_BYTE_5_1 */
ADI_REG_TYPE R53_SERIAL_BYTE_5_1_IC_1_Default[REG_SERIAL_BYTE_5_1_IC_1_BYTE] = {
0x00, 0x22
};

/* Register Default - IC 1.SERIAL_BYTE_6_0 */
ADI_REG_TYPE R54_SERIAL_BYTE_6_0_IC_1_Default[REG_SERIAL_BYTE_6_0_IC_1_BYTE] = {
0x48, 0x00
};

/* Register Default - IC 1.SERIAL_BYTE_6_1 */
ADI_REG_TYPE R55_SERIAL_BYTE_6_1_IC_1_Default[REG_SERIAL_BYTE_6_1_IC_1_BYTE] = {
0x00, 0x22
};

/* Register Default - IC 1.SERIAL_BYTE_7_0 */
ADI_REG_TYPE R56_SERIAL_BYTE_7_0_IC_1_Default[REG_SERIAL_BYTE_7_0_IC_1_BYTE] = {
0x6C, 0x00
};

/* Register Default - IC 1.SERIAL_BYTE_7_1 */
ADI_REG_TYPE R57_SERIAL_BYTE_7_1_IC_1_Default[REG_SERIAL_BYTE_7_1_IC_1_BYTE] = {
0x00, 0x22
};

/* Register Default - IC 1.MP0_MODE1 */
ADI_REG_TYPE R58_MP0_MODE1_IC_1_Default[REG_MP0_MODE1_IC_1_BYTE] = {
0x00, 0x01
};

/* Register Default - IC 1.MP1_MODE1 */
ADI_REG_TYPE R59_MP1_MODE1_IC_1_Default[REG_MP1_MODE1_IC_1_BYTE] = {
0x00, 0x01
};

/* Register Default - IC 1.SECONDARY_I2C */
ADI_REG_TYPE R60_SECONDARY_I2C_IC_1_Default[REG_SECONDARY_I2C_IC_1_BYTE] = {
0x00, 0x01
};

/* Register Default - IC 1.MP14_PIN */
ADI_REG_TYPE R61_MP14_PIN_IC_1_Default[REG_MP14_PIN_IC_1_BYTE] = {
0x00, 0x08
};

/* Register Default - IC 1.MP15_PIN */
ADI_REG_TYPE R62_MP15_PIN_IC_1_Default[REG_MP15_PIN_IC_1_BYTE] = {
0x00, 0x08
};

/* Register Default - IC 1.KILL_CORE */
ADI_REG_TYPE R66_KILL_CORE_IC_1_Default[REG_KILL_CORE_IC_1_BYTE] = {
0x00, 0x00
};

/* Register Default - IC 1.START_ADDRESS */
ADI_REG_TYPE R67_START_ADDRESS_IC_1_Default[REG_START_ADDRESS_IC_1_BYTE] = {
0x00, 0x00
};

/* Register Default - IC 1.START_PULSE */
ADI_REG_TYPE R68_START_PULSE_IC_1_Default[REG_START_PULSE_IC_1_BYTE] = {
0x00, 0x02
};

/* Register Default - IC 1.START_CORE */
ADI_REG_TYPE R69_START_CORE_IC_1_Default[REG_START_CORE_IC_1_BYTE] = {
0x00, 0x00
};

/* Register Default - IC 1.START_CORE */
ADI_REG_TYPE R70_START_CORE_IC_1_Default[REG_START_CORE_IC_1_BYTE] = {
0x00, 0x01
};

/* Register Default - IC 1.Start Delay */
#define R71_START_DELAY_IC_1_ADDR 0x0
#define R71_START_DELAY_IC_1_SIZE 2
ADI_REG_TYPE R71_START_DELAY_IC_1_Default[R71_START_DELAY_IC_1_SIZE] = {
0x00, 0x01
};

/* Register Default - IC 1.HIBERNATE */
ADI_REG_TYPE R72_HIBERNATE_IC_1_Default[REG_HIBERNATE_IC_1_BYTE] = {
0x00, 0x00
};


/*
 * Default Download
 */
#define DEFAULT_DOWNLOAD_SIZE_IC_1 73

void default_download_IC_1() {
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOFT_RESET_IC_1_ADDR, REG_SOFT_RESET_IC_1_BYTE, R0_SOFT_RESET_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOFT_RESET_IC_1_ADDR, REG_SOFT_RESET_IC_1_BYTE, R1_SOFT_RESET_IC_1_Default );
	SIGMA_WRITE_DELAY( DEVICE_ADDR_IC_1, R2_RESET_DELAY_IC_1_SIZE, R2_RESET_DELAY_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_HIBERNATE_IC_1_ADDR, REG_HIBERNATE_IC_1_BYTE, R3_HIBERNATE_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_HIBERNATE_IC_1_ADDR, REG_HIBERNATE_IC_1_BYTE, R4_HIBERNATE_IC_1_Default );
	SIGMA_WRITE_DELAY( DEVICE_ADDR_IC_1, R5_HIBERNATE_DELAY_IC_1_SIZE, R5_HIBERNATE_DELAY_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_KILL_CORE_IC_1_ADDR, REG_KILL_CORE_IC_1_BYTE, R6_KILL_CORE_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_KILL_CORE_IC_1_ADDR, REG_KILL_CORE_IC_1_BYTE, R7_KILL_CORE_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PLL_ENABLE_IC_1_ADDR, REG_PLL_ENABLE_IC_1_BYTE, R8_PLL_ENABLE_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PLL_CTRL1_IC_1_ADDR, REG_PLL_CTRL1_IC_1_BYTE, R9_PLL_CTRL1_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PLL_CLK_SRC_IC_1_ADDR, REG_PLL_CLK_SRC_IC_1_BYTE, R10_PLL_CLK_SRC_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_MCLK_OUT_IC_1_ADDR, REG_MCLK_OUT_IC_1_BYTE, R11_MCLK_OUT_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PLL_ENABLE_IC_1_ADDR, REG_PLL_ENABLE_IC_1_BYTE, R12_PLL_ENABLE_IC_1_Default );
	SIGMA_WRITE_DELAY( DEVICE_ADDR_IC_1, R13_PLL_LOCK_DELAY_IC_1_SIZE, R13_PLL_LOCK_DELAY_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_POWER_ENABLE0_IC_1_ADDR, REG_POWER_ENABLE0_IC_1_BYTE, R14_POWER_ENABLE0_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_POWER_ENABLE1_IC_1_ADDR, REG_POWER_ENABLE1_IC_1_BYTE, R15_POWER_ENABLE1_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_MP6_MODE_IC_1_ADDR, REG_MP6_MODE_IC_1_BYTE, R16_MP6_MODE_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_MP7_MODE_IC_1_ADDR, REG_MP7_MODE_IC_1_BYTE, R17_MP7_MODE_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_MP6_PIN_IC_1_ADDR, REG_MP6_PIN_IC_1_BYTE, R18_MP6_PIN_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_MP7_PIN_IC_1_ADDR, REG_MP7_PIN_IC_1_BYTE, R19_MP7_PIN_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE0_IC_1_ADDR, REG_SOUT_SOURCE0_IC_1_BYTE, R20_SOUT_SOURCE0_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE1_IC_1_ADDR, REG_SOUT_SOURCE1_IC_1_BYTE, R21_SOUT_SOURCE1_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE2_IC_1_ADDR, REG_SOUT_SOURCE2_IC_1_BYTE, R22_SOUT_SOURCE2_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE3_IC_1_ADDR, REG_SOUT_SOURCE3_IC_1_BYTE, R23_SOUT_SOURCE3_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE4_IC_1_ADDR, REG_SOUT_SOURCE4_IC_1_BYTE, R24_SOUT_SOURCE4_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE5_IC_1_ADDR, REG_SOUT_SOURCE5_IC_1_BYTE, R25_SOUT_SOURCE5_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE6_IC_1_ADDR, REG_SOUT_SOURCE6_IC_1_BYTE, R26_SOUT_SOURCE6_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE7_IC_1_ADDR, REG_SOUT_SOURCE7_IC_1_BYTE, R27_SOUT_SOURCE7_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE8_IC_1_ADDR, REG_SOUT_SOURCE8_IC_1_BYTE, R28_SOUT_SOURCE8_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE9_IC_1_ADDR, REG_SOUT_SOURCE9_IC_1_BYTE, R29_SOUT_SOURCE9_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE10_IC_1_ADDR, REG_SOUT_SOURCE10_IC_1_BYTE, R30_SOUT_SOURCE10_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE11_IC_1_ADDR, REG_SOUT_SOURCE11_IC_1_BYTE, R31_SOUT_SOURCE11_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE12_IC_1_ADDR, REG_SOUT_SOURCE12_IC_1_BYTE, R32_SOUT_SOURCE12_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE13_IC_1_ADDR, REG_SOUT_SOURCE13_IC_1_BYTE, R33_SOUT_SOURCE13_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE14_IC_1_ADDR, REG_SOUT_SOURCE14_IC_1_BYTE, R34_SOUT_SOURCE14_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE15_IC_1_ADDR, REG_SOUT_SOURCE15_IC_1_BYTE, R35_SOUT_SOURCE15_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE16_IC_1_ADDR, REG_SOUT_SOURCE16_IC_1_BYTE, R36_SOUT_SOURCE16_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE17_IC_1_ADDR, REG_SOUT_SOURCE17_IC_1_BYTE, R37_SOUT_SOURCE17_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE18_IC_1_ADDR, REG_SOUT_SOURCE18_IC_1_BYTE, R38_SOUT_SOURCE18_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE19_IC_1_ADDR, REG_SOUT_SOURCE19_IC_1_BYTE, R39_SOUT_SOURCE19_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE20_IC_1_ADDR, REG_SOUT_SOURCE20_IC_1_BYTE, R40_SOUT_SOURCE20_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE21_IC_1_ADDR, REG_SOUT_SOURCE21_IC_1_BYTE, R41_SOUT_SOURCE21_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE22_IC_1_ADDR, REG_SOUT_SOURCE22_IC_1_BYTE, R42_SOUT_SOURCE22_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE23_IC_1_ADDR, REG_SOUT_SOURCE23_IC_1_BYTE, R43_SOUT_SOURCE23_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SERIAL_BYTE_0_1_IC_1_ADDR, REG_SERIAL_BYTE_0_1_IC_1_BYTE, R44_SERIAL_BYTE_0_1_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SERIAL_BYTE_1_0_IC_1_ADDR, REG_SERIAL_BYTE_1_0_IC_1_BYTE, R45_SERIAL_BYTE_1_0_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SERIAL_BYTE_1_1_IC_1_ADDR, REG_SERIAL_BYTE_1_1_IC_1_BYTE, R46_SERIAL_BYTE_1_1_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SERIAL_BYTE_2_0_IC_1_ADDR, REG_SERIAL_BYTE_2_0_IC_1_BYTE, R47_SERIAL_BYTE_2_0_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SERIAL_BYTE_2_1_IC_1_ADDR, REG_SERIAL_BYTE_2_1_IC_1_BYTE, R48_SERIAL_BYTE_2_1_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SERIAL_BYTE_3_0_IC_1_ADDR, REG_SERIAL_BYTE_3_0_IC_1_BYTE, R49_SERIAL_BYTE_3_0_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SERIAL_BYTE_3_1_IC_1_ADDR, REG_SERIAL_BYTE_3_1_IC_1_BYTE, R50_SERIAL_BYTE_3_1_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SERIAL_BYTE_4_1_IC_1_ADDR, REG_SERIAL_BYTE_4_1_IC_1_BYTE, R51_SERIAL_BYTE_4_1_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SERIAL_BYTE_5_0_IC_1_ADDR, REG_SERIAL_BYTE_5_0_IC_1_BYTE, R52_SERIAL_BYTE_5_0_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SERIAL_BYTE_5_1_IC_1_ADDR, REG_SERIAL_BYTE_5_1_IC_1_BYTE, R53_SERIAL_BYTE_5_1_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SERIAL_BYTE_6_0_IC_1_ADDR, REG_SERIAL_BYTE_6_0_IC_1_BYTE, R54_SERIAL_BYTE_6_0_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SERIAL_BYTE_6_1_IC_1_ADDR, REG_SERIAL_BYTE_6_1_IC_1_BYTE, R55_SERIAL_BYTE_6_1_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SERIAL_BYTE_7_0_IC_1_ADDR, REG_SERIAL_BYTE_7_0_IC_1_BYTE, R56_SERIAL_BYTE_7_0_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SERIAL_BYTE_7_1_IC_1_ADDR, REG_SERIAL_BYTE_7_1_IC_1_BYTE, R57_SERIAL_BYTE_7_1_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_MP0_MODE1_IC_1_ADDR, REG_MP0_MODE1_IC_1_BYTE, R58_MP0_MODE1_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_MP1_MODE1_IC_1_ADDR, REG_MP1_MODE1_IC_1_BYTE, R59_MP1_MODE1_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SECONDARY_I2C_IC_1_ADDR, REG_SECONDARY_I2C_IC_1_BYTE, R60_SECONDARY_I2C_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_MP14_PIN_IC_1_ADDR, REG_MP14_PIN_IC_1_BYTE, R61_MP14_PIN_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_MP15_PIN_IC_1_ADDR, REG_MP15_PIN_IC_1_BYTE, R62_MP15_PIN_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, PROGRAM_ADDR_IC_1, PROGRAM_SIZE_IC_1, Program_Data_IC_1 );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, PARAM_ADDR_IC_1, PARAM_SIZE_IC_1, Param_Data_IC_1 );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, DM1_DATA_ADDR_IC_1, DM1_DATA_SIZE_IC_1, DM1_DATA_Data_IC_1 );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_KILL_CORE_IC_1_ADDR, REG_KILL_CORE_IC_1_BYTE, R66_KILL_CORE_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_START_ADDRESS_IC_1_ADDR, REG_START_ADDRESS_IC_1_BYTE, R67_START_ADDRESS_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_START_PULSE_IC_1_ADDR, REG_START_PULSE_IC_1_BYTE, R68_START_PULSE_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_START_CORE_IC_1_ADDR, REG_START_CORE_IC_1_BYTE, R69_START_CORE_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_START_CORE_IC_1_ADDR, REG_START_CORE_IC_1_BYTE, R70_START_CORE_IC_1_Default );
	SIGMA_WRITE_DELAY( DEVICE_ADDR_IC_1, R71_START_DELAY_IC_1_SIZE, R71_START_DELAY_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_HIBERNATE_IC_1_ADDR, REG_HIBERNATE_IC_1_BYTE, R72_HIBERNATE_IC_1_Default );
}

#endif

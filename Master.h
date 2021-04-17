/* 
 * File:        Master.h
 * Author:      MBB
 * Comments:    System master include file
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef Master_H
#define	Master_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include <stdbool.h>

#define _XTAL_FREQ  8000000
#define S_Clock     8000000
#define I_Clock     2000000
// Timer 0 (Time-of-Day)
#define T0_Period   1

typedef union EchoPeriod_tag
{
   struct
   {
      uint8_t EPl;
      uint8_t EPh;
   };
   struct
   {
      uint16_t EP16;
   };
} EchoPeriod_t;
EchoPeriod_t giEchoPeriod;

// Timer 1 (Echo Timer) is in uS
#define T1_Period   0.5f           
#define T1_mm_Per_Tick  .343f    

// Timer 2 (40Khz Oscillator) 
#define T2_Period       25
#define T2_IncRate      1
#define T2_NumPulses    12

// Timer 3 (Sample Timer) Period is in mSeconds
// e.g. 1 sample every 5 ms
#define T3_Prescale     8
#define T3_Period       5
#define T3_Freq         (1000 / T3_Period)
#define T3_SampeRate    3

// Pin Definitions  (Write to latch, read from port)
#define Pin_Echo_Detect PORTCbits.CCP1
#define Pin_Tx_Enable   LATAbits.LATA5
#define Pin_Relay       LATAbits.LATA0
#define Pin_LCD_E       LATAbits.LATA1
#define Pin_LCD_RW      LATAbits.LATA2
#define Pin_LCD_RS      LATAbits.LATA3

// Volume of water calculations
#define TankDiameter_Ft 4
#define TankHeight_Ft   6
#define Gals_per_mm3    0.2872f

float TankDiameter_mm;
float TankVol_per_mm;
float TankGals_per_mm;
float TankHeight_mm;

// DEFINE MODE: Test or Normal
#define Test_Mode
//#Define Normal_Mode

#endif	/* Master_H */


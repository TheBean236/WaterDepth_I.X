/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F45K50
        Driver Version    :  2.00
*/

#include "mcc_generated_files/mcc.h"

#include "Master.h"
#include "CommonRoutines.h"

void InitTankVariables (void);
/*
                         Main application
 */
void SysInit(void);

void main(void)
{
    // Initialize the device
    SysInit();

    InitTankVariables();
    Timer0_Init();      // Initialize and start TOD clock
    Timer1_Init();      // Initialize Timer 1 (Echo Timer)
    Timer2_Init();      // Initialize 40 Khz clock
    Timer3_Init();      // Initialize and Start Sample clock
    CCP1_Init();        // Initialize CCP1 - Echo counter
    CCP2_Init();
    
    INTCONbits.GIE = 1; // Enable Global Interrupts
    INTCONbits.PEIE = 1;  // Enable Peripheral Interrupts

    while (1)
    {
        // Code is entirely interrupt driven. 
    }
}

void ComputeEchoDistance()
{
    float fEchoDistance_mm;
    float fEchoPeriod;
    float fWaterHeight_mm;
    float fWaterVol_Gal;

    fEchoPeriod     = T1_Period * giEchoPeriod.EP16;
    fEchoDistance_mm = T1_mm_Per_Tick * giEchoPeriod.EP16;
    fWaterHeight_mm = TankHeight_mm - fEchoDistance_mm;
    fWaterVol_Gal   = fWaterHeight_mm * TankGals_per_mm;
}

void InitTankVariables (void)
{
    TankDiameter_mm = TankDiameter_Ft * 12 * 25.4f;
    TankVol_per_mm  = 3.14159f * ((TankDiameter_mm * TankDiameter_mm)/4);
    TankGals_per_mm = TankVol_per_mm * Gals_per_mm3;
    TankHeight_mm   = TankHeight_Ft * 12 * 25.4f;
}
/**
 End of File
*/
/*
 * File:   TMR0_Code.c
 * Author: MBend
 *
 * Created on April 10, 2021, 10:40 AM
 */

#include "Master.h"
#include "Timer0.h"

bool bIncDays = false;

void Timer0_ISR(void) {
    TMR0 = Timer0_Reload_Val;       // Reload timer
    INTCONbits.TMR0IF = 0;          // Reset Interrupt Flab
    
    // Increment Seconds
    bIncDays = false;
    do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0);                           
    
    if (++giSecs == 60){
        giSecs = 0;
        if (++giMins == 60) {
            giMins = 0;
            if (++giHours == 24){
                giHours = 0;
                bIncDays = true;
            }
        }
    }
#ifdef Normal_Mode
    if (giSecs/10 * 10 == giSecs)
    {
        StartDepthDetection();
    }
#endif
    
    if (bIncDays)
        giDays++;
    return;
}

void Timer0_Init (void)
{
    TMR0 = Timer0_Reload_Val;
    
    // Clear Interrupt flag before enabling the interrupt
    INTCONbits.TMR0IF = 0;

    // Enabling TMR0 interrupt.
    INTCONbits.TMR0IE = 1;
    
    // T0PS 1:256; T08BIT 16-bit; T0SE Increment_Lo2Hi; T0CS FOSC/4; TMR0ON enabled; PSA assigned; 
    T0CON = 0x97;
}
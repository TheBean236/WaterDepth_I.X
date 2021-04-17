
#include "Master.h"
#include "GlobalRoutines.h"

void CCP2_Init (void)
{
    // Set the PWM2 to the options selected in the User Interface
	
	// CCP2M PWM; DC2B 3; 
	CCP2CON = 0x3C;     
	CCPR2L = 0x18;   // 24 = 25 pulses - 1 = (Pulses/Cycle / 2) - 1  
	CCPR2H = 0x00;   // 0
}

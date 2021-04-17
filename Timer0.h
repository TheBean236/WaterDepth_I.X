/* 
 * File:        Timer0.h
 * Author:      MBB
 * Comments:    Timer0 Globals (TOD Clock)
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef Timer0_H
#define	Timer0_H

#include <xc.h> // include processor files - each processor file is guarded.  

const uint16_t Timer0_Reload_Val = 0xE17B;
static char giSecs   = 0;
static char giMins   = 0;
static char giHours  = 0;
static int giDays   = 0;
static int giMonth  = 0;
static int giYear   = 0;

#endif	/* Timer0_H */


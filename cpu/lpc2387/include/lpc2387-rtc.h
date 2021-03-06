/******************************************************************************
Copyright 2008, Freie Universitaet Berlin (FUB). All rights reserved.

These sources were developed at the Freie Universitaet Berlin, Computer Systems
and Telematics group (http://cst.mi.fu-berlin.de).
-------------------------------------------------------------------------------
This file is part of RIOT.

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.

RIOT is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program.  If not, see http://www.gnu.org/licenses/ .
--------------------------------------------------------------------------------
For further information and questions please use the web site
	http://scatterweb.mi.fu-berlin.de
and the mailinglist (subscription via web site)
	scatterweb@lists.spline.inf.fu-berlin.de
*******************************************************************************/

#ifndef LPC2387_RTC_H
#define LPC2387_RTC_H

/**
 * @defgroup	lpc2387_rtc		LPC2387 Real-Time-Clock
 * @ingroup		lpc2387
 *
 * \section lpc2387_rtc_newlib	Standard library support
 * Currently reading and setting time and date through standard C functions is implemented.
 * Standard C timers are not available.
 *
 * @{
 */

/**
 * @file
 * @brief		LPC2387 Real-Time-Clock
 *
 * @author      Freie Universität Berlin, Computer Systems & Telematics
 * @version     $Revision: 1998 $
 *
 * @note    	$Id: lpc2387-rtc.h 1998 2010-03-16 13:05:41Z baar $
 */

#include <rtc.h>
#include <time.h>
#include <sys/time.h>
#include "lpc2387.h"

/* ------------------------------------------------------------------------- */
/**
 * @name LPC2387 RTC Compile-Time Configuration
 * @{
 */

/** @} */

/**
 * @brief	Mask for RTC alarms
 * @see		::rtc_set_alarm, ::rtc_get_alarm
 */
enum rtc_alarm_mask {
	RTC_AMR_DISABLED = 0,		///< Alarm disables
	RTC_AMR_SEC	=	AMRSEC,  	///< Alarm mask for Seconds
	RTC_AMR_MIN	=	AMRMIN,  	///< Alarm mask for Minutes
	RTC_AMR_HOUR=	AMRHOUR, 	///< Alarm mask for Hours
	RTC_AMR_DOM	=	AMRDOM,  	///< Alarm mask for Day of Month
	RTC_AMR_DOW	=	AMRDOW, 	///< Alarm mask for Day of Week
	RTC_AMR_DOY	=	AMRDOY,  	///< Alarm mask for Day of Year
	RTC_AMR_MON	=	AMRMON,  	///< Alarm mask for Month
	RTC_AMR_YEAR=	AMRYEAR, 	///< Alarm mask for Year
};

void rtc_reset(void);

/**
 * @brief	Returns the time of compilation in seconds
 * @internal
 */
time_t rtc_get_compile_time(void) __attribute__((noinline));

/**
 * @brief	Returns the current clock time
 * @param[out]	time		optional return value
 * @return	clock time in seconds
 */
time_t rtc_time(struct timeval* time);

/**
 * @brief	Sets the current clock time
 * @param[in]	time		new time in seconds
 * @note	Any set alarm is shifted
 */
void rtc_set(time_t time);

/**
 * @brief	Sets the alarm
 * @internal
 * @param[in]	localt	Alarm time
 * @param[in]	mask	Sets the registers to poll for the alarm
 *
 * To disable the alarm set mask to RTC_AMR_DISABLED.
 *
 * @see ::rtc_alarm_mask
 */
void rtc_set_alarm(struct tm* localt, enum rtc_alarm_mask mask);

/**
 * @brief	Gets the current alarm setting
 * @internal
 * @param[out]	localt	Pointer to structure to receive alarm time
 * @return		Alarm mask
 *
 * @see rtc_set_alarm
 * @see ::rtc_alarm_mask
 */
enum rtc_alarm_mask _rtc_get_alarm(struct tm* localt);

/** @} */
#endif /* end __RTC_H */

#pragma once
/*
* File: calendar.h
* -------------------------------------------
* Provides toools for coding calendar program
*/

#ifndef _calendar_h
#define _calendar_h

/* Include files necessary for the headerfile */
//#include <yyy.h>

/*
* Constants
* ---------
* Defines ...
*/
#define SUNDAY 0
#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6
#define STARTYEAR 1900

/*
* Typedefinitions
* ---------
* Description ...
*/

/* Function prototypes */

/************************************************************************************
* <Lägg till bra förklaring>
************************************************************************************/
void printCalendarMonth(int month, int year);

/************************************************************************************
* Gets given months name.
************************************************************************************/
char * monthName(int month);

/************************************************************************************
* <Lägg till bra förklaring>
************************************************************************************/
void indentFirstLine(int weekDay);

/************************************************************************************
* Checks if given year is a leap year
************************************************************************************/
int isLeapYear(int year);

/************************************************************************************
* <Lägg till bra förklaring>
************************************************************************************/
int monthDays(int month, int year);

/************************************************************************************
* Returns first day of the month
************************************************************************************/
int firstDayOfMonth(int month, int year);

#endif
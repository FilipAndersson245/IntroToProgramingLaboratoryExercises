#include "Calendar.h"

/************************************************************************************
************************************************************************************/
void printCalendarMonth(int month, int year)
{
    int weekday, mDays;
    printf("\n\n %s %d\n", monthName(month), year);
    printf(" Sö Må Ti On To Fr Lö\n");
    mDays = monthDays(month, year);
    weekday = firstDayOfMonth(month, year);
    indentFirstLine(weekday);
    for (int day = 1; day <= mDays; day++)
    {
        printf(" %2d", day);
        if (weekday == SATURDAY)
            printf("\n");
        weekday = ++weekday % 7;
    }
    if (weekday == SUNDAY)
        printf("\n");
}

/************************************************************************************
************************************************************************************/
char * monthName(int month)
{
    switch (month)
    {
    case 1: return "Januari"; break;
    case 2: return "Februari"; break;
    case 3: return "Mars"; break;
    case 4: return "April"; break;
    case 5: return "Maj"; break;
    case 6: return "Juni"; break;
    case 7: return "Juli"; break;
    case 8: return "Augusti"; break;
    case 9: return "September"; break;
    case 10: return "Oktober"; break;
    case 11: return "November"; break;
    case 12: return "December"; break;
    default: return "Not a valid month"; //We should never end up here
    }
}

/************************************************************************************
************************************************************************************/
void indentFirstLine(int weekDay)
{
    for (int i = 0; i < weekDay; i++)
        printf("   ");
}

/************************************************************************************
************************************************************************************/
int isLeapYear(int year)
{
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

/************************************************************************************
************************************************************************************/
int monthDays(int month, int year)
{
    switch (month)
    {
    case 2:
        if (isLeapYear(year))
            return 29;
        return 28;
    case 4: case 6: case 9: case 11:
        return 30;
    default:
        return 31;
    }
}

/************************************************************************************
************************************************************************************/
int firstDayOfMonth(int month, int year)
{
    int weekDay = MONDAY;
    for (int i = STARTYEAR; i < year; i++)
    {
        weekDay = (weekDay + 365) % 7;
        if (isLeapYear(i))
            weekDay = (++weekDay) % 7;
    }
    for (int i = 1; i < month; i++)
    {
        weekDay = (weekDay + monthDays(i, year)) % 7;
    }
    return weekDay;
}
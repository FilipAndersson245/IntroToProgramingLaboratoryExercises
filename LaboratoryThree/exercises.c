#include "exercises.h"
#include "Common.h"
#include "Calendar.h"
#include <stdio.h>

#define WEEK 7

int exercise1() {
    int year, month;
    year = getYearFromUser();
    month = getMonthFromUser();
    printCalendarMonth(year, month);
    return 0;
}

//Funktionsdefinitionerint
getYearFromUser(void) {
    int   year = 1;
    do
    {
        printf("\nYear: ");
        scanf_s("%d", &year);
    } while (year < STARTYEAR);
    return year;
}

int getMonthFromUser(void) {
    int   month = 0;
    do
    {
        printf("\nMonth: ");
        scanf_s("%d", &month);
    } while (month > 12 || month < 1);

    return month;
}

int getDayFromUser(int year, int month) {
    int day, numberOfDays = monthDays(month, year);
    do
    {
        printf("\nDay: ");
        scanf_s("%d", &day);
    } while (day > numberOfDays || day < 1);
    return day;
}

char* dayName(int day) {
    switch (day)
    {
    case SUNDAY: return "Sunday"; break;
    case MONDAY: return "Monday"; break;
    case TUESDAY: return "Tuesday"; break;
    case WEDNESDAY: return "Wednsday"; break;
    case THURSDAY: return "Thursday"; break;
    case FRIDAY: return "Friday"; break;
    case SATURDAY: return "Saturday"; break;
    default:
        return "Invalid date";
        break;
    }
}

void exercise2() {
    mainMenu();
}

void mainMenu() {
    int command = 0;
    do
    {
        printf(
            "\n===================================\n"
            "1. Get day for a specific date\n"
            "2. Get day for a specific holyday\n"
            "3. write a monthCalender\n"
            "0. Exit\n"
            "===================================\n");
        scanf_s("%d", &command);
        clrscr();
        switch (command)
        {
        case 1:
            exercise1();
            break;
        case 2:
            subMenu();
            break;
        case 3:
            printCalendarMonth(getMonthFromUser(), getYearFromUser());
            break;
        default:
            break;
        }
    } while (command != 0);
}

int getFirstWeekdayDateBetween(int selectedWeekDay, int start, int end, int year, int month) {
    int theFirstDayOfTheMonth = firstDayOfMonth(month, year);
    for (int i = start; i < end; i++) {
        int weekday = (i + theFirstDayOfTheMonth - 1) % WEEK;
        if (weekday == selectedWeekDay)
            return i;
    }
    return -1;
}

int getLastWeekDayBetween(int selectedWeekDay, int start, int end, int year, int month) {
    int firstDay = getFirstWeekdayDateBetween(selectedWeekDay, start, end, year, month); // Get first occurence of setday
    int numberOfDaysInMonth = monthDays(month, year);
    int day = firstDay;
    while (day <= numberOfDaysInMonth || day <= end) // Iterate until of of ranges(month days or given end)
    {
        if (day + WEEK > numberOfDaysInMonth || day + WEEK > end)
            return day;
        day += WEEK;
    }
}

void printEasterDay(int year) {
    int a = year % 19;
    int b = year % 4;
    int c = year % 7;
    int d = ((19 * a) + 24) % 30;
    int e = ((2 * b) + (4 * c) + (6 * d) + 5) % 7;

    int day;
    int month;
    if (d + e > 9) {
        month = 4;
        day = d + e - 9;
        if (day == 26) {
            day = 19;
        }
        else if (day == 25 && d == 28 && e == 6 && ((11 * 24) + 11) % 30 < 19) {
            day = 18;
        }
    }
    else {
        month = 5;
        day = 22 + d + e;
    }
    printf("\nEaster day occurse: %d/%d", day, month);
}

void PrintPingstday(int year) {
    int a = year % 19;
    int b = year % 4;
    int c = year % 7;
    int d = ((19 * a) + 24) % 30;
    int e = ((2 * b) + (4 * c) + (6 * d) + 5) % 7;

    int day;
    int month;
    if (d + e > 9) {
        month = 4;
        day = d + e - 9;
        if (day == 26) {
            day = 19;
        }
        else if (day == 25 && d == 28 && e == 6 && ((11 * 24) + 11) % 30 < 19) {
            day = 18;
        }
    }
    else {
        month = 5;
        day = 22 + d + e;
    }

    int daysUntilPingstDay = 49;
    while (daysUntilPingstDay > 0)
    {
        day++;
        daysUntilPingstDay--;
        if (day > monthDays(month, year)) {
            month++;
            day = 1;
        }
    }

    printf("\nEaster day occurse: %d/%d", day, month);
}

void subMenu() {
    int command = 0;
    int year = 19000;
    do
    {
        printf(
            "\n===================================\n"
            "1. Christmas day  \n"
            "2. new year's day \n"
            "3. midsummer      \n"
            "ExtraTasks\n"
            "4. mothers day and fathers day\n"
            "5. Easter Sunday\n"
            "6. Pingstdagen\n"
            "0. Back to main menu\n"
            "===================================\n");
        scanf_s("%d", &command);
        clrscr();
        switch (command)
        {
        case 1:
            printf("\nChristmas is on a: %s", dayName((firstDayOfMonth(12, getYearFromUser()) + 24) % WEEK));
            break;
        case 2:
            printf("\nNew year's on a: %s", dayName(firstDayOfMonth(1, getYearFromUser())));
            break;
        case 3:
            printf("\nMidsummer is: %d/%d", getFirstWeekdayDateBetween(SATURDAY, 20, 26, getYearFromUser(), 6), 6);
            break;
        case 4:
            year = getYearFromUser();
            printf("\nMothers day is : %d/%d", getLastWeekDayBetween(SUNDAY, monthDays(year, 5) - 7, monthDays(year, 5), year, 5), 5);
            printf("\nFathers day is : %d/%d", getFirstWeekdayDateBetween(SUNDAY, 1, 8, year, 11) + WEEK, 11);
        case 5:
            printEasterDay(getYearFromUser());
        case 6:
            PrintPingstday(getYearFromUser());
        default:
            break;
        }
    } while (command != 0);
}
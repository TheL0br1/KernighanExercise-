#include <stdio.h>
#include<stdlib.h>
#define MAXLEN 1000

static char daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
/* day_of_year: отримати день року маючи мiсяць i день */
int day_of_year(int year, int month, int day) {
    int i, leap;

    if (month < 1 || month > 12 || day < 1 || day > daytab[0][month])
        return -1;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    for (i = 1; i < month; i++)
        day += daytab[leap][i];

    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;

    if (year < 1 || yearday < 1 || yearday > 365 + (leap ? 1 : 0))
    {
        *pmonth = -1;
        *pday = -1;
        return;
    }

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];

    *pmonth = i;
    *pday = yearday;
}
int main() {



    return 0;
}
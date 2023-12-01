//
// Created by User on 11/30/2023.
//

#ifndef UNTITLED4_GETTOP_H
#define UNTITLED4_GETTOP_H
#define NUMBER '0'
#include <ctype.h>
#include<stdio.h>
#include "getch.h"
int getch(void);
void ungetch(int);
/* getop: отримати наступний знак або числовий операнд */
int getop(char s[])
{
    int sign = 1;
    int i, c;
    while ((s[0] = c = getch()) == ' '  || c == '\t')
        ;
    s[1] = '\0';
    i = 0;
    if (c == '-' && (isdigit(s[++i] = c = getch()))) {
        sign = -1;
    }
    else if (!isdigit(c) && c != '.') {

        return c; /* не є числом */
    }
    if (isdigit(c)) /* зберегти частину, що є цiлим */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* зберегти дробову частину */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#endif //UNTITLED4_GETTOP_H

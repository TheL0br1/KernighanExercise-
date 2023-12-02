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
static int temp = 0;
/* getop: отримати наступний знак або числовий операнд */
int getop(char s[])
{
    if(temp == '\n'){
        temp =0;
        s[0] = '\n';
        s[1] = '\0';
        return '\n';
    }
    int sign = 1;
    int i, c;
    while ((s[0] = c = getch()) == ' '  || c == '\t')
        ;
    if(temp!=0 && temp!=' ' && temp!='\t'){
        s[0]=temp;
    }
    s[1] = '\0';
    i = 0;
    char temp2 = c;
    if ( isdigit(s[++i] = c = getch()) && temp2 == '-' ) {
    }
    else if (!isdigit(temp2) && temp2 != '.') {
        if(c=='\n'){
            temp = c;
        }
        return temp2; /* не є числом */
    }
    if (isdigit(c)) /* зберегти частину, що є цiлим */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* зберегти дробову частину */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        temp = c;
    return NUMBER;
}

#endif //UNTITLED4_GETTOP_H

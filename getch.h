//
// Created by User on 11/30/2023.
//

#ifndef UNTITLED4_GETCH_H
#define UNTITLED4_GETCH_H
#define BUFSIZE 100
#include<stdio.h>
char buf[BUFSIZE]; /* буфер для ungetch */
int bufp = 0; /* наступна вiльна позицiя у buf */
int getch(void) /* отримати (можливо виштовхнутий) знак */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* виштовхнути знак назад у ввiд */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}


#endif //UNTITLED4_GETCH_H

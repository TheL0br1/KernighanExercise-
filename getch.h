//
// Created by User on 11/30/2023.
//

#ifndef UNTITLED4_GETCH_H
#define UNTITLED4_GETCH_H
#define BUFSIZE 100
#include<stdio.h>
#include<string.h>
char buf[BUFSIZE]; /* буфер для ungetch */
int bufp = 0; /* наступна вiльна позицiя у buf */
int getch(void) /* отримати (можливо виштовхнутий) знак */
{
    return (bufp == 1) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* виштовхнути знак назад у ввiд */
{
    if (bufp >= 1)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
void ungets(char s[]){
    for (int i = 0; i < strlen(s); ++i) {
        ungetch(s[i]);
    }
}

#endif //UNTITLED4_GETCH_H

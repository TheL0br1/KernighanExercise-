#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

/* getint: зберiгає наступне введене цiле у *pn */
int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch())) /* опустити пробiли */
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); /* c не є числом */
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
    }

    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }

    *pn *= sign;

    if (c != EOF)
        ungetch(c);
    if(sign == -1 && *pn == 0){
        return 0;
    }
    return c;
}

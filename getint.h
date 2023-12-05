#include <ctype.h>
#include <stdio.h>
#include<math.h>
int getch(void);
void ungetch(int);

/* getfloat: зберiгає наступне введене цiле у *pn */
int getfloat(float *pn)
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
    if(c=='.'){
        c = getch();
        for (int i =1; isdigit(c); c = getch(), i++) {
            *pn += (c - '0')/pow(10,i);
        }
    }
    *pn *= sign;

    if (c != EOF)
        ungetch(c);
    if(sign == -1 && *pn == 0){
        return 0;
    }
    return c;
}

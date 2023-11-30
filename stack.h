//
// Created by User on 11/30/2023.
//
#include<stdio.h>
#ifndef UNTITLED4_STACK_H
#define UNTITLED4_STACK_H
#define MAXVAL 100 /* максимальна глибина стеку */
int sp = 0; /* наступна вiльна позицiя у стеку */
double val[MAXVAL]; /* стек значень */
/* push: проштовхування у стек значень */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can’t push %g\n", f);
}
/* pop: виштовхнути i повернути верхнє значення зi стеку */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
#endif //UNTITLED4_STACK_H

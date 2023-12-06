#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "readlines.h"
#define MAXLINES 5000
int numeric = 0;
int reverse = 0;

char *lineptr[MAXLINES]; /* покажчики на текст рядкiв */
void qsort1(void *lineptr[], int left, int right,
           int (*comp)(const void *, const void *));
int numcmp(char *, char *);
/* сортує рядки вводу */
int main(int argc, char *argv[])
{
    int nlines; /* кiлькiсть прочитаних рядкiв вводу */

    if (argc > 1 )
        if(strcmp(argv[1], "-n") == 0) {
            numeric = 1;
        }
        if(strcmp(argv[1], "-r") == 0) {
            reverse = 1;
        }
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort1((void**) lineptr, 0, nlines-1,
              (int (*)(const void*,const void*))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}

int numcmp(char *s1, char *s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}
void swap(void *v[], int i, int j)
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
void qsort1(void *v[], int left, int right,
           int (*comp)(const void *, const void *))
{
    int i, last;
    void swap(void *v[], int, int);
    if (left >= right) /* не робить нiчого, якщо масив мiстить */
    return; /* менше нiж два елементи */
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if(reverse == 0) {
            if ((*comp)(v[i], v[left]) < 0)
                swap(v, ++last, i);
        }else{
            if ((*comp)(v[i], v[left]) < 0)
                swap(v, i,++last);
        }
    swap(v, left, last);
    qsort(v, left, last-1, comp);
    qsort(v, last+1, right, comp);
}

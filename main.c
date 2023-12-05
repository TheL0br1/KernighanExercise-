#include <stdio.h>
#include<stdlib.h>
#define MAXLEN 1000

char *a[5];
int getline(char *string, int n){
    int i =0;
    while((string[i] = getchar()) != '\n' && i < n){
        i++;
    }
    return i;
}
int readlines(char *lineptr[], int maxlines)
{
    int nlines;
    int len=0;
    nlines = 0;
    while (nlines < maxlines && (len = getline(lineptr[nlines], MAXLEN)) > 0) {
       lineptr[nlines][len]= '\0';
        nlines++;
    }
    return nlines;
}

int main() {

    for (int i = 0; i < 3; ++i) {
        a[i] = malloc(MAXLEN);
    }
    readlines(a,3);
    for (int i = 0; i < 3; ++i) {
        printf("%s\n", a[i]);
    }

    return 0;
}
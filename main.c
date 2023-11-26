#include <stdio.h>
#include<stdlib.h>
int main() {
    // Для знакових типів
    int i=0;
    int lim = 10;
    char c;
    char s[10];
    while((c=getchar()) != EOF) {
        if (i > (lim - 1)) break;
        if (c == '\n') break;

        s[i] = c;
        i ++;
    }
    s[i] = '\0';
    printf("%s\n", s);
    return 0;
}

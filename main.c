#include <stdio.h>
#include<stdlib.h>
#define BUFSIZE 500 /* максимальний розмiр операнда або оператора */
void strcat1(char *s, char *t)
{
    int i, j;
    i = j = 0;
    while (*(s+i) != '\0') { /* знаходить кiнець s */
        i++;
    }
    while ((*(s+i) = *(t+j)) != '\0') { /* копiює t */
        i++; j++;
    }
}
int main() {
    char s[]="frkjlk\0";
    char t[]= "00000\0";
    strcat1(s,t);
    printf("%s", s);
    return 0;
}
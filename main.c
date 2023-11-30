#include <stdio.h>
#include<limits.h>
#include<string.h>
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
void itoa(int n, char s[], int b)
{
    int min_int = 0;
    int i, sign;
    if (INT_MIN == n) {
        min_int = 1;
        n++;
    }
    if ((sign = n) < 0) /* виявити знак */
        n = -n; /* перетворити n на додатнє */
    i = 0;
    do { /* генерувати цифри в зворотньому порядку */
        s[i++] = n % 10 + '0'; /* одержати наступну цифру */
    } while ((n /= 10) > 0 && i<b); /* видалити її */
    if (min_int) {
        s[0] = (char) (s[0] + 1);
        s[i++] = '-';
    }
    if(sign<0){
        s[i++]= '-';
    }
    while(i<b){
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s);
}

int main() {
    int a = 12000;
    char b[100];
    itoa(a,b,7);
    printf("%s", b);
    return 0;
}

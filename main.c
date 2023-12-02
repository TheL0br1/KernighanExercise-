#include <stdio.h>

void itoa(int n, char s[], int* i)
{
    if (n < 0) {
        s[(*i)++] = '-';
        n = -n;
    }

    if (n / 10) {
        itoa(n / 10, s, i);
    }

    s[(*i)++] = n % 10 + '0';
    s[*i] = '\0';
}

int main() {
    int num = 1023352;
    char result[20];
    int i = 0;

    itoa(num, result, &i);

    printf("Int: %d\nStr: %s\n", num, result);

    return 0;

}

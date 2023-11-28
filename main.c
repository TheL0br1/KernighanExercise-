#include <stdio.h>

int lower(int c)
{
    int res;
    (c >= 'A' && c <= 'Z') ?  (res= (c + 'a' - 'A')) : (res = c);
    return res;
}

int main() {
    printf("%c", lower((int) 'A'));

    return 0;
}

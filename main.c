#include <stdio.h>
#include<stdbool.h>
void printbitset(int x, int n) {
    for (int i = n - 1; i >= 0; i--) {
        printf("%d", x & (1 << i) ? 1 : 0);
    }
    printf("\n");
}
unsigned setbits(unsigned x, int p, int n, unsigned y) {
    unsigned mask = ~(~0 << n) << (p - n + 1);

    x = x & ~mask;

    y = (y & ~(~0 << n)) << (p - n + 1);

    return x | y;
}


int main() {
    unsigned int a = 30;
    unsigned int b = 2;
    printbitset(a,8);
    printbitset(b, 8);
    printbitset(setbits(a,2,2,b),8);

    return 0;
}

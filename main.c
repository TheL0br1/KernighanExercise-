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
unsigned invert(unsigned x, int p, int n){
    unsigned mask = ((x >> (p+1-n)) & ~(~0 << n))<<(p-1);
    printbitset(mask,8);
    return x ^ mask;
}
unsigned rightpot(unsigned x, unsigned n){
    return x >> n;
}
int main() {
    unsigned int a = 53;
    printbitset(a,8);
    printbitset(rightpot(a,3),8);

    return 0;
}

#include <stdio.h>
#define swap(a,b) typeof(a) temp =a; a = b; b = temp;

int main() {

    int a = 10, b = 4;
    printf("%d\t%d\n", a,b);
    swap(a,b);
    printf("%d\t%d",a,b);
    return 0;

}

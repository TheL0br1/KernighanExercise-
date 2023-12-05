#include <stdio.h>
#include "stack.h"
#include "getint.h"
#define BUFSIZE 500 /* максимальний розмiр операнда або оператора */

int main() {
    float a[100];
    printf("%d\n", getfloat(&a[0]));
    printf("%f", a[0]);
    return 0;
}
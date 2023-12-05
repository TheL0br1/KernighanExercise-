#include <stdio.h>
#include "stack.h"
#include "getint.h"
#define BUFSIZE 500 /* максимальний розмiр операнда або оператора */

int main() {
    int a[100];
    printf("%d\n", getint(&a[0]));
    printf("%d", a[0]);
    return 0;
}
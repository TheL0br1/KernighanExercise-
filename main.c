#include <stdio.h>
#include <limits.h>
#include<float.h>
int main() {
    // Для знакових типів
    printf("Signed char: [%d, %d]\n", SCHAR_MIN, SCHAR_MAX);
    printf("Signed short: [%d, %d]\n", SHRT_MIN, SHRT_MAX);
    printf("Signed int: [%d, %d]\n", INT_MIN, INT_MAX);
    printf("Signed long: [%ld, %ld]\n", LONG_MIN, LONG_MAX);

    // Для беззнакових типів
    printf("Unsigned char: [0, %u]\n", UCHAR_MAX);
    printf("Unsigned short: [0, %u]\n", USHRT_MAX);
    printf("Unsigned int: [0, %u]\n", UINT_MAX);
    printf("Unsigned long: [0, %lu]\n", ULONG_MAX);
    printf("Float: [%e, %e]\n", FLT_MIN, FLT_MAX);
    printf("Double: [%e, %e]\n", DBL_MIN, DBL_MAX);
    printf("Long Double: [%Le, %Le]\n", LDBL_MIN, LDBL_MAX);
    return 0;
}

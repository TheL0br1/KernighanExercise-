#include <stdio.h>

int main()
{
    float fahr, celsius;
    float lower, upper, step;
    lower = 0; /* нижня межа температурної шкали */
    upper = 100; /* верхня межа */
    step = 5; /* розмiр кроку */
    celsius = upper;
    printf("From Celsius to Fahrenheit\n");
    while (celsius >= lower) {
        fahr = ((9.0/5.0) * celsius)+32.0;
        printf("%3.0f %6.1f\n", celsius,fahr);
        celsius -= step;
    }
}
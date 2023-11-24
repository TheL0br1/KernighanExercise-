#include <stdio.h>

int main()
{
    float fahr, celsius;
    float lower, upper, step;
    lower = 0; /* нижня межа температурної шкали */
    upper = 300; /* верхня межа */
    step = 20; /* розмiр кроку */
    fahr = lower;
    printf("From Fahrenheit to Celsius\n");
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
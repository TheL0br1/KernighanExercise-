#include <stdio.h>

#include <stdio.h>
double f2cConv(double fahr){
    return (5.0/9.0) * (fahr-32.0);
}
double c2fConv(double cels){
    ((9.0/5.0) * cels)+32.0;
}
int main()
{
    float fahr, celsius;
    float lower, upper, step;
    lower = 0; /* нижня межа температурної шкали */
    upper = 300; /* верхня межа */
    step = 5; /* розмiр кроку */
    celsius = lower;
    printf("From Celsius to Fahrenheit\n");
    while (celsius <= upper) {
        fahr = c2fConv(celsius);
        printf("%3.0f %6.1f\n", celsius,fahr);
        celsius += step;
    }
}
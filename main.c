#include <stdio.h>
#include<limits.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
double MYatof(char s[])
{
    double val=1, power=1;
    int exp=0, expSign =1;
    int i=0, sign;
    for (i = 0; isspace(s[i]); i++) { /* пропустити пробiли */
        ;
    }
 sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.') {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if(s[i] == 'e'){
        i++;
        if(s[i]=='-'){
            i++;
            expSign=-1;
        }
    }
    for (; isdigit(s[i]); i++) {
        exp = 10.0 * exp + (s[i] - '0');
    }
    printf("%c", s[i]);
    return sign * val / power * pow(10,expSign*exp);
}

int main() {
    printf("%f", MYatof("223.333e3\0"));

    return 0;
}

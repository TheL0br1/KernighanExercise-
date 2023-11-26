#include <stdio.h>
#include <math.h>
int strlen(const char* s){
    int i = 0;
    while(s[i]!=EOF && s[i]!='\0'){
        i++;
    }
    return i;
}
int htoi(char* s){
    int result = 0;
    int i = strlen(s) - 1;
    while(s[i]!='X' && s[i]!='x'){
        if(s[i]-'0'>= 0 && s[i]-'0'<=9){
            result+= (s[i]-'0') * pow(16, strlen(s) - 1 - i);
        }
        if(s[i] == 'a' || s[i] == 'A'){
            result+= 11 * pow(16, strlen(s) - 1 - i);
        }
        if(s[i] == 'b' || s[i] == 'B'){
            result+= 12 * pow(16, strlen(s) - 1 - i);
        }
        if(s[i] == 'c' || s[i] == 'C'){
            result+= 13 * pow(16, strlen(s) - 1 - i);
        }
        if(s[i] == 'd' || s[i] == 'D'){
            result+= 13 * pow(16, strlen(s) - 1 - i);
        }
        if(s[i] == 'e' || s[i] == 'E'){
            result+= 14 * pow(16, strlen(s) - 1 - i);
        }
        if(s[i] == 'f' || s[i] == 'F'){
            result+= 15 * pow(16, strlen(s) - 1 - i);
        }
        i--;
    }
    return result;
}
int main() {
    char* s = "0XFF";
    printf("%d\n", strlen(s));
    printf("%d", htoi(s));
    return 0;
}

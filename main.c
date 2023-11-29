#include <stdio.h>
#include<stdlib.h>
#include<string.h>
char* expand(char s1[], char s2[]){
    int i  =0;
    int t =0;
    while(s1[i]!='\0'){
        if(s1[i+1]=='-'){
            for (int j = s1[i]; j <= s1[i+2]; ++j, ++t) {
                s2[t] = (char)j;
            }
            s2[t] = '\0';
        }
        i++;
    }
    printf("%s", s2);
    return s2;
}
int main() {
    char a[20] ="a-z0-9\0";
    char b[100];
    expand(a,b);
    return 0;
}

#include <stdio.h>
#include<stdlib.h>
#define BUFSIZE 500 /* максимальний розмiр операнда або оператора */
int strend(char* s, char* t){
    int i=0,j=0;
    while(s[i] != t[0]){
        i++;
    }
    while(s[i]!='\0'){
        if(s[i] != t[j++]){
            return 0;
        }
        i++;
    }
    return 1;
}
int main() {
    char s[]="frkjlk0000\0";
    char t[]= "000\0";
    int a = strend(s,t);
    printf("%d", a);
    return 0;
}
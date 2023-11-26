#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
int strlen(char* s){
    int i =0;
    while(s[i]!='\0'){
        i++;
    }
    return i;
}
void reverse(char s[]){
    for (int i = 0; i < strlen(s)/2; ++i) {
        char temp = s[i];
        s[i] = s[strlen(s)-1-i];
        s[strlen(s)-1-i] = temp;
    }
}
int main() {

    char s[] = "hello world";
    printf("S : %s\n", s);
    reverse(s);
    printf("Reversed S: %s", s);
    return 0;
}

#include <stdio.h>

void strncpy1(char*s,char*t, int n){
    int i =0;
    while(t[i]!='\0' && i<n){
        s[i] = t[i];
        i++;
    }
    s[i] = '\0';
}
void strncat1(char *s, char *t, int n){
    int i =0, j=0;
    while(s[i++]!='\0'){;}
    i--;
    while ((s[i++] = t[j++]) != '\0' && j < n) {
        ;
    }
}
int strncmp1(char *s, char*t, int n){
    int i =0;
    while(s[i]!='\0' && t[i]!='\0' && i<n){
        if(s[i]!=t[i]){
            return 0;
        }
        i++;
    }
    return 1;


}
int main() {
  ;
    return 0;
}
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
char* escape(char s[], char t[]){
    int i =0;
    int j =0;
    while(s[i]!='\0'){
        switch (s[i]) {
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            default:
                t[j++] = s[i];
        }
        i++;
    }
    t[j] = '\0';
    printf("%s", t);
    return t;
}
char* antiescape(char s[], char t[]){
    int i =0;
    int j =0;
    while(s[i]!='\0'){
        char temp[2] = {s[i],s[i+1]};
        switch (temp[0]*temp[1]) {
            case '\\' * 'n':
                t[j++] = '\n';
                i++;
                break;
            case '\\'*'t':
                t[j++] = '\t';
                i++;
                break;
            default:
                t[j++] = s[i];

        }
        i++;
    }
    t[j] = '\0';
    printf("%s", t);
    return t;
}

int main() {
    char a[20] ="\\tHello\\nWorld\\t\0";
    char b[20];

    antiescape(a,b);
    return 0;
}

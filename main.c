#include <stdio.h>
#include<string.h>

void reverse(char s[], int a, int b){
    if(a<b){
        char temp = s[a];
        s[a] = s[b];
        s[b] = temp;
        reverse(s, a+1, b-1);
    }
}
int main() {
    char s[] = "i must get reversed!";
    printf("%s\n", s);
    reverse(s,0, strlen(s)-1);
    printf("%s\n", s);


    return 0;

}

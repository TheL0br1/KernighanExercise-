#include <stdio.h>
#include<stdbool.h>
unsigned int strlen(const char* s){
    int i = 0;
    while(s[i]!=EOF && s[i]!='\0'){
        i++;
    }
    return i;
}
void squeeze(char s1[], char s2[]){
    bool map[256] ={};
    for (int i = 0; i < strlen(s2); ++i) {
        map[s2[i]] = true;
    }
    int i,j;
    for (i = j = 0; s1[i] != '\0'; i++) {
        if (!map[s1[i]])
            s1[j++] = s1[i];
    }
    s1[j] = '\0';


}
int main() {
    char s1[] = "qkekefqmnkefk\0";
    char s2[] = "dlkfevnf\0";
    squeeze(s1,s2);
    printf("%s", s1);
    return 0;
}

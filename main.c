#include <stdio.h>
#include<stdbool.h>
unsigned int strlen(const char* s){
    int i = 0;
    while(s[i]!=EOF && s[i]!='\0'){
        i++;
    }
    return i;
}
uintptr_t /*unsigned ll*/ any(char s1[], char s2[]){
    bool map[256] ={};
    for (int i = 0; i < strlen(s2); ++i) {
        map[s2[i]] = true;
    }
    int i,j;
    for (i = j = 0; s1[i] != '\0'; i++) {
        if (map[s1[i]])
            return i;
    }
    s1[j] = '\0';


}
int main() {
    char s1[] = "qkekefqmnkefk\0";
    char s2[] = "dlkfevnf\0";
    printf("%d",     any(s1,s2));
    return 0;
}

#include <stdio.h>
#include<limits.h>
#include<string.h>


int strindex(char s[], char t[]) {
    int i, j, k, lastMatch = -1;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;

        if (t[k] == '\0') {
            lastMatch = i;
        }
    }

    return lastMatch;
}

int main() {
    printf("%d\n", strindex("hello world", "wo"));
    printf("%d\n", strindex("hello world", "ow"));

    return 0;
}

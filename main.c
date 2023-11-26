#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
int main() {

    char *longest = malloc(20);
    while (1) {
        long long i = 0;
        long long size = 20;
        char *line = malloc(size);
        long long lastSymbol = 0;
        bool flag = false;
        while ((line[i] = getchar()) != EOF && line[i] != '\n') {

            i++;
            if (i >= size) {
                size *= 2;
                line = realloc(line, size);
                if (line == NULL) {
                    break;
                }
            }
            if(!(line[i-1]==' ' || line[i-1] == '\t')){
                lastSymbol = (i-1);
            }else{
                flag = true;
            }

        }
        if(flag) {
            line[lastSymbol+1] = '\0';
        }else{
            line[i] = '\0';

        }


        printf("String = %s, Address: %u, len: %d\n", line, line, i);
        if(line[i]==EOF){
            free(line);
            break;
        }

    }

    free(longest);
    return 0;
}

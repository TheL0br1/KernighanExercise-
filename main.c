#include <stdio.h>
#include <stdlib.h>

int main() {

    char *longest = malloc(20); /* найдовший рядок буде збережено тут */
    while (1) {
        long long i = 0;
        long long size = 20;
        char *line = malloc(size); /* поточний рядок вводу */
        while ((line[i] = getchar()) != EOF && line[i] != '\n') {

            i++;
            if (i >= size) {
                size *= 2;
                line = realloc(line, size);
                if (line == NULL) {
                    break;
                }
            }
        }
        if(line[i]==EOF){
            break;
        }
        line[i] = '\0';
        printf("String = %s, Address: %u\n", line, line);
        if (i >= 80) {

            printf("Line above 80 char: %s, Address: %u\n", line, line);
        }
        free(line);

    }

    free(longest);
    return 0;
}

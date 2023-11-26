#include <stdio.h>
#include <stdlib.h>
long long getline(char *p);
void copy(char to[], char from[]);
/* виводить найдовший рядок вводу */
int main() {
    long long max; /* найбiльша знайдена довжина */

    char *longest = malloc(20); /* найдовший рядок буде збережено тут */
    max = 0;
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
        if (i > max) {
            max = i;
            longest = malloc(i);
            printf("temp line: %s, Address: %u\n", line, line);
            copy(longest, line);
        }
        free(line);

    }

    if (max > 0) /* було знайдено рядок */
        printf("Longest String: %s", longest);
    free(longest);
    return 0;
}
/* getline: зчитує рядок у s, повертає довжину */
long long getline(char *p)
{
    long long size = 20;
    long long i = 0;
    while((p[i]= getchar())!=EOF && p[i]!='\n'){
        i++;
        if(i>=size){
            size*=2;
            p = realloc(p, size);
            if(p==NULL){
                return -1;
            }
        }
    }
    p[i]='\0';
    printf("String = %s, Address: %u\n", p, p);
    return i;
}
/* copy: копiює from до to; припускає, що to досить великий */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
    ++i;
}
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int getline(char **p) {
    long long size = 20;
    *p = malloc(size);
    long long i = 0;
    int c;

    if (*p == NULL) {
        return -1;
    }

    while ((c = getchar()) != EOF && c != '\n') {
        (*p)[i] = c;
        i++;
        if (i >= size) {
            size *= 2;
            *p = realloc(*p, size);
            if (*p == NULL) {
                return -1;
            }
        }
    }
    if(c==EOF){
        return -1;
    }
    (*p)[i] = '\0';
    printf("String = %s, Address: %p\n", *p, (void *)*p);
    return i;
}
int main(int argc, char*argv[]) {
    int n = 10;
    int i = 0;
    if(argc>1){
        n = atoi(argv[1]);

    }
    char **s = malloc(n * sizeof(char *));
    while (getline(&(s[i]))!=-1){
        printf("%s\n", s[i]);

        i++;
        if(i>=(n+1)){
            i=0;
        }
    }
    n = (n>i) ? i:n;
    for (int j = 0; j < n; ++j) {
        printf("%s\n", s[j]);
    }
    return 0;
}

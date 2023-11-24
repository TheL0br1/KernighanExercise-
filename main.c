#include <stdio.h>
#include<stdbool.h>
#include <stdlib.h>

#define  MAXLENGTH 256
void printGisto(int *gisto){
    for (int i = 0; i < MAXLENGTH; ++i) {
        if(gisto[i]==0) continue;
        printf("%c: ", (char)i);
        for (int j = 0; j < gisto[i]; ++j) {
            printf("-");
        }
        printf("\n");
    }
}
int main()
{
    int gisto[MAXLENGTH] = {0};
    char c;
    bool flag = false;
    while((c=getchar())!=EOF){
        gisto[c]++;
    }

    printGisto(gisto);
    return 0;
}
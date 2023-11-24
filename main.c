#include <stdio.h>
#include<stdbool.h>
#include <stdlib.h>

#define  MAXLENGTH 100
void printGisto(int *gisto){
    for (int i = 0; i < MAXLENGTH; ++i) {
        if(gisto[i]==0) continue;
        printf("%d: ", i);
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
    int count =0;
    while((c=getchar())!=EOF){
        switch (c) {
            case ' ':
                if(flag) {
                    gisto[count]++;
                    count = 0;
                }
                flag = false;
                break;
            default:
                count++;
                flag = true;
                break;
        }
    }
    printGisto(gisto);
    system("PAUSE");

    return 0;
}
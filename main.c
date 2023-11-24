#include <stdio.h>

int main()
{
    char c;
    int countTab=0, countNL=0, countSpace=0;
    while((c=getchar())!=EOF){
        switch (c) {
            case ' ':
                countSpace++;
            case '\n':
                countNL++;
            case '\t':
                countTab++;
        }
    }
    printf("%d, %d, %d", countSpace, countTab, countNL);


    return 0;
}
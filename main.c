#include <stdio.h>

int main()
{
    char c;
    while(1){
        if((c=getchar())!=EOF){
            putchar(c);

        }else{
            printf("%d",EOF);
            return 0;
        }
    }
}
#include <stdio.h>
#include<stdbool.h>
int main()
{
    char c;
    bool flag = true;
    while((c=getchar())!=EOF){
        switch (c) {
            case ' ':
                if(flag) {
                    printf("\n");
                }
                flag = false;
                break;
            default:
                printf("%c", c);
                flag = true;
                break;
        }
    }


    return 0;
}
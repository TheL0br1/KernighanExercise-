#include <stdio.h>
#include<stdbool.h>
int main()
{
    char c;
    bool flag = true;
    while((c=getchar())!=EOF){
        if(c!=' '){
            putchar(c);
            flag = true;
        }
        if(c==' ' && flag){
            flag = false;
            putchar(c);
        }
    }


    return 0;
}
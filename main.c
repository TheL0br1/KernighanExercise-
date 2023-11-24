#include <stdio.h>
#include<stdbool.h>
int main()
{
    char c;
    bool flag = false;
    while((c=getchar())!=EOF){
        switch (c) {
            case '\n':
                printf("\\n");
                break;
            case '\t':
                printf("\\t");
                break;
            case '\b':
                printf("\\b");
                break;
            default:
                printf("%c", c);
                break;
        }


    }


    return 0;
}
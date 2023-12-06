#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "stack.h"
#define NUMBER '0'
int getNext(char* a){
    int i = 0;
    int size = strlen(a);
    while(a[i] == ' ' || a[i] == '\t'){ i++;}
    if(a[i]== '-' && isdigit(a[i+1])){
        return NUMBER;
    }
    if(!isdigit(a[i]) ){
        return a[i];
    }
    else{
        return NUMBER;
    }

}
int main(int argc, char* argv[]) {

    if(argc<=1){
        return -1;
    }
    for (int i = 0; i <argc; ++i) {
        printf("%s\n", argv[i]);
    }
    int type = 0;
    int op2;
    for (int i = 1; i <argc; ++i) {
        type = getNext(argv[i]);
        switch (type) {
            case NUMBER:
                push(atof(argv[i]));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());

                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                }

                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", argv[i]);
                break;
        }
    }
    printf("\t%.8g\n", pop());

    return 0;
}
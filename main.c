#include <stdio.h>
#include <stdlib.h> /* для atof() */
#include<math.h>
#include <ctype.h>
#include<string.h>
#include "stack.h"
#define BUFSIZE 500 /* максимальний розмiр операнда або оператора */
#define NUMBER '0' /* сигналiзувати, що номер знайдено */

int getop(char []);
void push(double);
double pop(void);

int getline(char s[], int buffer){
    int i =0;
    while(i<buffer && (s[i++]=getchar()) !='\n'){
        ;
    }
    return i-1;
}
float getNextNumber(char s[]){
    int i = 0;
    if(s[i]=='-' && strlen(s)>1 && isdigit(s[1])){
    }
    else if(s[i]!='.' && !isdigit(s[i])){
        return s[i];
    }
    return NUMBER;
}
int main() {
    int type;
    double op2;
    char buff[BUFSIZE];
    int length = 1;
    char *token;
    getline(buff, BUFSIZE);

    int i;
    while(buff[length-1]!=EOF) {
        token = strtok(buff, " ");
        while (token != NULL) {

            type = getNextNumber(token);
            switch (type) {
                case NUMBER:
                    push(atof(token));
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
                case '%':
                    op2 = pop();
                    push((int) pop() % (int) op2);
                    break;
                case '/':
                    op2 = pop();
                    if (op2 != 0.0)
                        push(pop() / op2);
                    else
                        printf("error: zero divisor\n");
                    break;
                case 's':
                    push(sin(pop()));
                    break;
                case 'c':
                    push(cos(pop()));
                    break;
                case 'e':
                    push(exp(pop()));
                    break;
                case 'p':
                    op2 = pop();
                    push(pow(pop(), op2));
                    break;
                case '\n':
                    printf("\t%.8g\n", pop());
                    break;
                default:
                    printf("error: unknown command \n");
                    break;
            }
            if(token[1]=='\n'){
                break;
            }
            token = strtok(NULL, " ");
        }
        printf("\t%.8g\n", pop());

        length = getline(buff, 500);

    }
    return 0;
}
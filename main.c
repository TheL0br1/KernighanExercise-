#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include "getch.h"

#define MAXTOKEN 100
enum { NAME, PARENS, BRACKETS, QUAL };
void dcl(void);
void dirdcl(void);
int gettoken(void);
int tokentype; /* тип останньої лексеми */
char token[MAXTOKEN]; /* ланцюжок останньої лексеми */
char name[MAXTOKEN]; /* назва iдентифiкатору */
char datatype[MAXTOKEN]; /* тип даних = char, int тощо */
char out[1000];
char datatype1[MAXTOKEN]; /* тип даних = char, int тощо */
char out1[1000];

int main() /* перетворює оголошення на словесний опис */
{
    int temp;
    while ((temp=gettoken()) != EOF) { /* перша лексема рядка */
        if(temp == NAME || temp == QUAL){
            strcat(datatype, strcat(token," "));
            continue;/* is the datatype */
        }
        if(temp == '*'){
            ungetch('*');
        }
        out[0] = '\0';
        dcl(); /* читання решти рядка */
        if (tokentype != '\n') {
            printf("syntax error\n");
        }
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;

}
int gettoken(void) /* return next token */
{
    int c;
    char *p = token;
    while ((c = getch()) == ' ' || c == '\t') { ;
    }
    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            return tokentype = '(';
        }
    } else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']'; ) {
            ;
        }
        *p = '\0';
        return tokentype = BRACKETS;
    } else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch());) {
            *p++ = c;
        }
        *p = '\0';
        ungetch(c);
        if(strcmp(token, "const") == 0 || strcmp(token, "static")==0){
            return QUAL;
        }
        return tokentype = NAME;
    } else {
        return tokentype = c;
    }
}
void dcl(void)
{
    int ns;
    for (ns = 0; gettoken() == '*'; ) { /* count *’s */
        ns++;
    }
    dirdcl();
    while (ns-- > 0)
        strcat(out1, " pointer to");
    strcat(out1,out);
    strcpy(out, out1);
}
/* dirdcl: прочитує безпосереднiй оголошувач */
void dirdcl(void) {
    int type;
    if (tokentype == '(') { /* ( dcl ) */
        dcl();
        if (tokentype != ')') {
            printf("error: missing )\n");
            while (gettoken() != ')' && tokentype != '\n') {}
        }
    } else if (tokentype == NAME)
        strcpy(name, token);
    else
        printf("error: expected name or (dcl)\n");

    while ((type = gettoken()) == PARENS || type == BRACKETS || type =='(') {
        if(type =='('){
            strcat(out, " function, that takes");
            while ((type=gettoken()) != ')') { /* перша лексема рядка */
                if (type == NAME || type == QUAL) {
                    strcat(datatype1, strcat(token, " "));
                    continue;/* is the datatype */
                }
            }
            ungetch(type);
            if (type == '*') {
                ungetch('*');
            }
            strcat(datatype1, "returning ");
            strcat(datatype1, datatype);
            strcpy(datatype, datatype1);
        }

        if(type == BRACKETS) {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }

    if (type != '\n') {
        while (gettoken() != '\n') {;
        }
    }
}

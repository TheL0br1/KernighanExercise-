#include <stdio.h>
#include <string.h>
#include <ctype.h>
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

int main() /* перетворює оголошення на словесний опис */
{
    int type;
    int prev_type=-1;
    char temp[MAXTOKEN];
    while (gettoken() != EOF) {
        strcpy(out, token);
        while ((type = gettoken()) != '\n') {
            if (type == PARENS || type == BRACKETS) {
                strcat(out, token);
            }
            else if (type == '*') {
                if(prev_type == BRACKETS){
                    sprintf(temp, "*%s", out);

                }
                else {
                    sprintf(temp, "(*%s)", out);
                }
                strcpy(out, temp);
            } else if (type == NAME) {
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            } else
                printf("invalid input at %s\n", token);
            prev_type = type;
        }
        printf("%s\n", temp);
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
        strcat(out, " pointer to");
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

    while ((type = gettoken()) == PARENS || type == BRACKETS || type == QUAL) {
        if (type == PARENS)
            strcat(out, " function returning");
        else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }

    if (type != '\n') {
        printf("error: expected newline\n");
        while (gettoken() != '\n') {}
    }
}

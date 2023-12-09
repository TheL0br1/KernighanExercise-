#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include<stdbool.h>
#include <malloc.h>
#include "getch.h"
#include<alg.h>
#define MAXWORD 100
#define NKEYS 12
struct tnode { /* вузол дерева: */
    char *word; /* покажчик на ланцюжок */
    int line; /* кiлькiсть його повторень */
    struct tnode *left; /* лiвий дочiрнiй вузол */
    struct tnode *right; /* правий дочiрнiй вузол */
};
int n;
int newlinec;
bool iskeyword(char* str);
struct tnode *addtree(struct tnode *, char *);
int getword(char *, int);
void treeprint(struct tnode *);

int main(int argc, char*argv[])
{
    newlinec = 0;
    if(argc > 1){
        n = atoi(argv[1]);
    }
    struct tnode *root;
    root = NULL;
    char word[MAXWORD];
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if(!iskeyword(word)){
                root = addtree(root, word);
            }
    treeprint(root);
    return 0;
}
int getword(char *word, int lim)
{
    int c;
    char *w = word;
    while (isspace(c = getch())){
        if(c == '\n'){
            newlinec++;
        }
    }


    if(c=='"'){
        while ((c = getch())=='"')
            ;
        while ((c = getch())!='"')
            ;
        while ((c = getch())=='"')
            ;
    }
    if(c=='/'){
        if((c=getch()) == '/'){
            while ((c = getch())!='\n')
                ;
        }else if(c == '*'){
            while ((c = getch())!='/')
                ;
        }else{
            ungetch(c);
        }
    }
    if(c=='#'){
        c = getch();

    }

    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}
//Ну не писав же я цю функція вручну, чи не так? (◠‿・)—☆
bool iskeyword(char* str)
{
    if (!strcmp(str, "auto") || !strcmp(str, "default")
        || !strcmp(str, "signed") || !strcmp(str, "enum")
        || !strcmp(str, "extern") || !strcmp(str, "for")
        || !strcmp(str, "register") || !strcmp(str, "if")
        || !strcmp(str, "else") || !strcmp(str, "int")
        || !strcmp(str, "while") || !strcmp(str, "do")
        || !strcmp(str, "break") || !strcmp(str, "continue")
        || !strcmp(str, "double") || !strcmp(str, "float")
        || !strcmp(str, "return") || !strcmp(str, "char")
        || !strcmp(str, "case") || !strcmp(str, "const")
        || !strcmp(str, "sizeof") || !strcmp(str, "long")
        || !strcmp(str, "short") || !strcmp(str, "typedef")
        || !strcmp(str, "switch")
        || !strcmp(str, "unsigned") || !strcmp(str, "void")
        || !strcmp(str, "static") || !strcmp(str, "struct")
        || !strcmp(str, "goto") || !strcmp(str, "union")
        || !strcmp(str, "volatile"))
        return (true);
    return (false);
}
int flagprint = 1;
void treeprint(struct tnode *p)
{
    if (p != NULL) {
        if(flagprint && strlen(p->word)>=n) {
            printf("group similar to %s:\n", p->word);
            flagprint = 0;
        }
        treeprint(p->left);
        flagprint = 1;

        if(strlen(p->word)>=n) {
            printf("%s, line: %d\n" , p->word, (p->line + 1));
        }
        treeprint(p->right);
    }
}
struct tnode *addtree(struct tnode *p, char *w)
{
    if (p == NULL) { /* надiйшло нове слов */
        p = (struct tnode *)malloc(sizeof(struct tnode)); /* створити новий вузол */
        p->word = strdup(w);
        p->line = newlinec;
        p->left = p->right = NULL;
    }
    else if (strncmp(w, p->word,n) == 0 && strcmp(w, p->word) != 0) /* якщо менше - лiве вiдгалуження */
        p->left = addtree(p->left, w);
    else if(strcmp(w, p->word) != 0)/* якщо бiльше - праве вiдгалуження */
        p->right = addtree(p->right, w);
    return p;
}

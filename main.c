#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include<stdbool.h>
#include <malloc.h>
#include "getch.h"
#include<alg.h>
#define MAXWORD 100
struct buffer{
    char *string;
    int count;
} buffer[1000];
int buffcounter;

struct tnode { /* вузол дерева: */
    char *word; /* покажчик на ланцюжок */
    int count; /* кiлькiсть його повторень */
    struct tnode *left; /* лiвий дочiрнiй вузол */
    struct tnode *right; /* правий дочiрнiй вузол */
};
int n;
bool iskeyword(char* str);
struct tnode *addtree(struct tnode *, char *);
int getword(char *, int);
void treeprint(struct tnode *);
int comp(const struct buffer* a, const struct buffer *b);
int main(int argc, char*argv[])
{
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
    qsort(buffer, buffcounter, sizeof(struct buffer), (int (*)(const void *, const void *)) comp);
    for (int i = 0; i < buffcounter; ++i) {
        printf("string: %s, count: %d\n", buffer[i].string, buffer[i].count);
    }
    return 0;
}
int getword(char *word, int lim)
{
    int c;
    char *w = word;
    while (isspace(c = getch())){
        ;
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
        buffer[buffcounter].string = malloc(strlen(p->word));
        buffer[buffcounter].count = p->count;
        strcpy(buffer[buffcounter++].string, p->word);
        treeprint(p->left);
        treeprint(p->right);
    }
}

struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;
    if (p == NULL) { /* надiйшло нове слово */
        p = (struct tnode *)malloc(sizeof(struct tnode)); /* створити новий вузол */
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++; /* повторне слово */
    else if (cond < 0) /* якщо менше - лiве вiдгалуження */
        p->left = addtree(p->left, w);
    else /* якщо бiльше - праве вiдгалуження */
        p->right = addtree(p->right, w);
    return p;
}
int comp(const struct buffer* a, const struct buffer *b){
    if(a->count==b->count){
        return 0;
    }
    else if(a->count>b->count){
        return -1;
    }else{
        return 1;
    }
}


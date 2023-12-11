#include <stdio.h>
#include<string.h>
#include<malloc.h>
#include <ctype.h>
#include "getch.h"
#define HASHSIZE 101
#define MAXWORD 101
struct nlist { /* запис таблицi: */
    struct nlist *next; /* наступний запис в ланцюжку */
    char *name; /* визначене iм’я */
    char *defn; /* текст замiни */
};
static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np; /* знайдено */
    return NULL; /* не знайдено */
}
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;
    if ((np = lookup(name)) == NULL) { /* not found */
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else /* already there */
        free((void *) np->defn); /*free previous defn */
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}
int under(char *s){
    struct nlist *np;
    if ((np = lookup(s)) != NULL){
        if(np->next!=NULL){
            hashtab[hash(s)] = np->next;
            free(np);
            return 0;
        }
        hashtab[hash(s)] = NULL;
        free(np);
    }
    return -1;
}

int getword(char *word, int lim)
{
    int c;
    char *w = word;
    while (isspace(c = getch()))
        ;
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
    if (!isalnum(c)) {
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
int main()
{
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF)
        if (strcmp(word,"define\0")==0){
            getword(word, MAXWORD);
            char* temp1 = strdup(word);
            getword(word, MAXWORD);
            char* temp2 = strdup(word);
            install(temp1, temp2);
            printf("added new element to hashtable\n");
        }
    return 0;
}



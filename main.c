#include <stdio.h>
#include<string.h>
#include<malloc.h>
#define HASHSIZE 5
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

int main()
{
    install("1", "11");
    install("2", "22");
    install("4", "44");
    install("5", "55");
    install("6", "66");
    install("7", "77");
    under("7");
    return 0;
}



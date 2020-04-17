#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLESIZE 101

struct pair {
    char* key;
    char* val;
};

// "unsigned", itself is a shortcut of "unsigned int"
unsigned int hash(char* s);
struct pair* put(char* key, char* val);
struct pair* lookup(char* s);
char* copyWord(char* w);
void printHTable();

struct pair* hashtab[TABLESIZE];

// hash table
int main()
{
    char k1[] = "curtis";
    char v1[] = "newbie";
    put(k1, v1);
    printHTable();

    char k2[] = "sharon";
    char v2[] = "lol";
    char v5[] = "mer";
    put(k2, v2);
    put(k1, v5);
    printHTable();
}

/* look for char *s */
struct pair* lookup(char* s)
{
    struct pair* np = hashtab[hash(s)];

    if (np != NULL && strcmp(s, np->key) == 0)
        return np;

    // not found
    return NULL;
}

// typical hash functionality for demo
unsigned int hash(char* s)
{
    unsigned int h;
    for (h = 0; *s != '\0'; s++) {
        h = *s + 31 * h;
    }
    // for distribution
    return h % TABLESIZE;
}

/* put a key/val pair to hashtable, if no duplicate of key found, create a new 
one, otherwise overwrite the value of previous one.*/
struct pair* put(char* key, char* val)
{
    struct pair* np;
    unsigned hashval;

    if ((np = lookup(key)) == NULL) {

        // not exists, create one
        np = malloc(sizeof(struct pair));
        if (np == NULL || (np->key = copyWord(key)) == NULL)
            // out of memory
            return NULL;

        hashval = hash(key);
        hashtab[hashval] = np;
    } else {
        free(np->val); /* as the previous value is overwritten, free it*/
    }

    // overwrites previous values
    if ((np->val = copyWord(val)) == NULL)
        return NULL;
    return np;
}

// copy the word and allocate a new memory for it, returns the pointer to this copied word
char* copyWord(char* w)
{
    char* t = malloc(sizeof(char) * strlen(w) + 1);
    if (t != NULL) // when there is no memory available, t is NULL
        strcpy(t, w);
    return t;
}

void printHTable()
{
    struct pair* tp = hashtab[0];

    for (int i = 0; i < TABLESIZE; i++) {
        if (hashtab[i] != NULL) {
            printf("[%d] -> ", i);
            printf("{ key: %s, value: %s}\n", hashtab[i]->key, hashtab[i]->val);
        }
    }
}

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LEN 15
#define WORDS 5

// btree node
struct tnode {
    char* word;
    // left node
    struct tnode* l;
    // right node
    struct tnode* r;
};

int getWord(char*, int);
struct tnode* addNode(struct tnode*, char*);
struct tnode* allocNode(void);
void inOrderTraversal(struct tnode*);
char* copyWord(char*);

int main()
{
    struct tnode* root = NULL;
    char word[WORD_LEN];
    for (int i = 0; i < WORDS; i++) {
        getWord(word, WORD_LEN);
        root = addNode(root, word);
    }
    inOrderTraversal(root);
    return 0;
}

/* 

len: the length of the char[]

return the first char in this word
*/
int getWord(char* word, int len)
{
    int c, i;
    for (i = 0; i < len - 1 && (c = getchar()) != EOF && isalpha(c); i++)
        *(word + i) = c;

    *(word + i) = '\0';
    return *word;
}

// add node of word *w to a sub-tree rooted at *p
struct tnode* addNode(struct tnode* p, char* w)
{
    if (p == NULL) { // at right position
        p = allocNode();
        char* wp = copyWord(w);
        if (wp == NULL)
            printf("Not enought memory available, failed at copying %s", w);
        else
            p->word = wp; // do not just copy word, as all nodes will be pointing to the same word
    } else if (strcmp(w, p->word) >= 0) {
        p->r = addNode(p->r, w);
    } else {
        p->l = addNode(p->l, w);
    }
    return p;
}

// alloc a new tnode
struct tnode* allocNode(void)
{
    struct tnode* t = malloc(sizeof(struct tnode));
    t->l = t->r = NULL;
    return t;
}

char* copyWord(char* w)
{
    char* t = malloc(sizeof(char) * strlen(w) + 1);
    if (t != NULL) // when there is no memory available, t is NULL
        strcpy(t, w);
    return t;
}

void printNode(struct tnode*);

void inOrderTraversal(struct tnode* p)
{
    printf("Tree: { ");
    printNode(p);
    printf("}\n");
}

void printNode(struct tnode* p)
{
    if (p != NULL) {
        printNode(p->l);
        printf("%s ", p->word);
        printNode(p->r);
    }
}
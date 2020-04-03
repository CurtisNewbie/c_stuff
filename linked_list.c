#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
};

struct node* addNode(struct node* n, int val);
struct node* allocNode(int val);
void printNode(struct node* root);
void printTree(struct node* root);

// singly linked list
int main()
{
    struct node* root = NULL;
    root = addNode(root, 1);
    addNode(root, 3);
    addNode(root, 5);
    printTree(root);
}

struct node* addNode(struct node* n, int val)
{
    if (n != NULL) {
        if (n->next == NULL)
            n->next = allocNode(val);
        else
            n->next = addNode(n->next, val);
    } else {
        n = allocNode(val);
    }
    return n;
}

struct node* allocNode(int val)
{
    struct node* t = malloc(sizeof(struct node));
    t->val = val;
    t->next = NULL;
    return t;
}

void printTree(struct node* root)
{
    printf("LinkedList: { ");
    printNode(root);
    printf("}\n");
}

void printNode(struct node* n)
{
    if (n != NULL) {
        printf("%d ", n->val);
        printNode(n->next);
    }
}

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node* create()
{
    int x;
    struct node *newnode;

    printf("Enter data (-1 for no node): ");
    scanf("%d", &x);

    if (x == -1)
        return NULL;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;

    printf("Left child of %d:\n", x);
    newnode->left = create();

    printf("Right child of %d:\n", x);
    newnode->right = create();

    return newnode;
}

int symmetric(struct node *a, struct node *b)
{
    if (a == NULL && b == NULL)
        return 1;

    if (a == NULL || b == NULL)
        return 0;

    if (a->data != b->data)
        return 0;

    return symmetric(a->left, b->right) &&
           symmetric(a->right, b->left);
}

int main()
{
    struct node *root;

    printf("Create Binary Tree:\n");
    root = create();

    if (symmetric(root->left, root->right))
        printf("Tree is Symmetric.\n");
    else
        printf("Tree is Not Symmetric.\n");

    return 0;
}
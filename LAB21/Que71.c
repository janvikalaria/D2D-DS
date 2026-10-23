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

int same(struct node *a, struct node *b)
{
    if (a == NULL && b == NULL)
        return 1;

    if (a == NULL || b == NULL)
        return 0;

    if (a->data != b->data)
        return 0;

    return same(a->left, b->left) &&
           same(a->right, b->right);
}

int main()
{
    struct node *root1, *root2;

    printf("\nCreate First Tree:\n");
    root1 = create();

    printf("\nCreate Second Tree:\n");
    root2 = create();

    if (same(root1, root2))
        printf("\nBoth trees are SAME.\n");
    else
        printf("\nBoth trees are NOT SAME.\n");

    return 0;
}
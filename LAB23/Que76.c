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

int height(struct node *root)
{
    int leftHeight, rightHeight;

    if (root == NULL)
        return 0;

    leftHeight = height(root->left);
    rightHeight = height(root->right);

    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

int balanced(struct node *root)
{
    int leftHeight, rightHeight;

    if (root == NULL)
        return 1;

    leftHeight = height(root->left);
    rightHeight = height(root->right);

    if (abs(leftHeight - rightHeight) > 1)
        return 0;

    return balanced(root->left) && balanced(root->right);
}

int main()
{
    struct node *root;

    printf("Create Binary Tree:\n");
    root = create();

    if (balanced(root))
        printf("TRUE: Tree is Height-Balanced.\n");
    else
        printf("FALSE: Tree is Not Height-Balanced.\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node* insert(struct node *root, int x)
{
    if (root == NULL)
    {
        root = (struct node*)malloc(sizeof(struct node));
        root->data = x;
        root->left = NULL;
        root->right = NULL;
    }
    else if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

void smallest(struct node *root)
{
    if (root == NULL)
    {
        printf("Tree is empty.\n");
        return;
    }

    while (root->left != NULL)
        root = root->left;

    printf("Smallest element = %d\n", root->data);
}

void largest(struct node *root)
{
    if (root == NULL)
    {
        printf("Tree is empty.\n");
        return;
    }

    while (root->right != NULL)
        root = root->right;

    printf("Largest element = %d\n", root->data);
}

int main()
{
    struct node *root = NULL;
    int n, i, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &x);
        root = insert(root, x);
    }

    smallest(root);
    largest(root);

    return 0;
}
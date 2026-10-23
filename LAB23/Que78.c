
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data1, data2;
    int count;
    struct node *left, *middle, *right;
};

struct node* createNode(int x)
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data1 = x;
    newnode->data2 = 0;
    newnode->count = 1;

    newnode->left = NULL;
    newnode->middle = NULL;
    newnode->right = NULL;

    return newnode;
}

void inorder(struct node *root)
{
    if (root == NULL)
        return;

    if (root->count == 1)
    {
        inorder(root->left);
        printf("%d ", root->data1);
        inorder(root->middle);
    }
    else
    {
        inorder(root->left);
        printf("%d ", root->data1);
        inorder(root->middle);
        printf("%d ", root->data2);
        inorder(root->right);
    }
}

int main()
{
    struct node *root = NULL;
    int n, i, x;

    printf("Enter number of values: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &x);

        if (root == NULL)
        {
            root = createNode(x);
        }
        else if (root->count == 1)
        {
            if (x < root->data1)
            {
                root->data2 = root->data1;
                root->data1 = x;
            }
            else
            {
                root->data2 = x;
            }

            root->count = 2;
        }
        else
        {
            printf("This simple program supports only 2 keys in the root.\n");
            break;
        }
    }

    printf("Inorder traversal: ");
    inorder(root);

    return 0;
}

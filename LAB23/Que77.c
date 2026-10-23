
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    char color;
    struct node *left, *right, *parent;
};

struct node *root = NULL;

struct node* createNode(int data)
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = data;
    newnode->color = 'R';
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->parent = NULL;

    return newnode;
}

void leftRotate(struct node *x)
{
    struct node *y = x->right;

    x->right = y->left;

    if (y->left != NULL)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void rightRotate(struct node *x)
{
    struct node *y = x->left;

    x->left = y->right;

    if (y->right != NULL)
        y->right->parent = x;

    y->parent = x->parent;

    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->right)
        x->parent->right = y;
    else
        x->parent->left = y;

    y->right = x;
    x->parent = y;
}

void fixTree(struct node *z)
{
    struct node *uncle;

    while (z != root && z->parent->color == 'R')
    {
        if (z->parent == z->parent->parent->left)
        {
            uncle = z->parent->parent->right;

            if (uncle != NULL && uncle->color == 'R')
            {
                z->parent->color = 'B';
                uncle->color = 'B';
                z->parent->parent->color = 'R';
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->right)
                {
                    z = z->parent;
                    leftRotate(z);
                }

                z->parent->color = 'B';
                z->parent->parent->color = 'R';
                rightRotate(z->parent->parent);
            }
        }
        else
        {
            uncle = z->parent->parent->left;

            if (uncle != NULL && uncle->color == 'R')
            {
                z->parent->color = 'B';
                uncle->color = 'B';
                z->parent->parent->color = 'R';
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->left)
                {
                    z = z->parent;
                    rightRotate(z);
                }

                z->parent->color = 'B';
                z->parent->parent->color = 'R';
                leftRotate(z->parent->parent);
            }
        }
    }

    root->color = 'B';
}

void insert(int data)
{
    struct node *newnode = createNode(data);
    struct node *parent = NULL;
    struct node *temp = root;

    while (temp != NULL)
    {
        parent = temp;

        if (data < temp->data)
            temp = temp->left;
        else if (data > temp->data)
            temp = temp->right;
        else
        {
            printf("Duplicate value not allowed.\n");
            free(newnode);
            return;
        }
    }

    newnode->parent = parent;

    if (parent == NULL)
        root = newnode;
    else if (data < parent->data)
        parent->left = newnode;
    else
        parent->right = newnode;

    fixTree(newnode);

    printf("Node inserted successfully.\n");
}

void inorder(struct node *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        printf("%d(%c) ", temp->data, temp->color);
        inorder(temp->right);
    }
}

int main()
{
    int choice, data;

    do
    {
        printf("\n\n1. Insert");
        printf("\n2. Display Inorder");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &data);
                insert(data);
                break;

            case 2:
                printf("Inorder Traversal:\n");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);

    return 0;
}

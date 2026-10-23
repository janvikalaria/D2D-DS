#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[50];
    char phone[15];
    struct node *left, *right;
};

struct node* add(struct node *root, char name[], char phone[])
{
    if (root == NULL)
    {
        struct node *newnode;
        newnode = (struct node*)malloc(sizeof(struct node));

        strcpy(newnode->name, name);
        strcpy(newnode->phone, phone);

        newnode->left = NULL;
        newnode->right = NULL;

        return newnode;
    }

    if (strcmp(name, root->name) < 0)
        root->left = add(root->left, name, phone);
    else if (strcmp(name, root->name) > 0)
        root->right = add(root->right, name, phone);
    else
        printf("Name already exists!\n");

    return root;
}

struct node* search(struct node *root, char name[])
{
    if (root == NULL || strcmp(name, root->name) == 0)
        return root;

    if (strcmp(name, root->name) < 0)
        return search(root->left, name);
    else
        return search(root->right, name);
}

struct node* minimum(struct node *root)
{
    while (root != NULL && root->left != NULL)
        root = root->left;

    return root;
}

struct node* deleteEntry(struct node *root, char name[])
{
    struct node *temp;

    if (root == NULL)
        return NULL;

    if (strcmp(name, root->name) < 0)
        root->left = deleteEntry(root->left, name);
    else if (strcmp(name, root->name) > 0)
        root->right = deleteEntry(root->right, name);
    else
    {
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        temp = minimum(root->right);

        strcpy(root->name, temp->name);
        strcpy(root->phone, temp->phone);

        root->right = deleteEntry(root->right, temp->name);
    }

    return root;
}

void ascending(struct node *root)
{
    if (root != NULL)
    {
        ascending(root->left);
        printf("%s : %s\n", root->name, root->phone);
        ascending(root->right);
    }
}

void descending(struct node *root)
{
    if (root != NULL)
    {
        descending(root->right);
        printf("%s : %s\n", root->name, root->phone);
        descending(root->left);
    }
}

int main()
{
    struct node *root = NULL, *temp;
    char name[50], phone[15];
    int choice;

    do
    {
        printf("\n--- PHONE BOOK ---\n");
        printf("1. Add New Entry\n");
        printf("2. Remove Entry\n");
        printf("3. Search Phone Number\n");
        printf("4. List in Ascending Order\n");
        printf("5. List in Descending Order\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter name: ");
                scanf(" %49[^\n]", name);

                printf("Enter phone number: ");
                scanf("%14s", phone);

                root = add(root, name, phone);
                break;

            case 2:
                printf("Enter name to remove: ");
                scanf(" %49[^\n]", name);

                temp = search(root, name);

                if (temp == NULL)
                    printf("Entry not found!\n");
                else
                {
                    root = deleteEntry(root, name);
                    printf("Entry deleted successfully!\n");
                }
                break;

            case 3:
                printf("Enter name to search: ");
                scanf(" %49[^\n]", name);

                temp = search(root, name);

                if (temp == NULL)
                    printf("Entry not found!\n");
                else
                    printf("Phone Number: %s\n", temp->phone);
                break;

            case 4:
                if (root == NULL)
                    printf("Phone book is empty!\n");
                else
                    ascending(root);
                break;

            case 5:
                if (root == NULL)
                    printf("Phone book is empty!\n");
                else
                    descending(root);
                break;

            case 6:
                printf("Exiting Phone Book.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}
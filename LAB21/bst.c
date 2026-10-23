#include <stdio.h>
#include <stdlib.h>

// Structure of a BST node
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Create a new node
struct node* createNode(int value)
{
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert a node
struct node* insert(struct node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

// Search a node
void search(struct node *root, int value)
{
    if (root == NULL)
    {
        printf("Node not found\n");
        return;
    }

    if (root->data == value)
    {
        printf("Node found\n");
    }
    else if (value < root->data)
    {
        search(root->left, value);
    }
    else
    {
        search(root->right, value);
    }
}

// Find smallest node
struct node* findMin(struct node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

// Delete a node
struct node* deleteNode(struct node *root, int value)
{
    struct node *temp;

    if (root == NULL)
    {
        printf("Node not found\n");
        return root;
    }

    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        // Node has no left child
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }

        // Node has no right child
        if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        // Node has two children
        temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Preorder: Root Left Right
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder: Left Root Right
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Postorder: Left Right Root
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Main function
int main()
{
    struct node *root = NULL;
    int choice, value;

    while (1)
    {
        printf("\n\n--- BINARY SEARCH TREE ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Preorder\n");
        printf("5. Postorder\n");
        printf("6. Inorder\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);

                root = insert(root, value);

                printf("Node inserted\n");
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);

                root = deleteNode(root, value);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);

                search(root, value);
                break;

            case 4:
                printf("Preorder: ");
                preorder(root);
                break;

            case 5:
                printf("Postorder: ");
                postorder(root);
                break;

            case 6:
                printf("Inorder: ");
                inorder(root);
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *left, *right;
};

int preIndex = 0;

struct node* createNode(char x)
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

int search(char inorder[], int start, int end, char x)
{
    int i;

    for (i = start; i <= end; i++)
    {
        if (inorder[i] == x)
            return i;
    }

    return -1;
}

struct node* buildTree(char inorder[], char preorder[],
                       int start, int end)
{
    int pos;
    struct node *root;

    if (start > end)
        return NULL;

    root = createNode(preorder[preIndex]);
    preIndex++;

    if (start == end)
        return root;

    pos = search(inorder, start, end, root->data);

    root->left = buildTree(inorder, preorder, start, pos - 1);
    root->right = buildTree(inorder, preorder, pos + 1, end);

    return root;
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

int main()
{
    char inorder[50], preorder[50];
    int n;
    struct node *root;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter Inorder traversal: ");
    scanf("%s", inorder);

    printf("Enter Preorder traversal: ");
    scanf("%s", preorder);

    preIndex = 0;

    root = buildTree(inorder, preorder, 0, n - 1);

    printf("Postorder traversal of constructed tree: ");
    postorder(root);

    return 0;
}
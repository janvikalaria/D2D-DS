#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL, *copy = NULL;
    struct node *temp, *newnode, *last = NULL;
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create original linked list
    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &value);

        newnode->data = value;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
        }
        else
        {
            last->next = newnode;
        }

        last = newnode;
    }

    // Copy linked list
    temp = head;

    while(temp != NULL)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        newnode->data = temp->data;
        newnode->next = NULL;

        if(copy == NULL)
        {
            copy = newnode;
            last = newnode;
        }
        else
        {
            last->next = newnode;
            last = newnode;
        }

        temp = temp->next;
    }

    // Display original list
    printf("\nOriginal Linked List: ");

    temp = head;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    // Display copied list
    printf("\nCopied Linked List: ");

    temp = copy;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
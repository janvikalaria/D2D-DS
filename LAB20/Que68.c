#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

void insert()
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
        newnode->prev = temp;
    }
}

void deleteAlternate()
{
    struct node *temp, *del;

    temp = head;

    while (temp != NULL && temp->next != NULL)
    {
        del = temp->next;

        temp->next = del->next;

        if (del->next != NULL)
            del->next->prev = temp;

        free(del);

        temp = temp->next;
    }
}

void display()
{
    struct node *temp = head;

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        insert();

    printf("Original list: ");
    display();

    deleteAlternate();

    printf("After deleting alternate nodes: ");
    display();

    return 0;
}
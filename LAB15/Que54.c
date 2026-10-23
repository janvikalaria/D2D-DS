#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int main()
{
    struct node *head = NULL;
    struct node *newnode, *temp;
    struct node *prev = NULL, *current, *next;
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create nexted list
    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &value);

        newnode->data = value;
        newnode->link = NULL;

        if(head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;

            while(temp->link != NULL)
            {
                temp = temp->link;
            }

            temp->link = newnode;
        }
    }

    // Reverse nexted list
    current = head;

    while(current != NULL)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }

    head = prev;

    // Display reversed list
    printf("\nReversed nexted List: ");

    temp = head;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
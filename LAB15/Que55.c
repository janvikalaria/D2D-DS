#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL;
    struct node *newnode, *temp, *p;
    int n, i, value, swap;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create linked list
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
            temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newnode;
        }
    }

    // Sort linked list
    temp = head;

    while(temp != NULL)
    {
        p = temp->next;

        while(p != NULL)
        {
            if(temp->data > p->data)
            {
                swap = temp->data;
                temp->data = p->data;
                p->data = swap;
            }

            p = p->next;
        }

        temp = temp->next;
    }

    // Display sorted list
    printf("\nSorted Linked List: ");

    temp = head;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
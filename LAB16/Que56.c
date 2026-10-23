#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

int main()
{
    struct node *first = NULL, *newnode, *temp, *del;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create linked list
    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter info: ");
        scanf("%d", &newnode->info);

        newnode->link = NULL;

        if(first == NULL)
        {
            first = newnode;
        }
        else
        {
            temp = first;

            while(temp->link != NULL)
                temp = temp->link;

            temp->link = newnode;
        }
    }

    // Remove duplicate nodes
    temp = first;

    while(temp != NULL && temp->link != NULL)
    {
        if(temp->info == temp->link->info)
        {
            del = temp->link;
            temp->link = temp->link->link;
            free(del);
        }
        else
        {
            temp = temp->link;
        }
    }

    // Display list
    printf("\nList after removing duplicates:\n");

    temp = first;

    while(temp != NULL)
    {
        printf("%d", temp->info);

        if(temp->link != NULL)
            printf(" -> ");

        temp = temp->link;
    }

    return 0;
}
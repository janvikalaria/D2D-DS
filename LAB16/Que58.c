#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

// Function to create linked list
struct node* createList()
{
    struct node *first = NULL, *newnode, *temp;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

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
            {
                temp = temp->link;
            }

            temp->link = newnode;
        }
    }

    return first;
}

// Function to remove duplicates
void removeDuplicates(struct node *first)
{
    struct node *temp, *p, *del;

    temp = first;

    while(temp != NULL)
    {
        p = temp;

        while(p->link != NULL)
        {
            if(temp->info == p->link->info)
            {
                del = p->link;

                p->link = p->link->link;

            }
            else
            {
                p = p->link;
            }
        }

        temp = temp->link;
    }
}

// Function to display linked list
void display(struct node *first)
{
    struct node *temp = first;

    while(temp != NULL)
    {
        printf("%d", temp->info);

        if(temp->link != NULL)
        {
            printf(" -> ");
        }

        temp = temp->link;
    }
}

// Main function
int main()
{
    struct node *first;

    first = createList();

    printf("\nOriginal List:\n");
    display(first);

    removeDuplicates(first);

    printf("\n\nList after removing duplicates:\n");
    display(first);

    return 0;
}
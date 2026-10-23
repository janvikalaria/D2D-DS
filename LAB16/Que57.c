#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

int main()
{
    struct node *first1 = NULL, *first2 = NULL;
    struct node *temp, *newnode;
    int n, i, same = 1;

    // Create first linked list
    printf("Enter number of nodes in first list: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter info: ");
        scanf("%d", &newnode->info);

        newnode->link = NULL;

        if(first1 == NULL)
            first1 = newnode;
        else
        {
            temp = first1;

            while(temp->link != NULL)
                temp = temp->link;

            temp->link = newnode;
        }
    }

    // Create second linked list
    printf("\nEnter number of nodes in second list: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter info: ");
        scanf("%d", &newnode->info);

        newnode->link = NULL;

        if(first2 == NULL)
            first2 = newnode;
        else
        {
            temp = first2;

            while(temp->link != NULL)
                temp = temp->link;

            temp->link = newnode;
        }
    }

    // Compare both lists
    temp = first1;
    struct node *temp2 = first2;

    while(temp != NULL && temp2 != NULL)
    {
        if(temp->info != temp2->info)
        {
            same = 0;
            break;
        }

        temp = temp->link;
        temp2 = temp2->link;
    }

    // Check if both have same number of nodes
    if(temp != NULL || temp2 != NULL)
        same = 0;

    if(same == 1)
        printf("\nBoth linked lists are same.");
    else
        printf("\nBoth linked lists are not same.");

    return 0;
}
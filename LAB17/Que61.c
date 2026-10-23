#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

/* Create linked list */
struct node* createList(int n)
{
    struct node *first = NULL, *newnode, *temp;
    int i;

    for(i = 1; i <= n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter value: ");
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

/* Swap consecutive nodes by changing links */
struct node* swapPairs(struct node *first)
{
    struct node *prev = NULL;
    struct node *a;
    struct node *b;

    while(first != NULL && first->link != NULL)
    {
        a = first;
        b = first->link;

        /* Change links */
        a->link = b->link;
        b->link = a;

        /* Connect previous pair */
        if(prev == NULL)
        {
            first = b;
        }
        else
        {
            prev->link = b;
        }

        /* Move to next pair */
        prev = a;
        first = a->link;
    }

    return first;
}

/* Display linked list */
void display(struct node *first)
{
    struct node *temp = first;

    while(temp != NULL)
    {
        printf("%d", temp->info);

        if(temp->link != NULL)
            printf(" -> ");

        temp = temp->link;
    }

    printf("\n");
}

int main()
{
    struct node *first;
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    first = createList(n);

    printf("\nOriginal List:\n");
    display(first);

    first = swapPairs(first);

    printf("\nAfter swapping consecutive nodes:\n");
    display(first);

    return 0;
}
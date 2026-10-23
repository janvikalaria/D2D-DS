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

/* Swap kth node from beginning and kth node from end */
void swapKth(struct node *first, int k, int n)
{
    struct node *p, *q;
    int i;
    int temp;

    if(k > n || k <= 0)
    {
        printf("Invalid value of K\n");
        return;
    }

    /* Find kth node from beginning */
    p = first;

    for(i = 1; i < k; i++)
    {
        p = p->link;
    }

    /* Find kth node from end */
    q = first;

    for(i = 1; i <= n - k; i++)
    {
        q = q->link;
    }

    /* Swap values */
    temp = p->info;
    p->info = q->info;
    q->info = temp;
}

int main()
{
    struct node *first;
    int n, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    first = createList(n);

    printf("\nOriginal List:\n");
    display(first);

    printf("Enter K: ");
    scanf("%d", &k);

    swapKth(first, k, n);

    printf("\nAfter swapping:\n");
    display(first);

    return 0;
}
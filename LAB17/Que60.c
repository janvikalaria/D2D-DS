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

/* Find GCD */
int gcd(int a, int b)
{
    int rem;

    while(b != 0)
    {
        rem = a % b;
        a = b;
        b = rem;
    }

    return a;
}

/* Insert GCD between every two nodes */
void insertGCD(struct node *first)
{
    struct node *temp;
    struct node *newnode;
    int g;

    temp = first;

    while(temp != NULL && temp->link != NULL)
    {
        g = gcd(temp->info, temp->link->info);

        newnode = (struct node*)malloc(sizeof(struct node));

        newnode->info = g;

        newnode->link = temp->link;

        temp->link = newnode;

        temp = newnode->link;
    }
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

    insertGCD(first);

    printf("\nAfter inserting GCD nodes:\n");
    display(first);

    return 0;
}
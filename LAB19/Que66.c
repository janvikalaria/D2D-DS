#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int power;
    struct Node *next;
};

/* Create a new node */
struct Node* createNode(int coeff, int power)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;

    return newNode;
}

/* Insert node at end */
struct Node* insert(struct Node *head, int coeff, int power)
{
    struct Node *newNode;
    struct Node *temp;

    newNode = createNode(coeff, power);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    return head;
}

/* Display polynomial */
void display(struct Node *head)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%dx^%d", temp->coeff, temp->power);

        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }

    printf("\n");
}

/* Add two polynomials */
struct Node* add(struct Node *p1, struct Node *p2)
{
    struct Node *result = NULL;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->power == p2->power)
        {
            result = insert(result,
                            p1->coeff + p2->coeff,
                            p1->power);

            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->power > p2->power)
        {
            result = insert(result,
                            p1->coeff,
                            p1->power);

            p1 = p1->next;
        }
        else
        {
            result = insert(result,
                            p2->coeff,
                            p2->power);

            p2 = p2->next;
        }
    }

    /* Remaining terms of first polynomial */
    while (p1 != NULL)
    {
        result = insert(result, p1->coeff, p1->power);
        p1 = p1->next;
    }

    /* Remaining terms of second polynomial */
    while (p2 != NULL)
    {
        result = insert(result, p2->coeff, p2->power);
        p2 = p2->next;
    }

    return result;
}

int main()
{
    struct Node *p1 = NULL;
    struct Node *p2 = NULL;
    struct Node *result = NULL;

    int n, i;
    int coeff, power;

    /* First polynomial */
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);

    printf("Enter coefficient and power:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &coeff, &power);
        p1 = insert(p1, coeff, power);
    }

    /* Second polynomial */
    printf("\nEnter number of terms in second polynomial: ");
    scanf("%d", &n);

    printf("Enter coefficient and power:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &coeff, &power);
        p2 = insert(p2, coeff, power);
    }

    printf("\nFirst Polynomial: ");
    display(p1);

    printf("Second Polynomial: ");
    display(p2);

    result = add(p1, p2);

    printf("Addition: ");
    display(result);

    return 0;
}
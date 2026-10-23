#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

/* Create a new node */
struct Node* createNode(int data)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

/* Insert node at end */
void insert(struct Node **last, int data)
{
    struct Node *newNode;

    newNode = createNode(data);

    if (*last == NULL)
    {
        *last = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = (*last)->next;
        (*last)->next = newNode;
        *last = newNode;
    }
}

/* Display circular linked list */
void display(struct Node *last)
{
    struct Node *temp;

    if (last == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = last->next;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("\n");
}

/* Split circular linked list */
void splitList(struct Node *last, struct Node **last1, struct Node **last2)
{
    struct Node *slow;
    struct Node *fast;

    slow = last->next;
    fast = last->next;

    /* Find middle */
    while (fast->next != last->next &&
           fast->next->next != last->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    /* For even number of nodes */
    if (fast->next->next == last->next)
        fast = fast->next;

    /*
       First half:
       first node to slow
    */
    *last1 = slow;

    /*
       Second half:
       slow->next to last
    */
    *last2 = last;

    /* Make second half circular */
    (*last2)->next = slow->next;

    /* Make first half circular */
    slow->next = last->next;
}

int main()
{
    struct Node *last = NULL;
    struct Node *last1 = NULL;
    struct Node *last2 = NULL;

    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        insert(&last, value);
    }

    printf("\nOriginal Circular Linked List: ");
    display(last);

    splitList(last, &last1, &last2);

    printf("First Half: ");
    display(last1);

    printf("Second Half: ");
    display(last2);

    return 0;
}
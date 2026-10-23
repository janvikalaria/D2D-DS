#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *first = NULL;

/* Insert at Front */
void insertFront()
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter info: ");
    scanf("%d", &newnode->info);

    newnode->link = first;
    first = newnode;

    printf("Node inserted at front.\n");
}

/* Insert at End */
void insertEnd()
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter info: ");
    scanf("%d", &newnode->info);

    newnode->link = NULL;

    if (first == NULL)
    {
        first = newnode;
    }
    else
    {
        temp = first;

        while (temp->link != NULL)
        {
            temp = temp->link;
        }

        temp->link = newnode;
    }

    printf("Node inserted at end.\n");
}

/* Ordered Insertion */
void orderedInsert()
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter info: ");
    scanf("%d", &newnode->info);

    newnode->link = NULL;

    if (first == NULL || newnode->info < first->info)
    {
        newnode->link = first;
        first = newnode;
    }
    else
    {
        temp = first;

        while (temp->link != NULL &&
               temp->link->info < newnode->info)
        {
            temp = temp->link;
        }

        newnode->link = temp->link;
        temp->link = newnode;
    }

    printf("Node inserted in ordered list.\n");
}

/* Display */
void display()
{
    struct node *temp;

    if (first == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = first;

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }

    printf("NULL\n");
}

/* Delete First */
void deleteFirst()
{
    struct node *temp;

    if (first == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = first;
    first = first->link;

    free(temp);

    printf("First node deleted.\n");
}

/* Delete Last */
void deleteLast()
{
    struct node *temp, *prev;

    if (first == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (first->link == NULL)
    {
        free(first);
        first = NULL;
    }
    else
    {
        temp = first;

        while (temp->link != NULL)
        {
            prev = temp;
            temp = temp->link;
        }

        prev->link = NULL;
        free(temp);
    }

    printf("Last node deleted.\n");
}

/* Delete from Position */
void deletePosition()
{
    struct node *temp, *prev;
    int pos, i;

    if (first == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        temp = first;
        first = first->link;
        free(temp);

        printf("Node deleted.\n");
        return;
    }

    temp = first;

    for (i = 1; i < pos; i++)
    {
        prev = temp;
        temp = temp->link;

        if (temp == NULL)
        {
            printf("Invalid position.\n");
            return;
        }
    }

    prev->link = temp->link;
    free(temp);

    printf("Node deleted.\n");
}

/* Count Nodes */
void countNodes()
{
    struct node *temp;
    int count = 0;

    temp = first;

    while (temp != NULL)
    {
        count++;
        temp = temp->link;
    }

    printf("Number of nodes = %d\n", count);
}

/* Main Function */
int main()
{
    int choice;
    printf("Enter choice:");
    scanf("%d",&choice);

    while (1)
    {
        printf("\n----- SINGLY LINKED LIST -----\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Ordered Insertion\n");
        printf("4. Display\n");
        printf("5. Delete First\n");
        printf("6. Delete Last\n");
        printf("7. Delete from Position\n");
        printf("8. Count Nodes\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertFront();
                break;

            case 2:
                insertEnd();
                break;

            case 3:
                orderedInsert();
                break;

            case 4:
                display();
                break;

            case 5:
                deleteFirst();
                break;

            case 6:
                deleteLast();
                break;

            case 7:
                deletePosition();
                break;

            case 8:
                countNodes();
                break;

            case 9:
                printf("Program ended.\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
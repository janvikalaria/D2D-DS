#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    int priority;
    struct node *link;
};

struct node *front = NULL;
struct node *rear = NULL;

/* SIMPLE QUEUE */

/* Enqueue */
void simpleEnqueue()
{
    struct node *newnode;
    int value;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &value);

    newnode->info = value;
    newnode->link = NULL;

    if (front == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->link = newnode;
        rear = newnode;
    }
}

/* Dequeue */
void simpleDequeue()
{
    struct node *temp;

    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        temp = front;

        printf("Deleted = %d\n", front->info);

        front = front->link;

        if (front == NULL)
            rear = NULL;

        free(temp);
    }
}

/* Display */
void simpleDisplay()
{
    struct node *temp;

    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        temp = front;

        while (temp != NULL)
        {
            printf("%d ", temp->info);
            temp = temp->link;
        }

        printf("\n");
    }
}


/* CIRCULAR QUEUE */

/* Enqueue */
void circularEnqueue()
{
    struct node *newnode;
    int value;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &value);

    newnode->info = value;

    if (front == NULL)
    {
        front = rear = newnode;
        rear->link = front;
    }
    else
    {
        newnode->link = front;
        rear->link = newnode;
        rear = newnode;
    }
}

/* Dequeue */
void circularDequeue()
{
    struct node *temp;

    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else if (front == rear)
    {
        printf("Deleted = %d\n", front->info);

        free(front);

        front = rear = NULL;
    }
    else
    {
        temp = front;

        printf("Deleted = %d\n", front->info);

        front = front->link;
        rear->link = front;

        free(temp);
    }
}

/* Display */
void circularDisplay()
{
    struct node *temp;

    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        temp = front;

        do
        {
            printf("%d ", temp->info);
            temp = temp->link;

        } while (temp != front);

        printf("\n");
    }
}


/* PRIORITY QUEUE */

/* Insert */
void priorityInsert()
{
    struct node *newnode;
    struct node *temp;
    int value, p;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &value);

    printf("Enter priority: ");
    scanf("%d", &p);

    newnode->info = value;
    newnode->priority = p;
    newnode->link = NULL;

    if (front == NULL || p < front->priority)
    {
        newnode->link = front;
        front = newnode;
    }
    else
    {
        temp = front;

        while (temp->link != NULL &&
               temp->link->priority <= p)
        {
            temp = temp->link;
        }

        newnode->link = temp->link;
        temp->link = newnode;
    }
}

/* Delete */
void priorityDelete()
{
    struct node *temp;

    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        temp = front;

        printf("Deleted = %d\n", front->info);

        front = front->link;

        free(temp);
    }
}

/* Display */
void priorityDisplay()
{
    struct node *temp;

    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        temp = front;

        printf("info\tPriority\n");

        while (temp != NULL)
        {
            printf("%d\t%d\n", temp->info, temp->priority);
            temp = temp->link;
        }
    }
}


/* MAIN */

int main()
{
    int choice, operation;

    while (1)
    {
        printf("\n============================\n");
        printf("       QUEUE MENU\n");
        printf("============================\n");

        printf("1. Simple Queue\n");
        printf("2. Circular Queue\n");
        printf("3. Priority Queue\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 4)
            break;

        /* SIMPLE QUEUE */
        if (choice == 1)
        {
            while (1)
            {
                printf("\n--- SIMPLE QUEUE ---\n");
                printf("1. Enqueue\n");
                printf("2. Dequeue\n");
                printf("3. Display\n");
                printf("4. Back\n");

                printf("Enter choice: ");
                scanf("%d", &operation);

                if (operation == 1)
                    simpleEnqueue();

                else if (operation == 2)
                    simpleDequeue();

                else if (operation == 3)
                    simpleDisplay();

                else if (operation == 4)
                    break;

                else
                    printf("Invalid choice\n");
            }
        }

        /* CIRCULAR QUEUE */
        else if (choice == 2)
        {
            /* Reset queue */
            front = NULL;
            rear = NULL;

            while (1)
            {
                printf("\n--- CIRCULAR QUEUE ---\n");
                printf("1. Enqueue\n");
                printf("2. Dequeue\n");
                printf("3. Display\n");
                printf("4. Back\n");

                printf("Enter choice: ");
                scanf("%d", &operation);

                if (operation == 1)
                    circularEnqueue();

                else if (operation == 2)
                    circularDequeue();

                else if (operation == 3)
                    circularDisplay();

                else if (operation == 4)
                    break;

                else
                    printf("Invalid choice\n");
            }
        }

        /* PRIORITY QUEUE */
        else if (choice == 3)
        {
            /* Reset queue */
            front = NULL;
            rear = NULL;

            while (1)
            {
                printf("\n--- PRIORITY QUEUE ---\n");
                printf("1. Insert\n");
                printf("2. Delete\n");
                printf("3. Display\n");
                printf("4. Back\n");

                printf("Enter choice: ");
                scanf("%d", &operation);

                if (operation == 1)
                    priorityInsert();

                else if (operation == 2)
                    priorityDelete();

                else if (operation == 3)
                    priorityDisplay();

                else if (operation == 4)
                    break;

                else
                    printf("Invalid choice\n");
            }
        }

        else
        {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
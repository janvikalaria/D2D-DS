#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *top = NULL;

// PUSH
void push()
{
    struct node *newnode;
    int value;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &value);

    newnode->info = value;
    newnode->link = top;
    top = newnode;
}

// POP
void pop()
{
    struct node *temp;

    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        temp = top;
        printf("Deleted element = %d\n", top->info);
        top = top->link;
        free(temp);
    }
}

// PEEP
void peep()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top element = %d\n", top->info);
    }
}

// CHANGE
void change()
{
    struct node *temp;
    int position, value, i;

    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Enter position from TOP: ");
    scanf("%d", &position);

    temp = top;

    for (i = 1; i < position && temp != NULL; i++)
    {
        temp = temp->link;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
    }
    else
    {
        printf("Enter new value: ");
        scanf("%d", &value);

        temp->info = value;

        printf("Value changed successfully\n");
    }
}

// DISPLAY
void display()
{
    struct node *temp;

    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        temp = top;

        printf("Stack elements are:\n");

        while (temp != NULL)
        {
            printf("%d\n", temp->info);
            temp = temp->link;
        }
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- STACK MENU ---\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEP\n");
        printf("4. CHANGE\n");
        printf("5. DISPLAY\n");
        printf("6. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peep();
                break;

            case 4:
                change();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
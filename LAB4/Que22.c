#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

// PUSH operation
void push() {
    int value;

    if (top == MAX - 1) {
        printf("Stack Overflow\\n");
        return;
    }

    printf("Enter value to push: ");
    scanf("%d", &value);

    top++;
    stack[top] = value;

    printf("%d pushed into stack\\n", value);
}

// POP operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow\\n");
        return;
    }

    printf("Popped element: %d\\n", stack[top]);
    top--;
}

// DISPLAY operation
void display() {
    int i;

    if (top == -1) {
        printf("Stack is empty\\n");
        return;
    }

    printf("Stack elements are:\\n");
    for (i = top; i >= 0; i--) {
        printf("%d\\n", stack[i]);
    }
}

// PEEP operation
void peep() {
    int pos;

    if (top == -1) {
        printf("Stack is empty\\n");
        return;
    }

    printf("Enter position from top (1 = top element): ");
    scanf("%d", &pos);

    if (pos <= 0 || pos > top + 1) {
        printf("Invalid position\\n");
        return;
    }

    printf("Element at position %d from top = %d\\n", pos, stack[top - pos + 1]);
}

// CHANGE operation
void change() {
    int pos, value;

    if (top == -1) {
        printf("Stack is empty\\n");
        return;
    }

    printf("Enter position from top to change: ");
    scanf("%d", &pos);

    if (pos <= 0 || pos > top + 1) {
        printf("Invalid position\\n");
        return;
    }

    printf("Enter new value: ");
    scanf("%d", &value);

    stack[top - pos + 1] = value;

    printf("Element changed successfully\\n");
}

int main() {
    int choice;

    do {
        printf("\\n--- STACK MENU ---\\n");
        printf("1. PUSH\\n");
        printf("2. POP\\n");
        printf("3. DISPLAY\\n");
        printf("4. PEEP\\n");
        printf("5. CHANGE\\n");
        printf("6. EXIT\\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                peep();
                break;

            case 5:
                change();
                break;

            case 6:
                printf("Exiting program...\\n");
                break;

            default:
                printf("Invalid choice\\n");
        }

    } while (choice != 6);

    return 0;
}
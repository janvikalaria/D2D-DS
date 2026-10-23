// CIRCULAR LINKED LIST

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int info;
    struct Node* link;
};

struct Node* head = NULL;//Global variable

struct Node* createNode(int info) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->info = info;
    newNode->link = NULL;
    return newNode;
}

void insertFront(int info) {
    struct Node* newNode = createNode(info);
    if (head == NULL) {
        newNode->link = newNode;
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->link != head)
        temp = temp->link;

    newNode->link = head;
    temp->link = newNode;
    head = newNode;
    printf("Node inserted at front.\n");
}

void insertEnd(int info) {
    struct Node* newNode = createNode(info);
    if (head == NULL) {
        newNode->link = newNode;
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->link != head)
        temp = temp->link;

    temp->link = newNode;
    newNode->link = head;
    printf("Node inserted at end.\n");
}

void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;
    int count = 1;

    if (pos == 1) {//delete head node
        while (temp->link != head)
            temp = temp->link;

        if (head == head->link) {
            free(head);
            head = NULL;
        } else {
            temp->link = head->link;
            free(head);
            head = temp->link;
        }
        printf("Node at position 1 deleted.\n");
        return;
    }

    temp = head;
    while (count < pos && temp->link != head) {
        prev = temp;
        temp = temp->link;
        count++;
    }

    if (count != pos || temp == head) {
        printf("Invalid position!\n");
        return;
    }

    prev->link = temp->link;
    free(temp);
    printf("Node at position %d deleted.\n", pos);
}

void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ",temp->info);
        temp = temp->link;
    } while (temp != head);
    printf("(back to head)\n");
}

int main() {
    int choice, info, pos;

    while (1) {
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert at front: ");
                scanf("%d", &info);
                insertFront(info);
                break;
            case 2:
                printf("Enter element to insert at end: ");
                scanf("%d", &info);
                insertEnd(info);
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 4:
                displayList();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
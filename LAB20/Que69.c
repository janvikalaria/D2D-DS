#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char song[50];
    struct node *prev, *next;
};

struct node *head = NULL, *current = NULL;

void addSong()
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter song name: ");
    scanf(" %[^\n]", newnode->song);

    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL)
    {
        head = newnode;
        current = newnode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
        newnode->prev = temp;
    }

    printf("Song added successfully!\n");
}

void deleteSong()
{
    struct node *temp;
    char name[50];

    if (head == NULL)
    {
        printf("Playlist is empty!\n");
        return;
    }

    printf("Enter song name to delete: ");
    scanf(" %[^\n]", name);

    temp = head;

    while (temp != NULL && strcmp(temp->song, name) != 0)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Song not found!\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (current == temp)
    {
        if (temp->next != NULL)
            current = temp->next;
        else
            current = temp->prev;
    }

    free(temp);

    printf("Song deleted successfully!\n");
}

void display()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("Playlist is empty!\n");
        return;
    }

    printf("\n--- Playlist ---\n");

    while (temp != NULL)
    {
        if (temp == current)
            printf("-> %s (Current Song)\n", temp->song);
        else
            printf("   %s\n", temp->song);

        temp = temp->next;
    }
}

void playSong()
{
    if (current == NULL)
    {
        printf("No songs to play!\n");
        return;
    }

    printf("Now playing: %s\n", current->song);
}

void nextSong()
{
    if (current == NULL)
        printf("Playlist is empty!\n");
    else if (current->next == NULL)
        printf("This is the last song!\n");
    else
    {
        current = current->next;
        playSong();
    }
}

void previousSong()
{
    if (current == NULL)
        printf("Playlist is empty!\n");
    else if (current->prev == NULL)
        printf("This is the first song!\n");
    else
    {
        current = current->prev;
        playSong();
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n\n--- MUSIC PLAYER ---");
        printf("\n1. Add Song");
        printf("\n2. Delete Song");
        printf("\n3. Display Playlist");
        printf("\n4. Play Current Song");
        printf("\n5. Next Song");
        printf("\n6. Previous Song");
        printf("\n7. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addSong();
                break;

            case 2:
                deleteSong();
                break;

            case 3:
                display();
                break;

            case 4:
                playSong();
                break;

            case 5:
                nextSong();
                break;

            case 6:
                previousSong();
                break;

            case 7:
                printf("Exiting Music Player.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 7);

    return 0;
}
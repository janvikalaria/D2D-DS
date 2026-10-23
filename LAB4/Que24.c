#include <stdio.h>
#include <string.h>

int main() {
    char str[100], stack[100];
    int top = -1, i = 0;

    printf("Enter string: ");
    scanf("%s", str);

    // Push all a's
    while (str[i] == 'a') {
        stack[++top] = 'a';
        i++;
    }

    // Pop for every b
    while (str[i] == 'b') {
        if (top == -1) {
            printf("Invalid string");
            return 0;
        }
        top--;
        i++;
    }

    // Check if stack is empty and string is fully processed
    if (str[i] == '\0' && top == -1)
        printf("Valid string (a^i b^i)");
    else
        printf("Invalid string");

    return 0;
}
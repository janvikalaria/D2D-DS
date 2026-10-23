#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push operation
void push(char ch) {
    stack[++top] = ch;
}

// Pop operation
char pop() {
    return stack[top--];
}

int main() {
    char str[MAX];
    int i, n;
    int palindrome = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    n = strlen(str);

    // Push first half of the string
    for (i = 0; i < n / 2; i++) {
        push(str[i]);
    }

    // Skip middle character if length is odd
    if (n % 2 != 0) {
        i++;
    }

    // Compare second half with stack
    while (i < n) {
        if (pop() != str[i]) {
            palindrome = 0;
            break;
        }
        i++;
    }

    if (palindrome)
        printf("The string '%s' is a palindrome.\n", str);
    else
        printf("The string '%s' is not a palindrome.\n", str);

    return 0;
}
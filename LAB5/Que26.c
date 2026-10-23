#include <stdio.h>
#include <string.h>

int main() {
    char s[1000], result[1000];
    int i, top = -1;

    scanf("%s", s);

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == '*') {
            top--;              // remove previous character
        } else {
            result[++top] = s[i];   // add character
        }
    }

    result[top + 1] = '\0';

    printf("%s\n", result);

    return 0;
}
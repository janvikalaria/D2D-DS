#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        char s[1000], stack[1000];
        int top = -1, i, ok = 1;


        scanf("%s", s);

        for (i = 0; s[i] != '\0'; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stack[++top] = s[i];
            } else {
                if (top == -1) {
                    ok = 0;
                    break;
                }

                if ((s[i] == ')' && stack[top] == '(') ||
                    (s[i] == '}' && stack[top] == '{') ||
                    (s[i] == ']' && stack[top] == '[')) {
                    top--;
                } else {
                    ok = 0;
                    break;
                }
            }
        }

        if (top != -1) ok = 0;

        printf("%d\n", ok);
    }

    return 0;
}
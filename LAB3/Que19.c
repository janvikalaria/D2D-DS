#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter number of rows: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        int num = 1;

        // Print spaces
        for(j = 0; j < n - i - 1; j++) {
            printf("  ");
        }

        // Print Pascal Triangle numbers
        for(j = 0; j <= i; j++) {
            printf("%4d", num);
            num = num * (i - j) / (j + 1);
        }

        printf("\n");
    }

    return 0;
}
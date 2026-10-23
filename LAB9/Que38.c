#include <stdio.h>

int sum(int a[], int n)
{
    if (n == 0)
        return 0;

    return a[n - 1] + sum(a, n - 1);
}

int main()
{
    int a[100], n, i;

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Sum = %d", sum(a, n));

    return 0;
}
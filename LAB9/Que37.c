#include <stdio.h>

int largest(int a[], int n)
{
    if (n == 1)
        return a[0];

    int max = largest(a, n - 1);

    if (a[n - 1] > max)
        return a[n - 1];
    else
        return max;
}

int main()
{
    int a[100], n, i;

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Largest = %d", largest(a, n));

    return 0;
}
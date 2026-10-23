#include <stdio.h>

int main()
{
    int a[100], n, sum = 0;
    int *p;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    p = a;

    printf("Enter %d numbers:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", p + i);
    }

    for (int i = 0; i < n; i++)
    {
        sum = sum + *(p + i);
    }

    printf("Sum = %d", sum);

    return 0;
}
#include <stdio.h>

int main()
{
    int a[100], n, *p, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    p = a;

    printf("Enter array elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", p + i);
    }

    // Sorting
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (*(p + j) > *(p + j + 1))
            {
                temp = *(p + j);
                *(p + j) = *(p + j + 1);
                *(p + j + 1) = temp;
            }
        }
    }

    printf("Sorted array:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(p + i));
    }

    return 0;
}
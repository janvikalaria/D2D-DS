#include <stdio.h>

int main()
{
    int a[100], n, *p, largest;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    p = a;

    printf("Enter array elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", p + i);
    }

    largest = *p;

    for (int i = 1; i < n; i++)
    {
        if (*(p + i) > largest)
        {
            largest = *(p + i);
        }
    }

    printf("Largest element = %d", largest);

    return 0;
}
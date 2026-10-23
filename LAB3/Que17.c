#include <stdio.h>

int main()
{
    int a[100], n, value, i, pos=-1;

    printf("Enter size: ");
    scanf("%d",&n);

    printf("Enter sorted array:\n");

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Enter value to delete: ");
    scanf("%d",&value);

    for(i=0;i<n;i++)
    {
        if(a[i]==value)
        {
            pos=i;
            break;
        }
    }

    if(pos==-1)
    {
        printf("Element not found");
        return 0;
    }

    for(i=pos;i<n-1;i++)
        a[i]=a[i+1];

    n--;

    printf("Array after deletion:\n");

    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}
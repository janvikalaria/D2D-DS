#include <stdio.h>

int main()
{
    int n, digit;
    int largest = 0;
    int smallest = 9;

    printf("Enter number: ");
    scanf("%d", &n);

    while(n != 0)
    {
        digit = n % 10;

        if(digit > largest)
            largest = digit;

        if(digit < smallest)
            smallest = digit;

        n /= 10;
    }

    printf("Largest digit = %d\n", largest);
    printf("Smallest digit = %d\n", smallest);

    return 0;
}
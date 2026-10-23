//A Strong Number is a number whose sum of factorials of digits equals the number itself.

#include <stdio.h>

int main()
{
    int n, temp, digit, sum = 0, i, fact;

    printf("Enter a number: ");
    scanf("%d", &n);

    temp = n;

    while(temp != 0)
    {
        digit = temp % 10;
        fact = 1;

        for(i = 1; i <= digit; i++)
            fact *= i;

        sum += fact;
        temp /= 10;
    }

    if(sum == n)
        printf("%d is a Strong Number.", n);
    else
        printf("%d is not a Strong Number.", n);

    return 0;
}
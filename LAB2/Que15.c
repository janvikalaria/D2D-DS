//A Happy Number is a number that eventually becomes 1 when replaced repeatedly by the sum of the squares of its digits.

#include <stdio.h>

int sumSquare(int n)
{
    int sum = 0, digit;
    while(n > 0)
    {
        digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

int main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    while(n != 1 && n != 4)
    {
        n = sumSquare(n);
    }

    if(n == 1)
        printf("Happy Number");
    else
        printf("Not a Happy Number");

    return 0;
}
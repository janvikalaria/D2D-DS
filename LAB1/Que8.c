//A Harshad Number is a number that is divisible by the sum of its digits.

#include <stdio.h>

int main()
{
    int n, temp, digit, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    temp = n;

    while(temp != 0)
    {
        digit = temp % 10;
        sum += digit;
        temp /= 10;
    }

    if(n % sum == 0)
        printf("%d is a Harshad Number.", n);
    else
        printf("%d is not a Harshad Number.", n);

    return 0;
}
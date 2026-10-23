//A Duck Number is a number containing at least one 0, but not as the first digit.

#include <stdio.h>

int main()
{
    int n, digit;
    int duck = 0;

    printf("Enter number: ");
    scanf("%d", &n);

    while(n != 0)
    {
        digit = n % 10;

        if(digit == 0)
        {
            duck = 1;
            break;
        }

        n /= 10;
    }

    if(duck)
        printf("Duck Number");
    else
        printf("Not a Duck Number");

    return 0;
}
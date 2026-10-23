//Two numbers are co-prime if their GCD is 1.
//15 28
#include <stdio.h>

int main()
{
    int a, b, i, gcd = 1;

    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);

    for(i = 1; i <= a && i <= b; i++)
    {
        if(a % i == 0 && b % i == 0)
            gcd = i;
    }

    if(gcd == 1)
        printf("Co-prime Numbers");
    else
        printf("Not Co-prime");

    return 0;
}
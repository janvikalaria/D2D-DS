#include <stdio.h>

int main()
{
    int n, digit;
    int freq[10] = {0};

    printf("Enter number: ");
    scanf("%d", &n);

    while(n != 0)
    {
        digit = n % 10;
        freq[digit]++;
        n /= 10;
    }

    printf("Digit Frequency:\n");

    for(int i = 0; i < 10; i++)
    {
        if(freq[i] != 0)
            printf("%d : %d\n", i, freq[i]);
    }

    return 0;
}
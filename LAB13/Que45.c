#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ip;
    char *cp;
    float *fp;

    ip = (int *)malloc(sizeof(int));
    cp = (char *)malloc(sizeof(char));
    fp = (float *)malloc(sizeof(float));

    printf("Enter an integer: ");
    scanf("%d", ip);

    printf("Enter a character: ");
    scanf(" %c", cp);

    printf("Enter a float: ");
    scanf("%f", fp);

    printf("\nInteger = %d", *ip);
    printf("\nCharacter = %c", *cp);
    printf("\nFloat = %.2f", *fp);

    free(ip);
    free(cp);
    free(fp);

    return 0;
}
#include <stdio.h>
#include <string.h>

int main()
{
    int T, N, i, top;
    char s[100], stack[100], temp[100];

    scanf("%d", &T);

    while(T--)
    {
        scanf("%d", &N);
        scanf("%s", s);

        top = -1;

        for(i = 0; i < N; i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
               s[i] == 'o' || s[i] == 'u')
            {
                // Copy stack in reverse order to temp
                int j, k = 0;

                for(j = top; j >= 0; j--)
                {
                    temp[k++] = stack[j];
                }

                // Copy temp back to stack
                for(j = 0; j < k; j++)
                {
                    stack[j] = temp[j];
                }

                top = k - 1;
            }
            else
            {
                // Push character into stack
                stack[++top] = s[i];
            }
        }

        // Put stack into string
        stack[top + 1] = '\0';

        printf("%s", stack);

        // Print remaining part of original string
        for(i = 0; i < N; i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
               s[i] == 'o' || s[i] == 'u')
            {
                printf("%c", s[i]);
            }
        }

        printf("\n");
    }

    return 0;
}
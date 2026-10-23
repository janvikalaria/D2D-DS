#include <stdio.h>

int main()
{
    int t, n, i, j, top, expected;
    int a[100], s[100];

    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &n);

        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);

        top = -1;
        expected = 1;

        for (i = 0; i < n; i++)
        {
            s[++top] = a[i];

            while (top != -1 && s[top] == expected)
            {
                top--;
                expected++;
            }
        }

        if (expected == n + 1)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
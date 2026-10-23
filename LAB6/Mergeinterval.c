#include <stdio.h>

struct Interval
{
    int start;
    int end;
};

struct Interval stack[100];
int top = -1;

void push(struct Interval x)
{
    stack[++top] = x;
}

struct Interval pop()
{
    return stack[top--];
}

int main()
{
    struct Interval a[100], temp;
    int n, i, j;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    printf("Enter intervals:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d %d", &a[i].start, &a[i].end);
    }

    // Sort intervals by start time
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(a[i].start > a[j].start)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    // Push first interval
    push(a[0]);

    // Merge intervals using stack
    for(i = 1; i < n; i++)
    {
        temp = pop();

        if(a[i].start <= temp.end)
        {
            // Overlapping
            if(a[i].end > temp.end)
                temp.end = a[i].end;

            push(temp);
        }
        else
        {
            // No overlap
            push(temp);
            push(a[i]);
        }
    }

    printf("\nMerged Intervals:\n");

    // Print stack from bottom to top
    for(i = 0; i <= top; i++)
    {
        printf("{%d, %d} ", stack[i].start, stack[i].end);
    }

    return 0;
}
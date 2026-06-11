#include <stdio.h>

int main()
{
    int start, end, i, j, isprime;

    printf("Enter the starting number:");
    scanf("%d", &start);

    printf("Enter the ending number:");
    scanf("%d", &end);

    printf("Prime number between %d and %d are:\n", start, end);

    for (i = start; i <= end; i++)
    {
        if (i <= 1)
            continue;

        isprime = 1;

        for (j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                isprime = 0;
                break;
            }
        }
        if (isprime)
            printf("%d ", i);
    }

    return 0;
}
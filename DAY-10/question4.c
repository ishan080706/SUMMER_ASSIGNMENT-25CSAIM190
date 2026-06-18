#include <stdio.h>

int main()
{
    int n = 5, i, j, k;

    for (i = 1; i <= n; i++)
    {

        for (j = 1; j <= n - i; j++)
        {
            printf(" ");
        }

        for (k = 0; k < i; k++)
        {
            printf("%c", 'A' + k);
        }

        for (k = i - 2; k >= 0; k--)
        {
            printf("%c", 'A' + k);
        }

        printf("\n");
    }

    return 0;
}
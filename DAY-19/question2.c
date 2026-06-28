#include <stdio.h>

int main()
{
    int r, c, i, j;
    int a[10][10], b[10][10], subtract[10][10];

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter elements of first matrix:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            subtract[i][j] = a[i][j] - b[i][j];
        }
    }

    printf("Difference of the matrices is:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ", subtract[i][j]);
        }
        printf("\n");
    }

    return 0;
}

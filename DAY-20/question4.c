#include <stdio.h>

int main()
{
    int rows, cols;
    int i, j;
    int matrix[10][10];
    int colSum[10];

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    if (rows <= 0 || rows > 10 || cols <= 0 || cols > 10)
    {
        printf("Please enter valid dimensions between 1 and 10.\n");
        return 1;
    }

    printf("Enter elements of the matrix:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (j = 0; j < cols; j++)
    {
        colSum[j] = 0;
        for (i = 0; i < rows; i++)
        {
            colSum[j] += matrix[i][j];
        }
    }

    printf("Column-wise sums:\n");
    for (j = 0; j < cols; j++)
    {
        printf("Sum of column %d = %d\n", j + 1, colSum[j]);
    }

    return 0;
}

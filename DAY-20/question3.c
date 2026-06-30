#include <stdio.h>

int main()
{
    int rows, cols;
    int i, j;
    int matrix[10][10];
    int rowSum[10];

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
        rowSum[i] = 0;
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
            rowSum[i] += matrix[i][j];
        }
    }

    printf("Row-wise sums:\n");
    for (i = 0; i < rows; i++)
    {
        printf("Sum of row %d = %d\n", i + 1, rowSum[i]);
    }

    return 0;
}

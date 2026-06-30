#include <stdio.h>

int main()
{
    int n, i, j;
    int matrix[10][10];
    int isSymmetric = 1;

    printf("Enter the order of the square matrix: ");
    scanf("%d", &n);

    if (n <= 0 || n > 10)
    {
        printf("Please enter a valid order between 1 and 10.\n");
        return 1;
    }

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                isSymmetric = 0;
                break;
            }
        }
        if (!isSymmetric)
            break;
    }

    if (isSymmetric)
        printf("The matrix is symmetric.\n");
    else
        printf("The matrix is not symmetric.\n");

    return 0;
}

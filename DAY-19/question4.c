#include <stdio.h>

int main() {
    int n, i, j;
    int a[10][10];
    int primarySum = 0, secondarySum = 0;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    printf("Enter elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        primarySum += a[i][i];
        secondarySum += a[i][n - i - 1];
    }

    printf("Primary diagonal sum = %d\n", primarySum);
    printf("Secondary diagonal sum = %d\n", secondarySum);
    printf("Total diagonal sum = %d\n", primarySum + secondarySum);

    return 0;
}

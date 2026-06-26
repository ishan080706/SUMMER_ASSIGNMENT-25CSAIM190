#include <stdio.h>

int main()
{
    int n, i, sum = 0, totalsum, missing;
    printf("Enter value of n:");
    scanf("%d", &n);

    int arr[n - 1];

    printf("Enter %d elements of array:", n - 1);
    for (i = 0; i < n - 1; i++)
    {

        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    totalsum = (n * (n + 1)) / 2;

    missing = totalsum - sum;

    printf("Missing number is: %d\n", missing);
    return 0;
}
#include <stdio.h>

int main()
{
    int arr[10], i;

    printf("Enter 10 elements:");

    for (i = 0; i < 10; i++)
    {

        scanf("%d", &arr[i]);
    }

    printf("Array elements are:");

    for (i = 0; i < 10; i++)
    {

        printf("%d ", arr[i]);
    }

    return 0;
}
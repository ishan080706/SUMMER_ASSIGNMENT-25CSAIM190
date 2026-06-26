#include <stdio.h>

int main()
{
    int arr[] = {8, 7, 2, 5, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 10;

    int found = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == sum)
            {
                printf("Pair found: (%d, %d)\n", arr[i], arr[j]);
                found = 1;
            }
        }
    }

    if (!found)
    {
        printf("No pair found.\n");
    }

    return 0;
}
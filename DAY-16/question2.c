#include <stdio.h>

int main()
{
    int n, i, j, maxfreq = 0, element;

    printf("Enetr the element:");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the array element:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++)
    {
        int count = 1;
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > maxfreq)
        {
            maxfreq = count;
            element = arr[i];
        }
    }

    printf("The most frequent element is: %d\n", element);
    printf("The frequency of the most frequent element is: %d\n", maxfreq);

    return 0;
}
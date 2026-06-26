#include <stdio.h>

int main()
{
    int arr1[100], arr2[100];
    int n1, n2;

    printf("Enter size of first array: ");
    scanf("%d", &n1);

    printf("Enter elements of first array: ");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &n2);

    printf("Enter elements of second array: ");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &arr2[i]);
    }

    printf("Union of arrays: ");

    // Print unique elements from first array
    for (int i = 0; i < n1; i++)
    {
        int duplicate = 0;

        for (int j = 0; j < i; j++)
        {
            if (arr1[i] == arr1[j])
            {
                duplicate = 1;
                break;
            }
        }

        if (!duplicate)
        {
            printf("%d ", arr1[i]);
        }
    }

    // Print elements from second array not present in first array
    for (int i = 0; i < n2; i++)
    {
        int found = 0;

        for (int j = 0; j < n1; j++)
        {
            if (arr2[i] == arr1[j])
            {
                found = 1;
                break;
            }
        }

        if (!found)
        {
            int duplicate = 0;

            for (int k = 0; k < i; k++)
            {
                if (arr2[i] == arr2[k])
                {
                    duplicate = 1;
                    break;
                }
            }

            if (!duplicate)
            {
                printf("%d ", arr2[i]);
            }
        }
    }

    return 0;
}
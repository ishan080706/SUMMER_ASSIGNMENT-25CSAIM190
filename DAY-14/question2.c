#include <stdio.h>

int main()
{
    int arr[100], n, i, element, frequency = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to find frequency: ");
    scanf("%d", &element);

    for (i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            frequency++;
        }
    }

    printf("Frequency of %d = %d\n", element, frequency);

    return 0;
}
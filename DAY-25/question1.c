#include <stdio.h>

int main()
{
    int a[100], b[100], merged[200];
    int n, m, i, j, k;

    printf("Enter size of first array: ");
    scanf("%d", &n);
    printf("Enter elements of first sorted array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &m);
    printf("Enter elements of second sorted array: ");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }

    i = 0;
    j = 0;
    k = 0;

    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            merged[k++] = a[i++];
        }
        else
        {
            merged[k++] = b[j++];
        }
    }

    while (i < n)
    {
        merged[k++] = a[i++];
    }

    while (j < m)
    {
        merged[k++] = b[j++];
    }

    printf("Merged array: ");
    for (i = 0; i < k; i++)
    {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}

#include <stdio.h>
#include <string.h>

int main()
{
    char names[10][50], temp[50];
    int n, i, j;

    printf("Enter number of names: ");
    scanf("%d", &n);
    getchar();

    for (i = 0; i < n; i++)
    {
        printf("Enter name %d: ", i + 1);
        gets(names[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(names[i], names[j]) > 0)
            {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }

    printf("Sorted names:\n");
    for (i = 0; i < n; i++)
    {
        puts(names[i]);
    }

    return 0;
}

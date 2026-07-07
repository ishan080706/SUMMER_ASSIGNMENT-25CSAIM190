#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i, count;

    printf("Enter a string: ");
    gets(str);

    i = 0;
    while (str[i] != '\0')
    {
        count = 1;
        while (str[i + count] == str[i])
        {
            count++;
        }

        printf("%c%d", str[i], count);
        i += count;
    }

    printf("\n");
    return 0;
}

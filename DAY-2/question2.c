#include <stdio.h>

int main()
{
    int num, reverse = 0, digit;
    printf("Enter the number:");
    scanf("%d", &num);

    while (num != 0)
    {
        digit = num % 10;
        reverse = reverse * 10 + digit;
        num = num / 10;
    }

    printf("Reversed number is = %d\n", reverse);

    return 0;
}
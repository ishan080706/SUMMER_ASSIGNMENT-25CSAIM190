#include <stdio.h>

int main()
{
    int num, digit;
    long long product = 1;
    printf("Enter the number:");

    scanf("%d", &num);

    while (num != 0)
    {
        digit = num % 10;
        product *= digit;
        num /= 10;
    }

    printf("Product of digits is = %d\n", product);

    return 0;
}
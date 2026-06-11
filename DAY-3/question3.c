#include <stdio.h>

int main()
{
    int a, b, temp;

    printf("Enter two numbers:");

    scanf("%d %d", &a, &b);

    while (b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    printf("GCD = %d\n", a);

    return 0;
}
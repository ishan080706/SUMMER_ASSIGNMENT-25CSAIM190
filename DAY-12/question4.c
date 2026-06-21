#include <stdio.h>

int isPerfect(int n)
{
    int i, sum = 0;

    for (i = 1; i <= n / 2; i++)
    {

        if (n % i == 0)

            sum += i;
    }

    return (sum == n);
}

int main()
{
    int num;

    printf("Enter a number: ");

    scanf("%d", &num);

    if (isPerfect(num))

        printf("%d is a Perfect Number.\n", num);

    else
        printf("%d is not a Perfect Number.\n", num);

    return 0;
}
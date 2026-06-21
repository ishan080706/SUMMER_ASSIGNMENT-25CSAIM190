#include <stdio.h>
#include <math.h>

int isArmstrong(int n)
{
    int original = n, sum = 0, digits = 0, temp = n;

    while (temp != 0)
    {
        digits++;
        temp /= 10;
    }

    temp = n;

    while (temp != 0)
    {
        int digit = temp % 10;

        sum += pow(digit, digits);

        temp /= 10;
    }

    return (sum == original);
}

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isArmstrong(num))

        printf("%d is an Armstrong Number.\n", num);
    else

        printf("%d is not an Armstrong Number.\n", num);

    return 0;
}
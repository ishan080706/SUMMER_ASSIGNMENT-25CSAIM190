#include <stdio.h>

int main()
{
    int num, originalNum, remainder, result = 0;
    printf("Enter the number: ");
    scanf("%d", &num);
    originalNum = num;

    while (num != 0)
    {
        remainder = num % 10;
        result += remainder * remainder * remainder;
        num /= 10;
    }
    if (result == originalNum)
    {
        printf("%d is an Armstrong number.", originalNum);
    }
    else
    {
        printf("%d is not an Armstrong number.", originalNum);
    }
    return 0;
}
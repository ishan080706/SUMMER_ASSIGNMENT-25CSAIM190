#include <stdio.h>

int main()
{
    int num, reverse = 0, digit , original;
    printf("Enter the number:");
    scanf("%d", &num);

    original = num;

    while (num != 0)
    {
        digit = num % 10;
        reverse = reverse * 10 + digit;
        num = num / 10;
    }

    if(original == reverse)
    printf("Palindrome Number\n");

    else
    printf("Not a Palindrome Number\n");


    return 0;
}
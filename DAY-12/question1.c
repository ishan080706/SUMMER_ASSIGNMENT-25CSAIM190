#include <stdio.h>

int isPalindrome(int n)
{
    int original = n, reverse = 0, digit;

    while (n > 0)
    {
        digit = n % 10;
        reverse = reverse * 10 + digit;
        n /= 10;
    }

    return (original == reverse);
}

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPalindrome(num))

        printf("%d is a Palindrome Number.\n", num);

    else
    
        printf("%d is not a Palindrome Number.\n", num);

    return 0;
}
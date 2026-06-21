#include <stdio.h>

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    int a = 0, b = 1, c, i;

    for (i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main()
{
    int n, i;

    printf("Enter the number of terms: ");

    scanf("%d", &n);

    printf("Fibonacci Series: ");

    for (i = 0; i < n; i++)
    {

        printf("%d ", fibonacci(i));
    }

    return 0;
}
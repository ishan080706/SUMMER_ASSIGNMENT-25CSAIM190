#include <stdio.h>

int main()
{
    int n1, n2, n3, num;
    n1 = 0;
    n2 = 1;
    printf("Enter the number of terms: ");

    scanf("%d", &num);

    printf("Fibonacci Series: ");

    for (int i = 0; i < num; i++)
    {
        printf("%d ", n1);

        n3 = n1 + n2;
        
        n1 = n2;
        n2 = n3;

    }
    return 0;
}
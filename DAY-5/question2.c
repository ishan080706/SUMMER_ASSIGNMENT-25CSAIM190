#include<stdio.h>

int main(){
    int n , temp , rem , sum = 0 , fact , i;

    printf("Enter  the number:");
    scanf("%d" , &n);

    temp=n;

    while (temp > 0)
    {
        rem = temp % 10;
        fact = 1;

        for (i = 1; i <= rem; i++)
        {
            fact *= i;
        }

        sum += fact;
        temp /= 10;
    }
    if (sum == n)
    {
        printf("%d is a strong number", n);
    }
    else
    {
        printf("%d is not a strong number", n);
    }
    
    return 0;
}
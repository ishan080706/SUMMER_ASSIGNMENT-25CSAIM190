#include<stdio.h>

int main(){
    int N;
    long long sum;
    
    printf("Enter number:");
    scanf("%d", &N);

    sum = (long long)N * (N + 1) / 2;
    printf("Sum of first %d natural numbers is = %lld\n",N,sum);

        return 0;
}
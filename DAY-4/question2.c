#include<stdio.h>

int main(){
     int n1, n2, n3, num;
    n1 = 0;
    n2 = 1;
    printf("Enter the number of terms: ");

    scanf("%d", &num);

    if(num == 0)
    {
        printf(" %d Fibonnacci Series is %d:", num, n1);
    }
    else if(num == 1)
    {
        printf(" %d Fibonnacci Series is %d:", num, n2);
    }
    else
    {

        for (int i = 2; i < num; i++)
        {
        
            n3 = n1 + n2;
            
            n1 = n2;
            n2 = n3;

        }
        printf(" %d Fibonnacci Series is %d:", num, n2);
    }

    return 0;
}
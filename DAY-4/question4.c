#include <stdio.h>

int main() {
    int start, end, num, temp, remainder, sum;

    printf("Enter starting number: ");
    scanf("%d", &start);

    printf("Enter ending number: ");
    scanf("%d", &end);

    printf("Armstrong numbers between %d and %d are:\n", start, end);

    for (num = start; num <= end; num++) {
        temp = num;
        sum = 0;

        while (temp != 0) {
            remainder = temp % 10;
            sum += remainder * remainder * remainder;
            temp /= 10;
        }

        if (sum == num)
            printf("%d ", num);
    }

    return 0;
}
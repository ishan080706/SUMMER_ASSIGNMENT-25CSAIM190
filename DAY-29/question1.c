#include <stdio.h>

int main() {
    int choice;
    float a, b, result;

    printf("Menu-Driven Calculator\n");
    printf("====================\n");

    while (1) {
        printf("\n1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("\nExiting calculator.\n");
            break;
        }

        printf("Enter first number: ");
        scanf("%f", &a);
        printf("Enter second number: ");
        scanf("%f", &b);

        switch (choice) {
            case 1:
                result = a + b;
                printf("\nResult: %.2f\n", result);
                break;
            case 2:
                result = a - b;
                printf("\nResult: %.2f\n", result);
                break;
            case 3:
                result = a * b;
                printf("\nResult: %.2f\n", result);
                break;
            case 4:
                if (b == 0) {
                    printf("\nError: Division by zero is not allowed.\n");
                } else {
                    result = a / b;
                    printf("\nResult: %.2f\n", result);
                }
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}

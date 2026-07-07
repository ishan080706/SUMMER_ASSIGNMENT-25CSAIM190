#include <stdio.h>

int main() {
    int choice;
    float balance = 1000.0, amount;

    printf("Welcome to the ATM\n");
    printf("1. Check Balance\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Current balance: %.2f\n", balance);
                break;
            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                balance += amount;
                printf("Deposit successful. New balance: %.2f\n", balance);
                break;
            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                if (amount > balance) {
                    printf("Insufficient balance.\n");
                } else {
                    balance -= amount;
                    printf("Withdrawal successful. New balance: %.2f\n", balance);
                }
                break;
            case 4:
                printf("Thank you for using the ATM.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

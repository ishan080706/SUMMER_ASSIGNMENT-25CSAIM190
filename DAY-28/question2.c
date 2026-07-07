#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int accountNo;
    char name[50];
    float balance;
} BankAccount;

void addAccount(BankAccount accounts[], int *count) {
    if (*count >= MAX) {
        printf("\nAccount list is full. Cannot add more accounts.\n");
        return;
    }

    BankAccount a;
    printf("\nEnter Account Number: ");
    scanf("%d", &a.accountNo);
    printf("Enter Name: ");
    scanf("%s", a.name);
    printf("Enter Initial Balance: ");
    scanf("%f", &a.balance);

    accounts[*count] = a;
    (*count)++;
    printf("\nAccount created successfully.\n");
}

void displayAccounts(BankAccount accounts[], int count) {
    if (count == 0) {
        printf("\nNo accounts found.\n");
        return;
    }

    printf("\nBank Accounts:\n");
    printf("----------------------------------------\n");
    printf("Acc No | Name           | Balance\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-7d | %-14s | %.2f\n", accounts[i].accountNo, accounts[i].name, accounts[i].balance);
    }
}

void searchAccount(BankAccount accounts[], int count) {
    int accNo;
    int found = 0;

    printf("\nEnter Account Number to search: ");
    scanf("%d", &accNo);

    for (int i = 0; i < count; i++) {
        if (accounts[i].accountNo == accNo) {
            printf("\nAccount found!\n");
            printf("Account Number: %d\n", accounts[i].accountNo);
            printf("Name: %s\n", accounts[i].name);
            printf("Balance: %.2f\n", accounts[i].balance);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nAccount with number %d not found.\n", accNo);
    }
}

void depositMoney(BankAccount accounts[], int count) {
    int accNo;
    float amount;
    int found = 0;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    for (int i = 0; i < count; i++) {
        if (accounts[i].accountNo == accNo) {
            accounts[i].balance += amount;
            printf("\nDeposit successful. New balance: %.2f\n", accounts[i].balance);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nAccount with number %d not found.\n", accNo);
    }
}

void withdrawMoney(BankAccount accounts[], int count) {
    int accNo;
    float amount;
    int found = 0;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    for (int i = 0; i < count; i++) {
        if (accounts[i].accountNo == accNo) {
            if (amount > accounts[i].balance) {
                printf("\nInsufficient balance.\n");
            } else {
                accounts[i].balance -= amount;
                printf("\nWithdrawal successful. New balance: %.2f\n", accounts[i].balance);
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nAccount with number %d not found.\n", accNo);
    }
}

int main() {
    BankAccount accounts[MAX];
    int count = 0;
    int choice;

    printf("Bank Account System\n");
    printf("==================\n");

    while (1) {
        printf("\n1. Create Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Search Account\n");
        printf("4. Deposit Money\n");
        printf("5. Withdraw Money\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAccount(accounts, &count);
                break;
            case 2:
                displayAccounts(accounts, count);
                break;
            case 3:
                searchAccount(accounts, count);
                break;
            case 4:
                depositMoney(accounts, count);
                break;
            case 5:
                withdrawMoney(accounts, count);
                break;
            case 6:
                printf("\nExiting program.\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <string.h>

#define MAX 100

struct Employee {
    int empId;
    char name[50];
    float salary;
};

int main() {
    struct Employee employees[MAX];
    int n = 0, choice;

    printf("Mini Employee Management System\n");
    printf("===============================\n");

    while (1) {
        printf("\n1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (n >= MAX) {
                    printf("\nEmployee list is full.\n");
                } else {
                    printf("Enter Employee ID: ");
                    scanf("%d", &employees[n].empId);
                    printf("Enter Name: ");
                    scanf("%s", employees[n].name);
                    printf("Enter Salary: ");
                    scanf("%f", &employees[n].salary);
                    n++;
                    printf("\nEmployee added successfully.\n");
                }
                break;

            case 2:
                if (n == 0) {
                    printf("\nNo employees found.\n");
                } else {
                    printf("\nEmployee Records:\n");
                    for (int i = 0; i < n; i++) {
                        printf("Employee ID: %d\n", employees[i].empId);
                        printf("Name: %s\n", employees[i].name);
                        printf("Salary: %.2f\n\n", employees[i].salary);
                    }
                }
                break;

            case 3:
                if (n == 0) {
                    printf("\nNo employees found.\n");
                } else {
                    int id;
                    int found = 0;
                    printf("Enter employee ID to search: ");
                    scanf("%d", &id);
                    for (int i = 0; i < n; i++) {
                        if (employees[i].empId == id) {
                            printf("\nEmployee found!\n");
                            printf("Employee ID: %d\n", employees[i].empId);
                            printf("Name: %s\n", employees[i].name);
                            printf("Salary: %.2f\n", employees[i].salary);
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("\nEmployee not found.\n");
                    }
                }
                break;

            case 4:
                printf("\nExiting program.\n");
                return 0;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}

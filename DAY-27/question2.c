#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int empId;
    char name[50];
    float salary;
} Employee;

void addEmployee(Employee employees[], int *count) {
    if (*count >= MAX) {
        printf("\nEmployee list is full. Cannot add more employees.\n");
        return;
    }

    Employee e;
    printf("\nEnter Employee ID: ");
    scanf("%d", &e.empId);
    printf("Enter Name: ");
    scanf("%s", e.name);
    printf("Enter Salary: ");
    scanf("%f", &e.salary);

    employees[*count] = e;
    (*count)++;
    printf("\nEmployee record added successfully.\n");
}

void displayEmployees(Employee employees[], int count) {
    if (count == 0) {
        printf("\nNo employee records found.\n");
        return;
    }

    printf("\nEmployee Records:\n");
    printf("----------------------------------------\n");
    printf("Emp ID | Name           | Salary\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-7d | %-14s | %.2f\n", employees[i].empId, employees[i].name, employees[i].salary);
    }
}

void searchEmployee(Employee employees[], int count) {
    int id;
    int found = 0;

    printf("\nEnter employee ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
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
        printf("\nEmployee with ID %d not found.\n", id);
    }
}

void updateEmployee(Employee employees[], int count) {
    int id;
    int found = 0;

    printf("\nEnter employee ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (employees[i].empId == id) {
            printf("Enter new name: ");
            scanf("%s", employees[i].name);
            printf("Enter new salary: ");
            scanf("%f", &employees[i].salary);
            printf("\nEmployee record updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", id);
    }
}

void deleteEmployee(Employee employees[], int count) {
    int id;
    int found = 0;

    printf("\nEnter employee ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (employees[i].empId == id) {
            for (int j = i; j < count - 1; j++) {
                employees[j] = employees[j + 1];
            }
            found = 1;
            printf("\nEmployee record deleted successfully.\n");
            return;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", id);
    }
}

int main() {
    Employee employees[MAX];
    int count = 0;
    int choice;

    printf("Employee Management System\n");
    printf("=========================\n");

    while (1) {
        printf("\n1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(employees, &count);
                break;
            case 2:
                displayEmployees(employees, count);
                break;
            case 3:
                searchEmployee(employees, count);
                break;
            case 4:
                updateEmployee(employees, count);
                break;
            case 5:
                deleteEmployee(employees, count);
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

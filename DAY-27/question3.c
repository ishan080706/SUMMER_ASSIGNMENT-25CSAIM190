#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int empId;
    char name[50];
    float basicSalary;
    float hra;
    float da;
    float grossSalary;
} EmployeeSalary;

void calculateGrossSalary(EmployeeSalary *e) {
    e->grossSalary = e->basicSalary + e->hra + e->da;
}

void addEmployeeSalary(EmployeeSalary employees[], int *count) {
    if (*count >= MAX) {
        printf("\nSalary list is full. Cannot add more employees.\n");
        return;
    }

    EmployeeSalary e;
    printf("\nEnter Employee ID: ");
    scanf("%d", &e.empId);
    printf("Enter Name: ");
    scanf("%s", e.name);
    printf("Enter Basic Salary: ");
    scanf("%f", &e.basicSalary);
    printf("Enter HRA: ");
    scanf("%f", &e.hra);
    printf("Enter DA: ");
    scanf("%f", &e.da);

    calculateGrossSalary(&e);
    employees[*count] = e;
    (*count)++;
    printf("\nEmployee salary record added successfully.\n");
}

void displaySalaryRecords(EmployeeSalary employees[], int count) {
    if (count == 0) {
        printf("\nNo salary records found.\n");
        return;
    }

    printf("\nSalary Records:\n");
    printf("--------------------------------------------------------\n");
    printf("Emp ID | Name           | Basic   | HRA    | DA    | Gross\n");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-7d | %-14s | %-7.2f | %-6.2f | %-6.2f | %-6.2f\n",
               employees[i].empId,
               employees[i].name,
               employees[i].basicSalary,
               employees[i].hra,
               employees[i].da,
               employees[i].grossSalary);
    }
}

void searchSalaryRecord(EmployeeSalary employees[], int count) {
    int id;
    int found = 0;

    printf("\nEnter employee ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (employees[i].empId == id) {
            printf("\nSalary record found!\n");
            printf("Employee ID: %d\n", employees[i].empId);
            printf("Name: %s\n", employees[i].name);
            printf("Basic Salary: %.2f\n", employees[i].basicSalary);
            printf("HRA: %.2f\n", employees[i].hra);
            printf("DA: %.2f\n", employees[i].da);
            printf("Gross Salary: %.2f\n", employees[i].grossSalary);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", id);
    }
}

void updateSalaryRecord(EmployeeSalary employees[], int count) {
    int id;
    int found = 0;

    printf("\nEnter employee ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (employees[i].empId == id) {
            printf("Enter new name: ");
            scanf("%s", employees[i].name);
            printf("Enter new basic salary: ");
            scanf("%f", &employees[i].basicSalary);
            printf("Enter new HRA: ");
            scanf("%f", &employees[i].hra);
            printf("Enter new DA: ");
            scanf("%f", &employees[i].da);
            calculateGrossSalary(&employees[i]);
            printf("\nSalary record updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", id);
    }
}

void deleteSalaryRecord(EmployeeSalary employees[], int count) {
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
            printf("\nSalary record deleted successfully.\n");
            return;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", id);
    }
}

int main() {
    EmployeeSalary employees[MAX];
    int count = 0;
    int choice;

    printf("Salary Management System\n");
    printf("========================\n");

    while (1) {
        printf("\n1. Add Salary Record\n");
        printf("2. Display All Salary Records\n");
        printf("3. Search Salary Record\n");
        printf("4. Update Salary Record\n");
        printf("5. Delete Salary Record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployeeSalary(employees, &count);
                break;
            case 2:
                displaySalaryRecords(employees, count);
                break;
            case 3:
                searchSalaryRecord(employees, count);
                break;
            case 4:
                updateSalaryRecord(employees, count);
                break;
            case 5:
                deleteSalaryRecord(employees, count);
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

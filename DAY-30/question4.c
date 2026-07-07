#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

void addStudent(struct Student students[], int *n) {
    if (*n >= MAX) {
        printf("\nStudent list is full.\n");
        return;
    }

    printf("Enter Roll Number: ");
    scanf("%d", &students[*n].rollNo);
    printf("Enter Name: ");
    scanf("%s", students[*n].name);
    printf("Enter Marks: ");
    scanf("%f", &students[*n].marks);
    (*n)++;
    printf("\nStudent added successfully.\n");
}

void displayStudents(struct Student students[], int n) {
    if (n == 0) {
        printf("\nNo students found.\n");
        return;
    }

    printf("\nStudent Records:\n");
    for (int i = 0; i < n; i++) {
        printf("Roll No: %d\n", students[i].rollNo);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n\n", students[i].marks);
    }
}

void searchStudent(struct Student students[], int n) {
    int roll;
    int found = 0;

    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < n; i++) {
        if (students[i].rollNo == roll) {
            printf("\nStudent found!\n");
            printf("Roll No: %d\n", students[i].rollNo);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent not found.\n");
    }
}

int main() {
    struct Student students[MAX];
    int n = 0, choice;

    printf("Mini Project: Student Management System\n");
    printf("=====================================\n");

    while (1) {
        printf("\n1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &n);
                break;
            case 2:
                displayStudents(students, n);
                break;
            case 3:
                searchStudent(students, n);
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

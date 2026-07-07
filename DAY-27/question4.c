#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int rollNo;
    char name[50];
    float marks[5];
    float total;
    float percentage;
} StudentMarks;

void calculateResult(StudentMarks *s) {
    s->total = 0;
    for (int i = 0; i < 5; i++) {
        s->total += s->marks[i];
    }
    s->percentage = (s->total / 500) * 100;
}

void addStudentMarks(StudentMarks students[], int *count) {
    if (*count >= MAX) {
        printf("\nMarks list is full. Cannot add more students.\n");
        return;
    }

    StudentMarks s;
    printf("\nEnter Roll Number: ");
    scanf("%d", &s.rollNo);
    printf("Enter Name: ");
    scanf("%s", s.name);

    printf("Enter 5 subject marks:\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%f", &s.marks[i]);
    }

    calculateResult(&s);
    students[*count] = s;
    (*count)++;
    printf("\nMarksheet added successfully.\n");
}

void displayMarksheet(StudentMarks students[], int count) {
    if (count == 0) {
        printf("\nNo marksheet records found.\n");
        return;
    }

    printf("\nMarksheet Records:\n");
    printf("--------------------------------------------------------------\n");
    printf("Roll | Name           | Sub1 | Sub2 | Sub3 | Sub4 | Sub5 | Total | Percentage\n");
    printf("--------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-5d | %-14s | %-5.1f | %-5.1f | %-5.1f | %-5.1f | %-5.1f | %-6.1f | %-10.2f\n",
               students[i].rollNo,
               students[i].name,
               students[i].marks[0],
               students[i].marks[1],
               students[i].marks[2],
               students[i].marks[3],
               students[i].marks[4],
               students[i].total,
               students[i].percentage);
    }
}

void searchMarksheet(StudentMarks students[], int count) {
    int roll;
    int found = 0;

    printf("\nEnter roll number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == roll) {
            printf("\nMarksheet found!\n");
            printf("Roll Number: %d\n", students[i].rollNo);
            printf("Name: %s\n", students[i].name);
            for (int j = 0; j < 5; j++) {
                printf("Subject %d: %.1f\n", j + 1, students[i].marks[j]);
            }
            printf("Total: %.1f\n", students[i].total);
            printf("Percentage: %.2f\n", students[i].percentage);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent with roll number %d not found.\n", roll);
    }
}

int main() {
    StudentMarks students[MAX];
    int count = 0;
    int choice;

    printf("Marksheet Generation System\n");
    printf("==========================\n");

    while (1) {
        printf("\n1. Add Student Marksheet\n");
        printf("2. Display All Marksheets\n");
        printf("3. Search Marksheet\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudentMarks(students, &count);
                break;
            case 2:
                displayMarksheet(students, count);
                break;
            case 3:
                searchMarksheet(students, count);
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

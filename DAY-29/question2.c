#include <stdio.h>

#define MAX 100

int main() {
    int arr[MAX];
    int n = 0, choice, value, pos, i;

    printf("Menu-Driven Array Operations\n");
    printf("===========================\n");

    while (1) {
        printf("\n1. Insert Element\n");
        printf("2. Display Array\n");
        printf("3. Search Element\n");
        printf("4. Delete Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (n >= MAX) {
                    printf("\nArray is full.\n");
                } else {
                    printf("Enter value to insert: ");
                    scanf("%d", &value);
                    arr[n] = value;
                    n++;
                    printf("\nElement inserted successfully.\n");
                }
                break;

            case 2:
                if (n == 0) {
                    printf("\nArray is empty.\n");
                } else {
                    printf("\nArray elements: ");
                    for (i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;

            case 3:
                if (n == 0) {
                    printf("\nArray is empty.\n");
                } else {
                    printf("Enter value to search: ");
                    scanf("%d", &value);
                    for (i = 0; i < n; i++) {
                        if (arr[i] == value) {
                            printf("\nValue found at index %d.\n", i);
                            break;
                        }
                    }
                    if (i == n) {
                        printf("\nValue not found.\n");
                    }
                }
                break;

            case 4:
                if (n == 0) {
                    printf("\nArray is empty.\n");
                } else {
                    printf("Enter value to delete: ");
                    scanf("%d", &value);
                    for (i = 0; i < n; i++) {
                        if (arr[i] == value) {
                            for (pos = i; pos < n - 1; pos++) {
                                arr[pos] = arr[pos + 1];
                            }
                            n--;
                            printf("\nElement deleted successfully.\n");
                            break;
                        }
                    }
                    if (i == n) {
                        printf("\nValue not found.\n");
                    }
                }
                break;

            case 5:
                printf("\nExiting program.\n");
                return 0;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}

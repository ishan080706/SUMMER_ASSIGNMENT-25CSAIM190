#include <stdio.h>
#include <string.h>

#define MAX 100

struct Book {
    int bookId;
    char title[50];
    char author[50];
};

int main() {
    struct Book books[MAX];
    int n = 0, choice;

    printf("Mini Library System\n");
    printf("==================\n");

    while (1) {
        printf("\n1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (n >= MAX) {
                    printf("\nLibrary is full.\n");
                } else {
                    printf("Enter Book ID: ");
                    scanf("%d", &books[n].bookId);
                    printf("Enter Title: ");
                    scanf("%s", books[n].title);
                    printf("Enter Author: ");
                    scanf("%s", books[n].author);
                    n++;
                    printf("\nBook added successfully.\n");
                }
                break;

            case 2:
                if (n == 0) {
                    printf("\nNo books found.\n");
                } else {
                    printf("\nBooks in Library:\n");
                    for (int i = 0; i < n; i++) {
                        printf("Book ID: %d\n", books[i].bookId);
                        printf("Title: %s\n", books[i].title);
                        printf("Author: %s\n\n", books[i].author);
                    }
                }
                break;

            case 3:
                if (n == 0) {
                    printf("\nNo books found.\n");
                } else {
                    int id;
                    int found = 0;
                    printf("Enter book ID to search: ");
                    scanf("%d", &id);
                    for (int i = 0; i < n; i++) {
                        if (books[i].bookId == id) {
                            printf("\nBook found!\n");
                            printf("Book ID: %d\n", books[i].bookId);
                            printf("Title: %s\n", books[i].title);
                            printf("Author: %s\n", books[i].author);
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("\nBook not found.\n");
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

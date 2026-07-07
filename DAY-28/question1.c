#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int bookId;
    char title[50];
    char author[50];
    int quantity;
} Book;

void addBook(Book books[], int *count) {
    if (*count >= MAX) {
        printf("\nLibrary is full. Cannot add more books.\n");
        return;
    }

    Book b;
    printf("\nEnter Book ID: ");
    scanf("%d", &b.bookId);
    printf("Enter Title: ");
    scanf("%s", b.title);
    printf("Enter Author: ");
    scanf("%s", b.author);
    printf("Enter Quantity: ");
    scanf("%d", &b.quantity);

    books[*count] = b;
    (*count)++;
    printf("\nBook added successfully.\n");
}

void displayBooks(Book books[], int count) {
    if (count == 0) {
        printf("\nNo books found.\n");
        return;
    }

    printf("\nLibrary Books:\n");
    printf("----------------------------------------\n");
    printf("Book ID | Title          | Author        | Qty\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-7d | %-14s | %-13s | %-3d\n",
               books[i].bookId,
               books[i].title,
               books[i].author,
               books[i].quantity);
    }
}

void searchBook(Book books[], int count) {
    int id;
    int found = 0;

    printf("\nEnter Book ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].bookId == id) {
            printf("\nBook found!\n");
            printf("Book ID: %d\n", books[i].bookId);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Quantity: %d\n", books[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nBook with ID %d not found.\n", id);
    }
}

void updateBook(Book books[], int count) {
    int id;
    int found = 0;

    printf("\nEnter Book ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].bookId == id) {
            printf("Enter new title: ");
            scanf("%s", books[i].title);
            printf("Enter new author: ");
            scanf("%s", books[i].author);
            printf("Enter new quantity: ");
            scanf("%d", &books[i].quantity);
            printf("\nBook updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nBook with ID %d not found.\n", id);
    }
}

void deleteBook(Book books[], int count) {
    int id;
    int found = 0;

    printf("\nEnter Book ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].bookId == id) {
            for (int j = i; j < count - 1; j++) {
                books[j] = books[j + 1];
            }
            found = 1;
            printf("\nBook deleted successfully.\n");
            return;
        }
    }

    if (!found) {
        printf("\nBook with ID %d not found.\n", id);
    }
}

int main() {
    Book books[MAX];
    int count = 0;
    int choice;

    printf("Library Management System\n");
    printf("========================\n");

    while (1) {
        printf("\n1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Update Book\n");
        printf("5. Delete Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(books, &count);
                break;
            case 2:
                displayBooks(books, count);
                break;
            case 3:
                searchBook(books, count);
                break;
            case 4:
                updateBook(books, count);
                break;
            case 5:
                deleteBook(books, count);
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

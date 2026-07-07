#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int contactId;
    char name[50];
    char phone[15];
    char email[50];
} Contact;

void addContact(Contact contacts[], int *count) {
    if (*count >= MAX) {
        printf("\nContact list is full. Cannot add more contacts.\n");
        return;
    }

    Contact c;
    printf("\nEnter Contact ID: ");
    scanf("%d", &c.contactId);
    printf("Enter Name: ");
    scanf("%s", c.name);
    printf("Enter Phone Number: ");
    scanf("%s", c.phone);
    printf("Enter Email: ");
    scanf("%s", c.email);

    contacts[*count] = c;
    (*count)++;
    printf("\nContact added successfully.\n");
}

void displayContacts(Contact contacts[], int count) {
    if (count == 0) {
        printf("\nNo contacts found.\n");
        return;
    }

    printf("\nContact List:\n");
    printf("--------------------------------------------\n");
    printf("ID | Name           | Phone        | Email\n");
    printf("--------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-2d | %-14s | %-12s | %-20s\n",
               contacts[i].contactId,
               contacts[i].name,
               contacts[i].phone,
               contacts[i].email);
    }
}

void searchContact(Contact contacts[], int count) {
    int id;
    int found = 0;

    printf("\nEnter Contact ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (contacts[i].contactId == id) {
            printf("\nContact found!\n");
            printf("Contact ID: %d\n", contacts[i].contactId);
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nContact with ID %d not found.\n", id);
    }
}

void updateContact(Contact contacts[], int count) {
    int id;
    int found = 0;

    printf("\nEnter Contact ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (contacts[i].contactId == id) {
            printf("Enter new name: ");
            scanf("%s", contacts[i].name);
            printf("Enter new phone number: ");
            scanf("%s", contacts[i].phone);
            printf("Enter new email: ");
            scanf("%s", contacts[i].email);
            printf("\nContact updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nContact with ID %d not found.\n", id);
    }
}

void deleteContact(Contact contacts[], int count) {
    int id;
    int found = 0;

    printf("\nEnter Contact ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (contacts[i].contactId == id) {
            for (int j = i; j < count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            found = 1;
            printf("\nContact deleted successfully.\n");
            return;
        }
    }

    if (!found) {
        printf("\nContact with ID %d not found.\n", id);
    }
}

int main() {
    Contact contacts[MAX];
    int count = 0;
    int choice;

    printf("Contact Management System\n");
    printf("========================\n");

    while (1) {
        printf("\n1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Update Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &count);
                break;
            case 2:
                displayContacts(contacts, count);
                break;
            case 3:
                searchContact(contacts, count);
                break;
            case 4:
                updateContact(contacts, count);
                break;
            case 5:
                deleteContact(contacts, count);
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

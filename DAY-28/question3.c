#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int ticketId;
    char passengerName[50];
    int seats;
    float price;
} Ticket;

void bookTicket(Ticket tickets[], int *count) {
    if (*count >= MAX) {
        printf("\nTicket list is full. Cannot book more tickets.\n");
        return;
    }

    Ticket t;
    printf("\nEnter Ticket ID: ");
    scanf("%d", &t.ticketId);
    printf("Enter Passenger Name: ");
    scanf("%s", t.passengerName);
    printf("Enter Number of Seats: ");
    scanf("%d", &t.seats);
    printf("Enter Ticket Price: ");
    scanf("%f", &t.price);

    tickets[*count] = t;
    (*count)++;
    printf("\nTicket booked successfully.\n");
}

void displayTickets(Ticket tickets[], int count) {
    if (count == 0) {
        printf("\nNo tickets booked.\n");
        return;
    }

    printf("\nBooked Tickets:\n");
    printf("----------------------------------------\n");
    printf("Ticket ID | Passenger       | Seats | Price\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-9d | %-15s | %-5d | %.2f\n",
               tickets[i].ticketId,
               tickets[i].passengerName,
               tickets[i].seats,
               tickets[i].price);
    }
}

void cancelTicket(Ticket tickets[], int count) {
    int id;
    int found = 0;

    printf("\nEnter Ticket ID to cancel: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (tickets[i].ticketId == id) {
            for (int j = i; j < count - 1; j++) {
                tickets[j] = tickets[j + 1];
            }
            found = 1;
            printf("\nTicket cancelled successfully.\n");
            return;
        }
    }

    if (!found) {
        printf("\nTicket with ID %d not found.\n", id);
    }
}

int main() {
    Ticket tickets[MAX];
    int count = 0;
    int choice;

    printf("Ticket Booking System\n");
    printf("====================\n");

    while (1) {
        printf("\n1. Book Ticket\n");
        printf("2. Display All Tickets\n");
        printf("3. Cancel Ticket\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookTicket(tickets, &count);
                break;
            case 2:
                displayTickets(tickets, count);
                break;
            case 3:
                cancelTicket(tickets, count);
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

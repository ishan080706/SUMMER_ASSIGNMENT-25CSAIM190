#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int productId;
    char name[50];
    int quantity;
    float price;
} Product;

void addProduct(Product products[], int *count) {
    if (*count >= MAX) {
        printf("\nInventory is full. Cannot add more products.\n");
        return;
    }

    Product p;
    printf("\nEnter Product ID: ");
    scanf("%d", &p.productId);
    printf("Enter Product Name: ");
    scanf("%s", p.name);
    printf("Enter Quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter Price: ");
    scanf("%f", &p.price);

    products[*count] = p;
    (*count)++;
    printf("\nProduct added successfully.\n");
}

void displayProducts(Product products[], int count) {
    if (count == 0) {
        printf("\nNo products found.\n");
        return;
    }

    printf("\nInventory Products:\n");
    printf("----------------------------------------------\n");
    printf("ID | Name           | Quantity | Price\n");
    printf("----------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-2d | %-14s | %-8d | %.2f\n",
               products[i].productId,
               products[i].name,
               products[i].quantity,
               products[i].price);
    }
}

void searchProduct(Product products[], int count) {
    int id;
    int found = 0;

    printf("\nEnter Product ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (products[i].productId == id) {
            printf("\nProduct found!\n");
            printf("Product ID: %d\n", products[i].productId);
            printf("Name: %s\n", products[i].name);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price: %.2f\n", products[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nProduct with ID %d not found.\n", id);
    }
}

void updateProduct(Product products[], int count) {
    int id;
    int found = 0;

    printf("\nEnter Product ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (products[i].productId == id) {
            printf("Enter new name: ");
            scanf("%s", products[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &products[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &products[i].price);
            printf("\nProduct updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nProduct with ID %d not found.\n", id);
    }
}

void deleteProduct(Product products[], int count) {
    int id;
    int found = 0;

    printf("\nEnter Product ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (products[i].productId == id) {
            for (int j = i; j < count - 1; j++) {
                products[j] = products[j + 1];
            }
            found = 1;
            printf("\nProduct deleted successfully.\n");
            return;
        }
    }

    if (!found) {
        printf("\nProduct with ID %d not found.\n", id);
    }
}

int main() {
    Product products[MAX];
    int count = 0;
    int choice;

    printf("Inventory Management System\n");
    printf("==========================\n");

    while (1) {
        printf("\n1. Add Product\n");
        printf("2. Display All Products\n");
        printf("3. Search Product\n");
        printf("4. Update Product\n");
        printf("5. Delete Product\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(products, &count);
                break;
            case 2:
                displayProducts(products, count);
                break;
            case 3:
                searchProduct(products, count);
                break;
            case 4:
                updateProduct(products, count);
                break;
            case 5:
                deleteProduct(products, count);
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

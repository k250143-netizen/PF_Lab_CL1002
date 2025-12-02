#include <stdio.h>
#include <string.h>

struct Item {
    char name[50];
    char category[30];
    int quantity;
};

void displayItems(struct Item *items, int count) {
    printf("\n--- Inventory List ---\n");
    for(int i=0; i<count; i++) {
        printf("Name: %s, Category: %s, Qty: %d\n", (items+i)->name, (items+i)->category, (items+i)->quantity);
    }
}

void searchByCategory(struct Item *items, int count, char *searchCat) {
    printf("\n--- Items in Category: %s ---\n", searchCat);
    int found = 0;
    for(int i=0; i<count; i++) {
        if(strcmp((items+i)->category, searchCat) == 0) {
            printf("%s - %d\n", (items+i)->name, (items+i)->quantity);
            found = 1;
        }
    }
    if(!found) printf("No items found.\n");
}

int main() {
    struct Item inventory[100];
    int n, choice;
    
    printf("Enter number of items: ");
    scanf("%d", &n);
    
    struct Item *ptr = inventory;
    
    for(int i=0; i<n; i++) {
        printf("\nEnter item %d details:\n", i+1);
        printf("Name: ");
        scanf("%s", (ptr+i)->name);
        printf("Category: ");
        scanf("%s", (ptr+i)->category);
        printf("Quantity: ");
        scanf("%d", &(ptr+i)->quantity);
    }
    
    while(1) {
        printf("\n1. Show All Items\n2. Search by Category\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        if(choice == 1) {
            displayItems(inventory, n);
        }
        else if(choice == 2) {
            char cat[30];
            printf("Enter category to search: ");
            scanf("%s", cat);
            searchByCategory(inventory, n, cat);
        }
        else {
            break;
        }
    }
    
    return 0;
}

#include <stdio.h>
#include <string.h>

struct Gift {
    char name[50];
    char type[30];
    float price;
    int quantity;
};

int main() {
    struct Gift gifts[100];
    int count = 0;
    int choice;
    
    while(1) {
        printf("\n1. Add Gift\n2. Find Expensive Gifts\n3. Check Quantity\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        if(choice == 1) {
            printf("Enter gift name: ");
            scanf("%s", gifts[count].name);
            printf("Enter type: ");
            scanf("%s", gifts[count].type);
            printf("Enter price: ");
            scanf("%f", &gifts[count].price);
            printf("Enter quantity: ");
            scanf("%d", &gifts[count].quantity);
            count++;
    }
            else if(choice == 2) {
                float limit;
                printf("Enter price limit: ");
                scanf("%f", &limit);
                printf("\nGifts more expensive than %.2f:\n", limit);
                for(int i=0; i<count; i++) {
                    if(gifts[i].price > limit) {
                        printf("%s - %.2f\n", gifts[i].name, gifts[i].price);
                }
            }
        }
        else if(choice == 3) {
            int qty;
            printf("Enter minimum quantity: ");
            scanf("%d", &qty);
            printf("\nGifts with quantity more than %d:\n", qty);
            for(int i=0; i<count; i++) {
                if(gifts[i].quantity > qty) {
                    printf("%s - %d available\n", gifts[i].name, gifts[i].quantity);
                }
            }
        }
        else if(choice == 4) {
            break;
        }
    }
    
    return 0;
}

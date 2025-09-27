#include <stdio.h>
int main() {
    int choice;
    int book;
    int magazine;
    printf("Library Management System\n");
    printf("1. Manage Books\n");
    printf("2. Manage Magazines\n");
    printf("Enter your choice (1-2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("----Books Menu------\n");
            printf("1. Issue Book\n");
            printf("2. Return Book\n");
            printf("3. View Books\n");
            printf("Enter your choice (1-3): ");
            scanf("%d", &book);
            switch (book)
            {
            case 1:
                printf("Issuing Book...\n");
                break;
            case 2:
                printf("Returning Book...\n");
                break;
            case 3:
                printf("Viewing Books...\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option (1-3).\n");
                break;
            }
            break;
        case 2:
            printf("----Magazines Menu------\n");
            printf("1. Issue Magazine\n");
            printf("2. Return Magazine\n"); 
            printf("3. View Magazines\n");
            printf("Enter your choice (1-3): ");
            scanf("%d", &magazine);
            switch (magazine)
            {
            case 1:
                printf("Issuing Magazine...\n");
                break;
            case 2:
                printf("Returning Magazine...\n");
                break;
            case 3:
                printf("Viewing Magazines...\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option (1-3).\n");
                break;
            }
            break;
        default:
            printf("Invalid choice. Please select a valid option (1-2).\n");
            break;
        }

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEVELS 50
#define MAX_DESC_LENGTH 100

int countWords(char *str) {
    int count = 0;
    int inWord = 0;
    
    while (*str) {
        if (*str == ' ' || *str == '\t' || *str == '\n') {
            inWord = 0;
        } else if (inWord == 0) {
            inWord = 1;
            count++;
        }
        str++;
    }
    return count;
}

int readLevels(char levels[][MAX_DESC_LENGTH]) {
    FILE *file = fopen("levels.txt", "r");
    int count = 0;
    
    if (file == NULL) {
        printf("No saved levels found. Starting fresh!\n");
        return 0;
    }
    
    while (fgets(levels[count], MAX_DESC_LENGTH, file) && count < MAX_LEVELS) {
        levels[count][strcspn(levels[count], "\n")] = 0;
        count++;
    }
    
    fclose(file);
    return count;
}

void saveLevels(char levels[][MAX_DESC_LENGTH], int count) {
    FILE *file = fopen("levels.txt", "w");
    
    if (file == NULL) {
        printf("Error saving levels!\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n", levels[i]);
    }
    
    fclose(file);
    printf("Levels saved successfully!\n");
}

int addLevel(char levels[][MAX_DESC_LENGTH], int count) {
    if (count >= MAX_LEVELS) {
        printf("Maximum levels reached!\n");
        return count;
    }
    
    char description[MAX_DESC_LENGTH];
    
    printf("Enter level description (max 7 words): ");
    getchar(); 
    fgets(description, MAX_DESC_LENGTH, stdin);
    description[strcspn(description, "\n")] = 0;
    
    int wordCount = countWords(description);
    if (wordCount > 7) {
        printf("Error: Description must be 7 words or less (you entered %d words)!\n", wordCount);
        return count;
    }
    
    if (wordCount == 0) {
        printf("Error: Description cannot be empty!\n");
        return count;
    }
    
    strcpy(levels[count], description);
    printf("Level added successfully! (%d words)\n", wordCount);
    return count + 1;
}


void searchLevel(char levels[][MAX_DESC_LENGTH], int count) {
    char searchTerm[MAX_DESC_LENGTH];
    int found = 0;
    
    printf("Enter level name/keyword to search: ");
    getchar();
    fgets(searchTerm, MAX_DESC_LENGTH, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0;
    
    printf("\n=== Search Results ===\n");
    for (int i = 0; i < count; i++) {
        if (strstr(levels[i], searchTerm) != NULL) {
            printf("%d. %s\n", i + 1, levels[i]);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No matching levels found!\n");
    }
    printf("====================\n");
}

void updateLevel(char levels[][MAX_DESC_LENGTH], int count) {
    int levelNum;
    char newDescription[MAX_DESC_LENGTH];
    
    printf("Enter level number to update (1-%d): ", count);
    scanf("%d", &levelNum);
    
    if (levelNum < 1 || levelNum > count) {
        printf("Invalid level number!\n");
        return;
    }
    
    printf("Current description: %s\n", levels[levelNum - 1]);
    printf("Enter new description (max 7 words): ");
    getchar();
    fgets(newDescription, MAX_DESC_LENGTH, stdin);
    newDescription[strcspn(newDescription, "\n")] = 0;

    int wordCount = countWords(newDescription);
    if (wordCount > 7) {
        printf("Error: Description must be 7 words or less (you entered %d words)!\n", wordCount);
        return;
    }
    
    if (wordCount == 0) {
        printf("Error: Description cannot be empty!\n");
        return;
    }
    
    strcpy(levels[levelNum - 1], newDescription);
    printf("Level updated successfully!\n");
}

int deleteLevel(char levels[][MAX_DESC_LENGTH], int count) {
    int levelNum;
    
    printf("Enter level number to delete (1-%d): ", count);
    scanf("%d", &levelNum);
    
    if (levelNum < 1 || levelNum > count) {
        printf("Invalid level number!\n");
        return count;
    }
    
    printf("Deleting: %s\n", levels[levelNum - 1]);
    
    for (int i = levelNum - 1; i < count - 1; i++) {
        strcpy(levels[i], levels[i + 1]);
    }
    
    printf("Level deleted successfully!\n");
    return count - 1;
}

void displayLevels(char levels[][MAX_DESC_LENGTH], int count) {
    if (count == 0) {
        printf("\nNo levels completed yet!\n");
        return;
    }
    
    printf("\n=== Recently Completed Levels (%d) ===\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, levels[i]);
    }
    printf("=====================================\n");
}

int main() {
    char levels[MAX_LEVELS][MAX_DESC_LENGTH];
    int levelCount = 0;
    int choice;
    
    levelCount = readLevels(levels);
    printf("Loaded %d completed levels.\n\n", levelCount);
    
    while (1) {
        printf("\n--- Game Levels Tracker ---\n");
        printf("1. Add New Level\n");
        printf("2. Search Level\n");
        printf("3. Update Level\n");
        printf("4. Delete Level\n");
        printf("5. Display All Levels\n");
        printf("0. Exit and Save\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            break;
        }
        
        switch (choice) {
            case 1:
                levelCount = addLevel(levels, levelCount);
                break;
            case 2:
                searchLevel(levels, levelCount);
                break;
            case 3:
                updateLevel(levels, levelCount);
                break;
            case 4:
                levelCount = deleteLevel(levels, levelCount);
                break;
            case 5:
                displayLevels(levels, levelCount);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    printf("\n=== Final Levels List ===\n");
    displayLevels(levels, levelCount);
    saveLevels(levels, levelCount);
    
    printf("\nThank you for playing!\n");
    
    return 0;
}
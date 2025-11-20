#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_AFFIRMATIONS 100
#define MAX_AFFIRMATION_LENGTH 100
#define MAX_WORDS 7

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

void toLowerCase(char *str, char *result) {
    int i = 0;
    while (str[i]) {
        result[i] = tolower(str[i]);
        i++;
    }
    result[i] = '\0';
}

int loadAffirmations(char affirmations[][MAX_AFFIRMATION_LENGTH]) {
    FILE *file = fopen("affirm.txt", "r");
    int count = 0;
    
    if (file == NULL) {
        printf("No existing affirmations found. Starting fresh!\n");
        return 0;
    }
    
    while (fgets(affirmations[count], MAX_AFFIRMATION_LENGTH, file) && count < MAX_AFFIRMATIONS) {
        affirmations[count][strcspn(affirmations[count], "\n")] = 0;
        if (strlen(affirmations[count]) > 0) {
            count++;
        }
    }
    
    fclose(file);
    return count;
}

void saveAffirmations(char affirmations[][MAX_AFFIRMATION_LENGTH], int count) {
    FILE *file = fopen("affirm.txt", "w");
    
    if (file == NULL) {
        printf("Error saving affirmations!\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n", affirmations[i]);
    }
    
    fclose(file);
    printf("Affirmations saved successfully!\n");
}

int addAffirmation(char affirmations[][MAX_AFFIRMATION_LENGTH], int count) {
    if (count >= MAX_AFFIRMATIONS) {
        printf("Maximum affirmations reached!\n");
        return count;
    }
    
    char newAffirmation[MAX_AFFIRMATION_LENGTH];
    
    printf("Enter new affirmation (max %d words): ", MAX_WORDS);
    getchar();
    fgets(newAffirmation, MAX_AFFIRMATION_LENGTH, stdin);
    newAffirmation[strcspn(newAffirmation, "\n")] = 0;
    

    if (strlen(newAffirmation) == 0) {
        printf("Affirmation cannot be empty!\n");
        return count;
    }

    int wordCount = countWords(newAffirmation);
    if (wordCount > MAX_WORDS) {
        printf("Error: Affirmation must be %d words or less (you entered %d words)!\n", MAX_WORDS, wordCount);
        return count;
    }
    
    strcpy(affirmations[count], newAffirmation);
    printf("Affirmation added successfully! (%d words)\n", wordCount);
    return count + 1;
}

int deleteAffirmation(char affirmations[][MAX_AFFIRMATION_LENGTH], int count) {
    int affirmNum;
    
    if (count == 0) {
        printf("No affirmations to delete!\n");
        return count;
    }
    
    printf("Enter affirmation number to delete (1-%d): ", count);
    scanf("%d", &affirmNum);
    
    if (affirmNum < 1 || affirmNum > count) {
        printf("Invalid affirmation number!\n");
        return count;
    }
    
    printf("Deleting: %s\n", affirmations[affirmNum - 1]);

    for (int i = affirmNum - 1; i < count - 1; i++) {
        strcpy(affirmations[i], affirmations[i + 1]);
    }
    
    printf("Affirmation deleted successfully!\n");
    return count - 1;
}

void updateAffirmation(char affirmations[][MAX_AFFIRMATION_LENGTH], int count) {
    int affirmNum;
    char updatedAffirmation[MAX_AFFIRMATION_LENGTH];
    
    if (count == 0) {
        printf("No affirmations to update!\n");
        return;
    }
    
    printf("Enter affirmation number to update (1-%d): ", count);
    scanf("%d", &affirmNum);
    
    if (affirmNum < 1 || affirmNum > count) {
        printf("Invalid affirmation number!\n");
        return;
    }
    
    printf("Current affirmation: %s\n", affirmations[affirmNum - 1]);
    printf("Enter new affirmation (max %d words): ", MAX_WORDS);
    getchar();
    fgets(updatedAffirmation, MAX_AFFIRMATION_LENGTH, stdin);
    updatedAffirmation[strcspn(updatedAffirmation, "\n")] = 0;
    
    if (strlen(updatedAffirmation) == 0) {
        printf("Affirmation cannot be empty!\n");
        return;
    }

    int wordCount = countWords(updatedAffirmation);
    if (wordCount > MAX_WORDS) {
        printf("Error: Affirmation must be %d words or less (you entered %d words)!\n", MAX_WORDS, wordCount);
        return;
    }
    
    strcpy(affirmations[affirmNum - 1], updatedAffirmation);
    printf("Affirmation updated successfully!\n");
}

void searchAffirmation(char affirmations[][MAX_AFFIRMATION_LENGTH], int count) {
    char searchPhrase[MAX_AFFIRMATION_LENGTH];
    char lowerSearch[MAX_AFFIRMATION_LENGTH];
    char lowerAffirmation[MAX_AFFIRMATION_LENGTH];
    int found = 0;
    
    if (count == 0) {
        printf("No affirmations to search!\n");
        return;
    }
    
    printf("Enter phrase to search: ");
    getchar();
    fgets(searchPhrase, MAX_AFFIRMATION_LENGTH, stdin);
    searchPhrase[strcspn(searchPhrase, "\n")] = 0;
    
    toLowerCase(searchPhrase, lowerSearch);
    
    printf("\n=== Search Results ===\n");
    for (int i = 0; i < count; i++) {
        toLowerCase(affirmations[i], lowerAffirmation);
        if (strstr(lowerAffirmation, lowerSearch) != NULL) {
            printf("%d. %s\n", i + 1, affirmations[i]);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No matching affirmations found!\n");
    }
    printf("=====================\n");
}

void displayAffirmations(char affirmations[][MAX_AFFIRMATION_LENGTH], int count) {
    if (count == 0) {
        printf("\nNo affirmations yet. Add some positive thoughts!\n");
        return;
    }
    
    printf("\n=== Your Daily Affirmations (%d) ===\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, affirmations[i]);
    }
    printf("====================================\n");
}

int main() {
    char affirmations[MAX_AFFIRMATIONS][MAX_AFFIRMATION_LENGTH];
    int affirmCount = 0;
    int choice;

    affirmCount = loadAffirmations(affirmations);
    printf("Welcome to your Wellness Affirmation Manager!\n");
    printf("Loaded %d affirmations.\n\n", affirmCount);
    
    while (1) {
        printf("\n--- Daily Affirmations Menu ---\n");
        printf("1. Add New Affirmation\n");
        printf("2. Delete Affirmation\n");
        printf("3. Update Affirmation\n");
        printf("4. Search Affirmations\n");
        printf("5. Display All Affirmations\n");
        printf("0. Exit and Save\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            break;
        }
        
        switch (choice) {
            case 1:
                affirmCount = addAffirmation(affirmations, affirmCount);
                break;
            case 2:
                affirmCount = deleteAffirmation(affirmations, affirmCount);
                break;
            case 3:
                updateAffirmation(affirmations, affirmCount);
                break;
            case 4:
                searchAffirmation(affirmations, affirmCount);
                break;
            case 5:
                displayAffirmations(affirmations, affirmCount);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    printf("\n=== Your Final Affirmations ===\n");
    displayAffirmations(affirmations, affirmCount);
    saveAffirmations(affirmations, affirmCount);
    
    printf("\nStay positive and keep affirming!\n");
    
    return 0;
}
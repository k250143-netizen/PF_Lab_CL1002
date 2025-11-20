#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_RECIPES 40
#define MAX_NAME_LENGTH 100

void toLowerCase(char *str, char *result) {
    int i = 0;
    while (str[i]) {
        result[i] = tolower(str[i]);
        i++;
    }
    result[i] = '\0';
}

int readRecipes(char recipes[][MAX_NAME_LENGTH]) {
    FILE *file = fopen("recipes.txt", "r");
    int count = 0;

    if (file == NULL) {
        printf("No existing recipes found. Starting fresh!\n");
        return 0;
    }

    while (fgets(recipes[count], MAX_NAME_LENGTH, file) && count < MAX_RECIPES) {
        recipes[count][strcspn(recipes[count], "\n")] = 0;
        if (strlen(recipes[count]) > 0)
            count++;
    }

    fclose(file);
    return count;
}

void saveRecipes(char recipes[][MAX_NAME_LENGTH], int count) {
    FILE *file = fopen("recipes.txt", "w");

    if (file == NULL) {
        printf("Error saving recipes!\n");
        return;
    }

    for (int i = 0; i < count; i++)
        fprintf(file, "%s\n", recipes[i]);

    fclose(file);
    printf("Recipes saved successfully!\n");
}

int addRecipe(char recipes[][MAX_NAME_LENGTH], int count) {
    if (count >= MAX_RECIPES) {
        printf("Recipe book is full! Maximum %d allowed.\n", MAX_RECIPES);
        return count;
    }

    printf("Enter recipe name: ");
    getchar();
    fgets(recipes[count], MAX_NAME_LENGTH, stdin);
    recipes[count][strcspn(recipes[count], "\n")] = 0;

    if (strlen(recipes[count]) == 0) {
        printf("Recipe name cannot be empty!\n");
        return count;
    }

    printf("Recipe '%s' added successfully!\n", recipes[count]);
    return count + 1;
}

void searchRecipe(char recipes[][MAX_NAME_LENGTH], int count) {
    char searchTerm[MAX_NAME_LENGTH];
    char lowerSearch[MAX_NAME_LENGTH];
    char lowerRecipe[MAX_NAME_LENGTH];
    int found = 0;

    printf("Enter recipe name or keyword to search: ");
    getchar();
    fgets(searchTerm, MAX_NAME_LENGTH, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0;

    toLowerCase(searchTerm, lowerSearch);

    printf("\n=== Search Results ===\n");
    for (int i = 0; i < count; i++) {
        toLowerCase(recipes[i], lowerRecipe);
        if (strstr(lowerRecipe, lowerSearch)) {
            printf("%d. %s\n", i + 1, recipes[i]);
            found = 1;
        }
    }

    if (!found)
        printf("No matching recipes found!\n");

    printf("======================\n");
}

void modifyRecipe(char recipes[][MAX_NAME_LENGTH], int count) {
    int recipeNum;
    char newName[MAX_NAME_LENGTH];

    if (count == 0) {
        printf("No recipes to modify!\n");
        return;
    }

    printf("Enter recipe number to modify (1-%d): ", count);
    scanf("%d", &recipeNum);

    if (recipeNum < 1 || recipeNum > count) {
        printf("Invalid recipe number!\n");
        return;
    }

    printf("Current name: %s\n", recipes[recipeNum - 1]);
    printf("Enter new recipe name: ");
    getchar();
    fgets(newName, MAX_NAME_LENGTH, stdin);
    newName[strcspn(newName, "\n")] = 0;

    if (strlen(newName) == 0) {
        printf("Recipe name cannot be empty!\n");
        return;
    }

    strcpy(recipes[recipeNum - 1], newName);
    printf("Recipe modified successfully!\n");
}

int removeRecipe(char recipes[][MAX_NAME_LENGTH], int count) {
    int recipeNum;

    if (count == 0) {
        printf("No recipes to remove!\n");
        return count;
    }

    printf("Enter recipe number to remove (1-%d): ", count);
    scanf("%d", &recipeNum);

    if (recipeNum < 1 || recipeNum > count) {
        printf("Invalid recipe number!\n");
        return count;
    }

    printf("Removing: %s\n", recipes[recipeNum - 1]);

    for (int i = recipeNum - 1; i < count - 1; i++)
        strcpy(recipes[i], recipes[i + 1]);

    printf("Recipe removed successfully!\n");
    return count - 1;
}

void sortRecipes(char recipes[][MAX_NAME_LENGTH], int count) {
    char temp[MAX_NAME_LENGTH];

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcasecmp(recipes[j], recipes[j + 1]) > 0) {
                strcpy(temp, recipes[j]);
                strcpy(recipes[j], recipes[j + 1]);
                strcpy(recipes[j + 1], temp);
            }
        }
    }
}

void displayRecipes(char recipes[][MAX_NAME_LENGTH], int count) {
    if (count == 0) {
        printf("\nNo recipes in your collection!\n");
        return;
    }

    printf("\n=== Your Recipe Collection (%d recipes) ===\n", count);
    for (int i = 0; i < count; i++)
        printf("%d. %s\n", i + 1, recipes[i]);

    printf("==========================================\n");
}

int main() {
    char recipes[MAX_RECIPES][MAX_NAME_LENGTH];
    int recipeCount = 0;
    int choice;

    recipeCount = readRecipes(recipes);
    printf("Loaded %d recipes from your collection.\n\n", recipeCount);

    while (1) {
        printf("\n--- Cooking Recipe Manager ---\n");
        printf("1. Add New Recipe\n");
        printf("2. Search Recipe\n");
        printf("3. Modify Recipe\n");
        printf("4. Remove Recipe\n");
        printf("5. Display All Recipes\n");
        printf("-1. Exit (Sort & Save)\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == -1)
            break;

        switch (choice) {
            case 1: recipeCount = addRecipe(recipes, recipeCount); break;
            case 2: searchRecipe(recipes, recipeCount); break;
            case 3: modifyRecipe(recipes, recipeCount); break;
            case 4: recipeCount = removeRecipe(recipes, recipeCount); break;
            case 5: displayRecipes(recipes, recipeCount); break;
            default: printf("Invalid choice! Try again.\n");
        }
    }

    sortRecipes(recipes, recipeCount);
    printf("\nRecipes sorted alphabetically.\n");

    displayRecipes(recipes, recipeCount);

    saveRecipes(recipes, recipeCount);

    printf("\nHappy cooking! Your recipes are saved.\n");

    return 0;
}

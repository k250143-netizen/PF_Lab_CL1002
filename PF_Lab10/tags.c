#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_TAGS 100
#define MAX_TAG_LENGTH 100
#define MIN_WORDS 5
#define MAX_WORDS 7

int countWordsPtr(char *str) {
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

void toLowerPtr(char *str, char *result) {
    while (*str) {
        *result = tolower(*str);
        str++;
        result++;
    }
    *result = '\0';
}

int compareStringsPtr(char *str1, char *str2) {
    while (*str1 && *str2) {
        if (tolower(*str1) != tolower(*str2)) {
            return tolower(*str1) - tolower(*str2);
        }
        str1++;
        str2++;
    }
    return tolower(*str1) - tolower(*str2);
}

void copyStringPtr(char *dest, char *src) {
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int stringLengthPtr(char *str) {
    int len = 0;
    while (*str) {
        len++;
        str++;
    }
    return len;
}

int loadTags(char tags[][MAX_TAG_LENGTH]) {
    FILE *file = fopen("tags.txt", "r");
    int count = 0;
    
    if (file == NULL) {
        printf("No existing tags found. Starting fresh!\n");
        return 0;
    }
    
    while (fgets(tags[count], MAX_TAG_LENGTH, file) && count < MAX_TAGS) {
        char *newline = strchr(tags[count], '\n');
        if (newline) {
            *newline = '\0';
        }
        
        if (stringLengthPtr(tags[count]) > 0) {
            count++;
        }
    }
    
    fclose(file);
    return count;
}

void saveTags(char tags[][MAX_TAG_LENGTH], int count) {
    FILE *file = fopen("tags.txt", "w");
    
    if (file == NULL) {
        printf("Error saving tags!\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        char *tagPtr = tags[i];
        while (*tagPtr) {
            fputc(*tagPtr, file);
            tagPtr++;
        }
        fputc('\n', file);
    }
    
    fclose(file);
    printf("Tags saved successfully!\n");
}

int addTag(char tags[][MAX_TAG_LENGTH], int count) {
    if (count >= MAX_TAGS) {
        printf("Maximum tags reached!\n");
        return count;
    }
    
    char newTag[MAX_TAG_LENGTH];
    
    printf("Enter new photo tag (%d-%d words): ", MIN_WORDS, MAX_WORDS);
    getchar(); 
    fgets(newTag, MAX_TAG_LENGTH, stdin);

    char *newline = strchr(newTag, '\n');
    if (newline) {
        *newline = '\0';
    }

    if (stringLengthPtr(newTag) == 0) {
        printf("Tag cannot be empty!\n");
        return count;
    }

    int wordCount = countWordsPtr(newTag);
    if (wordCount < MIN_WORDS || wordCount > MAX_WORDS) {
        printf("Error: Tag must be between %d and %d words (you entered %d words)!\n", 
               MIN_WORDS, MAX_WORDS, wordCount);
        return count;
    }

    copyStringPtr(tags[count], newTag);
    printf("Tag added successfully! (%d words)\n", wordCount);
    return count + 1;
}

int deleteTag(char tags[][MAX_TAG_LENGTH], int count) {
    int tagNum;
    
    if (count == 0) {
        printf("No tags to delete!\n");
        return count;
    }
    
    printf("Enter tag number to delete (1-%d): ", count);
    scanf("%d", &tagNum);
    
    if (tagNum < 1 || tagNum > count) {
        printf("Invalid tag number!\n");
        return count;
    }
    
    printf("Deleting: %s\n", tags[tagNum - 1]);

    for (int i = tagNum - 1; i < count - 1; i++) {
        copyStringPtr(tags[i], tags[i + 1]);
    }
    
    printf("Tag deleted successfully!\n");
    return count - 1;
}

void updateTag(char tags[][MAX_TAG_LENGTH], int count) {
    int tagNum;
    char updatedTag[MAX_TAG_LENGTH];
    
    if (count == 0) {
        printf("No tags to update!\n");
        return;
    }
    
    printf("Enter tag number to update (1-%d): ", count);
    scanf("%d", &tagNum);
    
    if (tagNum < 1 || tagNum > count) {
        printf("Invalid tag number!\n");
        return;
    }
    
    printf("Current tag: %s\n", tags[tagNum - 1]);
    printf("Enter new tag (%d-%d words): ", MIN_WORDS, MAX_WORDS);
    getchar();
    fgets(updatedTag, MAX_TAG_LENGTH, stdin);

    char *newline = strchr(updatedTag, '\n');
    if (newline) {
        *newline = '\0';
    }

    if (stringLengthPtr(updatedTag) == 0) {
        printf("Tag cannot be empty!\n");
        return;
    }
    
    int wordCount = countWordsPtr(updatedTag);
    if (wordCount < MIN_WORDS || wordCount > MAX_WORDS) {
        printf("Error: Tag must be between %d and %d words (you entered %d words)!\n", 
               MIN_WORDS, MAX_WORDS, wordCount);
        return;
    }

    copyStringPtr(tags[tagNum - 1], updatedTag);
    printf("Tag updated successfully!\n");
}

void searchTag(char tags[][MAX_TAG_LENGTH], int count) {
    char searchPhrase[MAX_TAG_LENGTH];
    char lowerSearch[MAX_TAG_LENGTH];
    char lowerTag[MAX_TAG_LENGTH];
    int found = 0;
    
    if (count == 0) {
        printf("No tags to search!\n");
        return;
    }
    
    printf("Enter keyword to search: ");
    getchar();
    fgets(searchPhrase, MAX_TAG_LENGTH, stdin);
    
    char *newline = strchr(searchPhrase, '\n');
    if (newline) {
        *newline = '\0';
    }
    
    toLowerPtr(searchPhrase, lowerSearch);
    
    printf("\n=== Search Results ===\n");
    for (int i = 0; i < count; i++) {
        toLowerPtr(tags[i], lowerTag);

        char *result = strstr(lowerTag, lowerSearch);
        if (result != NULL) {
            printf("%d. %s\n", i + 1, tags[i]);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No matching tags found!\n");
    }
    printf("=====================\n");
}

void displayTags(char tags[][MAX_TAG_LENGTH], int count) {
    if (count == 0) {
        printf("\nNo photo tags yet!\n");
        return;
    }
    
    printf("\n=== Photo Tags Collection (%d tags) ===\n", count);
    for (int i = 0; i < count; i++) {
        char *tagPtr = tags[i];
        printf("%d. ", i + 1);
        while (*tagPtr) {
            putchar(*tagPtr);
            tagPtr++;
        }
        printf("\n");
    }
    printf("=======================================\n");
}

int countTags(char tags[][MAX_TAG_LENGTH], int maxCount) {
    int count = 0;
    for (int i = 0; i < maxCount; i++) {
        if (stringLengthPtr(tags[i]) > 0) {
            count++;
        }
    }
    return count;
}

int main() {
    char tags[MAX_TAGS][MAX_TAG_LENGTH];
    int tagCount = 0;
    int choice;
    
    for (int i = 0; i < MAX_TAGS; i++) {
        tags[i][0] = '\0';
    }
    
    tagCount = loadTags(tags);
    printf("Welcome to Photo Tag Manager!\n");
    printf("Loaded %d photo tags.\n\n", tagCount);
    
    while (1) {
        printf("\n--- Photo Tag Menu ---\n");
        printf("1. Add New Tag\n");
        printf("2. Delete Tag\n");
        printf("3. Update Tag\n");
        printf("4. Search Tags\n");
        printf("5. Display All Tags\n");
        printf("0. Exit and Save\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            break;
        }
        
        switch (choice) {
            case 1:
                tagCount = addTag(tags, tagCount);
                break;
            case 2:
                tagCount = deleteTag(tags, tagCount);
                break;
            case 3:
                updateTag(tags, tagCount);
                break;
            case 4:
                searchTag(tags, tagCount);
                break;
            case 5:
                displayTags(tags, tagCount);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    printf("\n=== Final Photo Tags ===\n");
    displayTags(tags, tagCount);
    saveTags(tags, tagCount);
    
    printf("\nThank you for using Photo Tag Manager! 📸\n");
    
    return 0;
}
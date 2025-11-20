#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_NOTES 100
#define MAX_NOTE_LENGTH 150

int strLenPtr(char *str) {
    char *start = str;
    while (*str) {
        str++;
    }
    return str - start;
}

void strCopyPtr(char *dest, char *src) {
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
}

void convertLowerPtr(char *str, char *result) {
    while (*str) {
        *result++ = tolower(*str++);
    }
    *result = '\0';
}

int compareIgnoreCasePtr(char *str1, char *str2) {
    while (*str1 && *str2) {
        char c1 = tolower(*str1);
        char c2 = tolower(*str2);
        if (c1 != c2) {
            return c1 - c2;
        }
        str1++;
        str2++;
    }
    return tolower(*str1) - tolower(*str2);
}

int containsSubstringPtr(char *text, char *pattern) {
    char lowerText[MAX_NOTE_LENGTH];
    char lowerPattern[MAX_NOTE_LENGTH];
    
    convertLowerPtr(text, lowerText);
    convertLowerPtr(pattern, lowerPattern);
    
    char *textPtr = lowerText;
    int patternLen = strLenPtr(lowerPattern);
    
    while (*textPtr) {
        char *t = textPtr;
        char *p = lowerPattern;
        
        while (*p && *t == *p) {
            t++;
            p++;
        }
        
        if (*p == '\0') {
            return 1; 
        }
        textPtr++;
    }
    return 0;
}

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

int countWordOccurrencesPtr(char notes[][MAX_NOTE_LENGTH], int count, char *targetWord) {
    int occurrences = 0;
    char lowerTarget[MAX_NOTE_LENGTH];
    convertLowerPtr(targetWord, lowerTarget);
    
    for (int i = 0; i < count; i++) {
        char lowerNote[MAX_NOTE_LENGTH];
        convertLowerPtr(notes[i], lowerNote);
        
        char *ptr = lowerNote;
        while (*ptr) {
            if (ptr == lowerNote || *(ptr - 1) == ' ') {
                char *wordStart = ptr;
                char *targetPtr = lowerTarget;
                while (*ptr && *ptr != ' ' && *targetPtr && *ptr == *targetPtr) {
                    ptr++;
                    targetPtr++;
                }

                if (*targetPtr == '\0' && (*ptr == '\0' || *ptr == ' ')) {
                    occurrences++;
                }

                ptr = wordStart + 1;
            } else {
                ptr++;
            }
        }
    }
    return occurrences;
}

void removeNewlinePtr(char *str) {
    while (*str) {
        if (*str == '\n') {
            *str = '\0';
            return;
        }
        str++;
    }
}

int loadNotes(char notes[][MAX_NOTE_LENGTH]) {
    FILE *file = fopen("episodes.txt", "r");
    int count = 0;
    
    if (file == NULL) {
        printf("No existing episode notes found. Starting fresh!\n");
        return 0;
    }
    
    while (fgets(notes[count], MAX_NOTE_LENGTH, file) && count < MAX_NOTES) {
        removeNewlinePtr(notes[count]);
        
        if (strLenPtr(notes[count]) > 0) {
            count++;
        }
    }
    
    fclose(file);
    return count;
}

void saveNotes(char notes[][MAX_NOTE_LENGTH], int count) {
    FILE *file = fopen("episodes.txt", "w");
    
    if (file == NULL) {
        printf("Error saving notes!\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        char *ptr = notes[i];
        while (*ptr) {
            fputc(*ptr++, file);
        }
        fputc('\n', file);
    }
    
    fclose(file);
    printf("Episode notes saved successfully!\n");
}

int addNote(char notes[][MAX_NOTE_LENGTH], int count) {
    if (count >= MAX_NOTES) {
        printf("Maximum notes reached!\n");
        return count;
    }
    
    char newNote[MAX_NOTE_LENGTH];
    
    printf("Enter episode note title: ");
    getchar();
    fgets(newNote, MAX_NOTE_LENGTH, stdin);
    removeNewlinePtr(newNote);
    
    if (strLenPtr(newNote) == 0) {
        printf("Note cannot be empty!\n");
        return count;
    }
    
    strCopyPtr(notes[count], newNote);
    printf("Note added successfully! (%d words)\n", countWordsPtr(newNote));
    return count + 1;
}

void searchNotes(char notes[][MAX_NOTE_LENGTH], int count) {
    char searchTerm[MAX_NOTE_LENGTH];
    int found = 0;
    
    if (count == 0) {
        printf("No notes to search!\n");
        return;
    }
    
    printf("Enter keyword to search: ");
    getchar();
    fgets(searchTerm, MAX_NOTE_LENGTH, stdin);
    removeNewlinePtr(searchTerm);
    
    printf("\n=== Search Results ===\n");
    for (int i = 0; i < count; i++) {
        if (containsSubstringPtr(notes[i], searchTerm)) {
            printf("%d. %s\n", i + 1, notes[i]);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No matching notes found!\n");
    }
    printf("=====================\n");
}

int removeNote(char notes[][MAX_NOTE_LENGTH], int count) {
    int noteNum;
    
    if (count == 0) {
        printf("No notes to remove!\n");
        return count;
    }
    
    printf("Enter note number to remove (1-%d): ", count);
    scanf("%d", &noteNum);
    
    if (noteNum < 1 || noteNum > count) {
        printf("Invalid note number!\n");
        return count;
    }
    
    printf("Removing: %s\n", notes[noteNum - 1]);

    for (int i = noteNum - 1; i < count - 1; i++) {
        strCopyPtr(notes[i], notes[i + 1]);
    }
    
    printf("Note removed successfully!\n");
    return count - 1;
}

void editNote(char notes[][MAX_NOTE_LENGTH], int count) {
    int noteNum;
    char updatedNote[MAX_NOTE_LENGTH];
    
    if (count == 0) {
        printf("No notes to edit!\n");
        return;
    }
    
    printf("Enter note number to edit (1-%d): ", count);
    scanf("%d", &noteNum);
    
    if (noteNum < 1 || noteNum > count) {
        printf("Invalid note number!\n");
        return;
    }
    
    printf("Current note: %s\n", notes[noteNum - 1]);
    printf("Enter new note title: ");
    getchar();
    fgets(updatedNote, MAX_NOTE_LENGTH, stdin);
    removeNewlinePtr(updatedNote);
    
    if (strLenPtr(updatedNote) == 0) {
        printf("Note cannot be empty!\n");
        return;
    }
    
    strCopyPtr(notes[noteNum - 1], updatedNote);
    printf("Note updated successfully!\n");
}

void countSpecificWord(char notes[][MAX_NOTE_LENGTH], int count) {
    char targetWord[MAX_NOTE_LENGTH];
    
    if (count == 0) {
        printf("No notes available for counting!\n");
        return;
    }
    
    printf("Enter word to count across all notes: ");
    getchar();
    fgets(targetWord, MAX_NOTE_LENGTH, stdin);
    removeNewlinePtr(targetWord);
    
    int occurrences = countWordOccurrencesPtr(notes, count, targetWord);
    printf("The word '%s' appears %d time(s) across all notes.\n", targetWord, occurrences);
}

void displayNotes(char notes[][MAX_NOTE_LENGTH], int count) {
    if (count == 0) {
        printf("\nNo episode notes yet!\n");
        return;
    }
    
    printf("\n=== Episode Notes (%d notes) ===\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d. ", i + 1);
        char *ptr = notes[i];
        while (*ptr) {
            putchar(*ptr++);
        }
        printf(" [%d words]\n", countWordsPtr(notes[i]));
    }
    printf("=================================\n");
}

void displayStatistics(char notes[][MAX_NOTE_LENGTH], int count) {
    if (count == 0) {
        printf("\nNo notes to analyze!\n");
        return;
    }
    
    int totalWords = 0;
    int longestNoteIdx = 0;
    int longestLength = 0;
    
    for (int i = 0; i < count; i++) {
        int words = countWordsPtr(notes[i]);
        totalWords += words;
        
        int len = strLenPtr(notes[i]);
        if (len > longestLength) {
            longestLength = len;
            longestNoteIdx = i;
        }
    }
    
    printf("\n=== Statistics ===\n");
    printf("Total notes: %d\n", count);
    printf("Total words: %d\n", totalWords);
    printf("Average words per note: %.2f\n", (float)totalWords / count);
    printf("Longest note: %s\n", notes[longestNoteIdx]);
    printf("==================\n");
}

int main() {
    char notes[MAX_NOTES][MAX_NOTE_LENGTH];
    int noteCount = 0;
    int choice;
 
    for (int i = 0; i < MAX_NOTES; i++) {
        notes[i][0] = '\0';
    }

    noteCount = loadNotes(notes);
    printf("🎙️  Welcome to Podcast Episode Notes Manager!\n");
    printf("Loaded %d episode notes.\n\n", noteCount);
    
    while (1) {
        printf("\n--- Podcast Notes Menu ---\n");
        printf("1. Add New Note\n");
        printf("2. Search Notes\n");
        printf("3. Remove Note\n");
        printf("4. Edit Note\n");
        printf("5. Count Specific Word\n");
        printf("6. Display All Notes\n");
        printf("7. Show Statistics\n");
        printf("0. Exit and Save\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            break;
        }
        
        switch (choice) {
            case 1:
                noteCount = addNote(notes, noteCount);
                break;
            case 2:
                searchNotes(notes, noteCount);
                break;
            case 3:
                noteCount = removeNote(notes, noteCount);
                break;
            case 4:
                editNote(notes, noteCount);
                break;
            case 5:
                countSpecificWord(notes, noteCount);
                break;
            case 6:
                displayNotes(notes, noteCount);
                break;
            case 7:
                displayStatistics(notes, noteCount);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    printf("\n=== Final Episode Notes ===\n");
    displayNotes(notes, noteCount);
    saveNotes(notes, noteCount);
    
    printf("\nThank you for using Podcast Notes Manager! 🎙️\n");
    
    return 0;
}
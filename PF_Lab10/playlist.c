#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SONGS 10
#define MAX_TITLE_LENGTH 50

int readPlaylist(char playlist[][MAX_TITLE_LENGTH]) {
    FILE *file = fopen("playlist.txt", "r");
    int count = 0;
    
    if (file == NULL) {
        printf("No existing playlist found. Starting fresh!\n");
        return 0;
    }
    
    while (fgets(playlist[count], MAX_TITLE_LENGTH, file) && count < MAX_SONGS) {
        playlist[count][strcspn(playlist[count], "\n")] = 0;
        count++;
    }
    
    fclose(file);
    return count;
}

void savePlaylist(char playlist[][MAX_TITLE_LENGTH], int count) {
    FILE *file = fopen("playlist.txt", "w");
    
    if (file == NULL) {
        printf("Error saving playlist!\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n", playlist[i]);
    }
    
    fclose(file);
    printf("Playlist saved successfully!\n");
}

int addSong(char playlist[][MAX_TITLE_LENGTH], int count) {
    if (count >= MAX_SONGS) {
        printf("Playlist is full! Maximum 10 songs allowed.\n");
        return count;
    }
    
    printf("Enter song title (5-7 words): ");
    getchar();
    fgets(playlist[count], MAX_TITLE_LENGTH, stdin);
    playlist[count][strcspn(playlist[count], "\n")] = 0;
    
    printf("Song added successfully!\n");
    return count + 1;
}

int deleteSong(char playlist[][MAX_TITLE_LENGTH], int count) {
    char title[MAX_TITLE_LENGTH];
    
    printf("Enter song title to delete: ");
    getchar();
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0;
    
    for (int i = 0; i < count; i++) {
        if (strcmp(playlist[i], title) == 0) {
            for (int j = i; j < count - 1; j++) {
                strcpy(playlist[j], playlist[j + 1]);
            }
            printf("Song deleted successfully!\n");
            return count - 1;
        }
    }
    
    printf("Song not found!\n");
    return count;
}

void updateSong(char playlist[][MAX_TITLE_LENGTH], int count) {
    char oldTitle[MAX_TITLE_LENGTH];
    char newTitle[MAX_TITLE_LENGTH];
    
    printf("Enter song title to update: ");
    getchar();
    fgets(oldTitle, MAX_TITLE_LENGTH, stdin);
    oldTitle[strcspn(oldTitle, "\n")] = 0;
    
    for (int i = 0; i < count; i++) {
        if (strcmp(playlist[i], oldTitle) == 0) {
            printf("Enter new song title: ");
            fgets(newTitle, MAX_TITLE_LENGTH, stdin);
            newTitle[strcspn(newTitle, "\n")] = 0;
            strcpy(playlist[i], newTitle);
            printf("Song updated successfully!\n");
            return;
        }
    }
    
    printf("Song not found!\n");
}

void searchSong(char playlist[][MAX_TITLE_LENGTH], int count) {
    char title[MAX_TITLE_LENGTH];
    
    printf("Enter song title to search: ");
    getchar();
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0;
    
    for (int i = 0; i < count; i++) {
        if (strcmp(playlist[i], title) == 0) {
            printf("Song found at position %d: %s\n", i + 1, playlist[i]);
            return;
        }
    }
    
    printf("Song not found!\n");
}

void sortPlaylist(char playlist[][MAX_TITLE_LENGTH], int count) {
    char temp[MAX_TITLE_LENGTH];
    
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(playlist[j], playlist[j + 1]) > 0) {
                strcpy(temp, playlist[j]);
                strcpy(playlist[j], playlist[j + 1]);
                strcpy(playlist[j + 1], temp);
            }
        }
    }
}

void displayPlaylist(char playlist[][MAX_TITLE_LENGTH], int count) {
    if (count == 0) {
        printf("\nPlaylist is empty!\n");
        return;
    }
    
    printf("\n=== Current Playlist (%d songs) ===\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, playlist[i]);
    }
    printf("================================\n");
}

int main() {
    char playlist[MAX_SONGS][MAX_TITLE_LENGTH];
    int songCount = 0;
    int choice;

    songCount = readPlaylist(playlist);
    printf("Loaded %d songs from playlist.\n\n", songCount);
    
    while (1) {
        printf("\n--- Music Playlist Manager ---\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Update Song\n");
        printf("4. Search Song\n");
        printf("5. Display Playlist\n");
        printf("-1. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == -1) {
            break;
        }
        
        switch (choice) {
            case 1:
                songCount = addSong(playlist, songCount);
                break;
            case 2:
                songCount = deleteSong(playlist, songCount);
                break;
            case 3:
                updateSong(playlist, songCount);
                break;
            case 4:
                searchSong(playlist, songCount);
                break;
            case 5:
                displayPlaylist(playlist, songCount);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
 
    sortPlaylist(playlist, songCount);
    printf("\n=== Final Playlist (Alphabetical Order) ===\n");
    displayPlaylist(playlist, songCount);
    
    savePlaylist(playlist, songCount);
    
    printf("\nThank you for using Music Playlist Manager!\n");
    
    return 0;
}
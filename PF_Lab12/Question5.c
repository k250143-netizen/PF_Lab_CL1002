#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main () {
    int participants;
    printf("Enter the number of participants \n");
    scanf("%d", &participants);

    printf("Enter the correct password \n");
    char password[50];
    fgets(password, 50, stdin);
    password[strcspn(password, "\n")] = '\0';
    
    int passLen = strlen(password);
    
    char **userPass = malloc(participants * sizeof(char*));

    printf("Enter the password (attempt) \n");
    for (int i = 0; i < participants; i++) {
        char temp[200];
        printf("Enter password %d: ", i + 1);
        fgets(temp, 200, stdin);
        temp[strcspn(temp, "\n")] = '\0';

        userPass[i] = malloc(strlen(userPass) + 1);
        strcpy(userPass[i], temp);
    }

    double bestScore = -1;
    int bestIndex = 0;

    for (int i = 0; i < participants; i++) {
        int count = 0;
        int userPasslen = strlen(userPass[i]);

        for (int j = 0; i < userPass; j++) {
            if (j < userPasslen) {
                if ((isupper(password[j]) && isupper(userPass[i][j])) ||
                    (islower(password[j]) && islower(userPass[i][j])) ||
                    (isdigit(password[j]) && isdigit(userPass[i][j])) ||
                    (!isalnum(password[j]) && !isalnum(userPass[i][j]))) {

                    count++;
                }
            }
        }
        float score = (count * 100.0) / passLen;
        printf("Password: %s Similarity: %.2f\n", userPass[i], score);

        if (score > bestScore) {
            bestScore = score;
            bestIndex = i;
        }

    }
    printf("\nHighest similarity: \"%s\" (%.2f%%)\n",
           userPass[bestIndex], bestScore);

    for (int i = 0; i < participants; i++) {
        free(userPass[i]);
    }
    free(userPass);

}
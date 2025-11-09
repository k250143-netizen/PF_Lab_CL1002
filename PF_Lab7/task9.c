#include <stdio.h>

int main() {
    char sentence[] = "This is a programming challenge";
    char longestWord[100];
    char currentWord[100];
    int maxLength = 0;
    int currentLength = 0;
    int i = 0, j = 0;

    while (1) {
        char ch = sentence[i];

        if (ch != ' ' && ch != '\0') {
            currentWord[currentLength] = ch;
            currentLength++;
        } else {
            currentWord[currentLength] = '\0';

            if (currentLength > maxLength) {
                maxLength = currentLength;

                for (j = 0; j <= currentLength; j++) {
                    longestWord[j] = currentWord[j];
                }
            }

            currentLength = 0;
        }

        if (ch == '\0') {
            break;
        }

        i++;
    }

    printf("Longest word: %s\n", longestWord);
    printf("Length: %d\n", maxLength);

    return 0;
}

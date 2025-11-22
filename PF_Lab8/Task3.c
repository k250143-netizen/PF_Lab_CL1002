#include <stdio.h>
#include <ctype.h>

int main() {
    int i,j;
    char words[3][10];
    printf("Enter 3 words (max 9 characters each):\n");
    for(i = 0; i < 3; i++) {
        printf("Word %d: ", i + 1);
        scanf("%9s", words[i]); 
    }
    
    int vowelCount = 0;
    
    printf("\nWords you entered:\n");

    for( i = 0; i < 3; i++) {
        printf("Word %d: %s\n", i + 1, words[i]);
        
        for( j = 0; j < 10 && words[i][j] != '\0'; j++) {
            
            char currentChar = toupper(words[i][j]);

            if(currentChar == 'A' || currentChar == 'E' || currentChar == 'I' || 
               currentChar == 'O' || currentChar == 'U') {
                vowelCount++;
            }
        }
    }
    
    printf("\nTotal vowels found: %d\n", vowelCount);
    
    return 0;
}
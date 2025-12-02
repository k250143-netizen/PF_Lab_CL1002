#include <stdio.h>
#include <string.h>

void reverseString(char str[], int index) {
    if (str[index] == '\0') {
        return;
    }
    reverseString(str, index + 1);
    printf("%c", str[index]);
}

int isPalindrome(char str[], int start, int end) {
    if (start >= end) {
        return 1;
    }
    if (str[start] != str[end]) {
        return 0;
    }
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    char word[100];
    int choice;
    
    while(1) {
        printf("\n1. Analyze Word\n2. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        if(choice == 1) {
            printf("Enter a word: ");
            scanf("%s", word);
            
            printf("Reversed word: ");
            reverseString(word, 0);
            printf("\n");
            
            int len = strlen(word);
            if(isPalindrome(word, 0, len - 1)) {
                printf("The word is a Palindrome.\n");
            } else {
                printf("The word is NOT a Palindrome.\n");
            }
        } else {
            break;
        }
    }
    
    return 0;
}

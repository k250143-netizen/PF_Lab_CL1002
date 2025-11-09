#include <stdio.h>

int main() {
    
    char characters[] = {'h','e','l','l','o','\0'};
    char characters2[] = {'h','e','l','z','o','\0'};

    int i = 0;

    while (characters[i] != '\0' && characters2[i] != '\0') {
        if (characters[i] == characters2[i]) {
            printf("%c of First array is same as %c of Second array.\n", characters[i], characters2[i]);
        } else {
            printf("%c of First array is not same as %c of Second array.\n", characters[i], characters2[i]);
            break;
        }
        i++;
    }

    if (characters[i] == '\0' && characters2[i] != '\0') {
        printf("First array ended, but second still has more characters.\n");
    } else if (characters2[i] == '\0' && characters[i] != '\0') {
        printf("Second array ended, but first still has more characters.\n");
    }

    return 0;
}
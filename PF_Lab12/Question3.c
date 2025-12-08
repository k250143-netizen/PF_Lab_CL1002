#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int containsDigit(char *str) {
    while (*str != '\0') {
        if (*str >= '0' && *str <= '9') {
            return 1;
        }
    str++;
    }
}

int main () {
    int n;

    printf("Enter number of username\n");
    scanf("%d", &n);

    char **username = malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        username[i] = malloc(100);
        scanf("%s", username[i]);
    

    if (containsDigit(username[i])) {
        printf("%s\n", username[i]);
    }

    for (int i = 0; i < n; i++)
        free(username[i]);
    free(username);
}
return 0;
}
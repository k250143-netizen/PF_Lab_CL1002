#include <stdio.h>
#include <stdlib.h>

int main () {
    int n;
    printf("Enter the number of feedbacks \n");
    scanf("%d", &n);

    char **feedback = NULL;
    feedback = (char **)malloc(n * sizeof(char *));

    int i;
    char temp[500];

    
    for (i = 0; i <n; i++){
        printf("Enter feedbacks one by one:\n");
        fgets(temp, sizeof(temp), stdin);

        feedback[i] = (char *)malloc(strlen(temp) + 1);
        strcpy(feedback[i],temp);
    }
    int total = 0;
    for (int i = 0; i <n; i++) {
        for (int j = 0; feedback[i] != '\0'; j++) {
            total++;
        }
    }
    int longestIndex = 0;
    int longest = feedback[0];

    for (int i = 0; i < n; i++) {
        int len = strlen(feedback[i]);
        if (len > strlen(longest)) {
            longest = feedback[i];
            longestIndex = i;
    }
}
    for (int i = 0; i < n; i++) {
        printf("%s",feedback[i]);
    }
     printf("\nTotal characters in all feedback: %d\n", total);
    printf("Longest feedback:\n%s", feedback[longestIndex]);

    for (i = 0; i < n; i++) {
        free(feedback[i]);
    }
    free(feedback);

    return 0;
}
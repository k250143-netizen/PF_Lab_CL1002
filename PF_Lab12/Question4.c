#include <stdio.h>
#include <stdlib.h>

int main () {
    int len;
    printf("Enter the number of ratings \n");
    scanf("%d", &len);

    int *ratings = malloc(len * sizeof(int));
    
    int sum = 0;
    int max = 0;

    for (int i = 0; i < len; i++) {
        scanf("%d", &ratings[i]);
    }
    for (int i = 0; i < len; i++) {
        sum += ratings[i];
        if (ratings[i] > ratings[max]) {
            max = i;
        }
    }
    float avg = (float)sum / len;

    printf("\nTotal ratings across all categories: %ld\n", sum);
    printf("Average ratings per category: %.2f\n", avg);
    printf("Category with highest rating count: %d (count = %d)\n", max + 1, ratings[max]);

    int category, newRating;

    printf("\nEnter category number to update ");
    scanf("%d", &category);
    printf("Enter new rating count for category %d: ", category);
    scanf("%d", &newRating);
    ratings[category - 1] = newRating;

    sum = 0;
    max = 0;

    for (int i = 0; i < len; i++) {
        scanf("%d", &ratings[i]);
    }
    for (int i = 0; i < len; i++) {
        sum += ratings[i];
        if (ratings[i] > ratings[max]) {
            max = i;
        }
    }
    avg = (float)sum / len;
    printf("\nEnter category number to update ");
    scanf("%d", &category);
    printf("Enter new rating count for category %d: ", category);
    scan("%d", &newRating);
    ratings[category - 1] = newRating;

    free(ratings);

    return 0;
}
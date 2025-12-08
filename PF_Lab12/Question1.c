#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of books \n");
    scanf("%d", &n);

    int *stocks = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &stocks[i]);
    }

    int total = 0, min = 0;
    for (int i = 0; i < n; i++) {
        total = total + stocks[i];
        if (stocks[i] < stocks[min]) {
            min = i;
        }
    }
    float avg = (float)total / n;
    printf("\nTotal stock: %ld\n", total);
    printf("Average stock per category: %.2f\n", avg);
    printf("Category with lowest stock: %d (stock = %d)\n", min + 1, stocks[min]);

    int newCategoryIndex, newStock;

    printf("Enter category number to update: ");
    scanf("%d", &newCategoryIndex);
    printf("Enter the new stock \n");
    printf("%d", &newStock);
    stocks[newCategoryIndex] = newStock;

    free(stocks);
    return 0;
}
#include <stdio.h>

void findRoads(int roads[], int size, int target) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (roads[i] + roads[j] == target) {
                printf("\nRoad %d and Road %d have a combined traffic of %d vehicles.\n",i, j, target);
                return;
            }
        }
    }
    printf("No matching pair found.\n");
}

int main() {
    int size;
    printf("Enter the number of roads in the city: ");
    scanf("%d", &size);

    int roads[size];
    printf("\nEnter the daily vehicle count for each road:\n");
    for (int i = 0; i < size; i++) {
        printf("Road %d: ", i);
        scanf("%d", &roads[i]);
    }

    int target;
    printf("\nEnter the target combined vehicle count: ");
    scanf("%d", &target);

    findRoads(roads, size, target);

    return 0;
}

#include <stdio.h>

int main() {
    int inventory[2][3][4];
    int sectionTotal[2] = {0};
    int shelfSum;
    int maxShelfTotal = 0, maxSection = 0, maxShelf = 0;
	int s,sh,it;
    for (s = 0; s < 2; s++) {
        printf("\n--- Section %d ---\n", s + 1);
        for (sh = 0; sh < 3; sh++) {
            printf("\n--- Shelf %d ---\n", sh + 1);
			for (it = 0; it < 4; it++) {
    		printf("Enter quantity for Item %d: ", it + 1);
    		scanf("%d", &inventory[s][sh][it]);
			}

        }
    }

    for ( s = 0; s < 2; s++) {
        for ( sh = 0; sh < 3; sh++) {
            shelfSum = 0;
            for ( it = 0; it < 4; it++) {
                sectionTotal[s] += inventory[s][sh][it];
                shelfSum += inventory[s][sh][it];
            }
            if (shelfSum > maxShelfTotal) {
                maxShelfTotal = shelfSum;
                maxSection = s;
                maxShelf = sh;
            }
        }
    }
    printf("\nTotal items in each section:\n");
    for ( s = 0; s < 2; s++) {
        printf("Section %d: %d items\n", s + 1, sectionTotal[s]);
    }
    printf("\nShelf with the highest total quantity:\n");
    printf("Section %d, Shelf %d with %d items\n",
    maxSection + 1, maxShelf + 1, maxShelfTotal);

    return 0;
}


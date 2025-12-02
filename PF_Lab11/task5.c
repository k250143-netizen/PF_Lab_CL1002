#include <stdio.h>

struct Team {
    char name[50];
    int scores[10];
    int rounds;
};

int calculateTotalScore(int scores[], int n) {
    if (n <= 0) {
        return 0;
    }
    return scores[n-1] + calculateTotalScore(scores, n-1);
}

int main() {
    struct Team teams[10];
    int n, threshold;
    
    printf("Enter number of teams: ");
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        printf("\nEnter details for Team %d:\n", i+1);
        printf("Team Name: ");
        scanf("%s", teams[i].name);
        printf("Number of rounds: ");
        scanf("%d", &teams[i].rounds);
        
        printf("Enter scores for %d rounds:\n", teams[i].rounds);
        for(int j=0; j<teams[i].rounds; j++) {
            scanf("%d", &teams[i].scores[j]);
        }
    }
    
    printf("\nEnter score threshold: ");
    scanf("%d", &threshold);
    
    printf("\n--- Teams above threshold ---\n");
    for(int i=0; i<n; i++) {
        int total = calculateTotalScore(teams[i].scores, teams[i].rounds);
        printf("Team %s Total Score: %d", teams[i].name, total);
        
        if(total > threshold) {
            printf(" (Qualified)\n");
        } else {
            printf(" (Not Qualified)\n");
        }
    }
    
    return 0;
}

#include <stdio.h>
#include <string.h>

void countdown(int days) {
    if (days < 0) {
        return;
    }
    if (days == 0) {
        printf("Event is today!\n");
        return;
    }
    printf("%d days remaining...\n", days);
    countdown(days - 1);
}

struct Event {
    char name[50];
    int daysRemaining;
};

int main() {
    struct Event events[10];
    int n;
    
    printf("Enter number of events: ");
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        printf("\nEnter event %d name: ", i+1);
        scanf("%s", events[i].name);
        printf("Enter days remaining: ");
        scanf("%d", &events[i].daysRemaining);
    }
    
    printf("\n--- Event Countdowns ---\n");
    for(int i=0; i<n; i++) {
        printf("\nCountdown for %s:\n", events[i].name);
        countdown(events[i].daysRemaining);
    }
    
    return 0;
}

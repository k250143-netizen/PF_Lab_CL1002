#include <stdio.h>

float calculateBonus(float salary) {
    if (salary < 30000)
        return salary * 0.20;
    else
        return salary * 0.10;
}

int main() {
    int size;
    printf("Enter the Number of Employees:");
    scanf(" %d",&size);
    float salary[size];
    float bonus, totalPayout = 0;

    for (int i = 0; i < size; i++) {
        printf("Enter salary of Employee %d: ", i + 1);
        scanf("%f", &salary[i]);
    }

    printf("\n");

    for (int i = 0; i < size; i++) {
        bonus = calculateBonus(salary[i]);
        printf("Employee %d Bonus: %.2f\n", i + 1, bonus);
        totalPayout = salary[i] + bonus;
    }

    printf("Total Payout: %.2f\n", totalPayout);

    return 0;
}

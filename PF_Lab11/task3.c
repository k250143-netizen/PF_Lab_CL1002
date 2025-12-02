#include <stdio.h>
#include <string.h>

struct Employee {
    char name[50];
    int id;
    int daysPresent;
};

int calculateTotalAttendance(struct Employee emps[], int n) {
    if (n <= 0) {
        return 0;
    }
    return emps[n-1].daysPresent + calculateTotalAttendance(emps, n-1);
}

int main() {
    struct Employee employees[100];
    int n, minDays;
    
    printf("Enter number of employees: ");
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        printf("\nEnter details for employee %d:\n", i+1);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("ID: ");
        scanf("%d", &employees[i].id);
        printf("Days Present: ");
        scanf("%d", &employees[i].daysPresent);
    }
    
    int total = calculateTotalAttendance(employees, n);
    printf("\nTotal attendance of all employees: %d days\n", total);
    
    printf("Enter minimum required days: ");
    scanf("%d", &minDays);
    
    printf("\nEmployees with low attendance:\n");
    for(int i=0; i<n; i++) {
        if(employees[i].daysPresent < minDays) {
            printf("%s (ID: %d) - %d days\n", employees[i].name, employees[i].id, employees[i].daysPresent);
        }
    }
    
    return 0;
}

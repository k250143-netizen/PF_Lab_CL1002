#include <stdio.h>
int main() {
    float basic_salary;
    printf("Enter the basic salary = ");
    scanf("%f", &basic_salary);

    float hra = (10.0 / 100) * basic_salary; // hra = house rent allowance
    float da = (5.0 / 100) * basic_salary;  // da = dearness allowance
    float gross_salary = basic_salary + hra + da;
    printf("HRA(House Rent Allowance) = %.2f\n", hra);
    printf("DA(Dearness Allowance) = %.2f\n", da);
    printf("Gross Salary = %.2f\n", gross_salary);
    return 0;
}
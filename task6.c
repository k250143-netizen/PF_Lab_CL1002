#include <stdio.h>
int main()
{
    int num;
    int i;
    printf("------Table Printer------\n");
    printf("Enter Number to Print the Table: ");
    scanf(" %d", &num);
    printf("\nMultiplication Table of %d\n", num);
    printf("---------------------------\n");
    for (i = 1; i <= 10; i++)
    {
        int multiply = num * i;
        printf("%d x %d = %d\n", num, i, multiply);
    }
    printf("---------------------------\n");
    printf("Table printing complete!\n");
    return 0;
}
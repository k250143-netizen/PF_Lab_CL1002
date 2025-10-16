#include <stdio.h>
int main()
{
    int pin;
    int sum = 0;
    printf("Enter PIN: ");
    scanf("%d", &pin);
    if (pin >= 1000 && pin <= 9999)
    {
        while (pin != 0)
        {
            int digit = pin % 10;
            sum = sum + digit;
            pin = pin / 10;
        }
        if (sum >= 10)
        {
            printf("Strong PIN.");
        }
        else
        {
            printf("Weak PIN.");
        }
    }
    else
    {
        printf("Invalid PIN");
    }
    return 0;
}
#include <stdio.h>
int main()
{
    int num_unit;
    int even_counter = 0;
    int odd_counter = 0;
    printf("Enter Your Consuming Unit: ");
    scanf(" %d", &num_unit);
    while (num_unit != 0)
    {
        int digit = num_unit % 10;
        if (digit % 2 != 0)
        {
            odd_counter++;
        }
        else
        {
            even_counter++;
        }
        num_unit = num_unit / 10;
    }
    printf("Total Even Number is: %d\n", even_counter);
    printf("Total Odd Number is: %d\n", odd_counter);
    return 0;
}
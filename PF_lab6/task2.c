#include <stdio.h>
int main()
{
    int ticket_num;
    int reverse = 0;
    printf("Enter Ticket Number: ");
    scanf(" %d", &ticket_num);
    while (ticket_num != 0)
    {
        int digit = ticket_num % 10;
        reverse = reverse * 10 + digit;
        ticket_num = ticket_num / 10;
    }
    printf("\nRevrese Ticket Number: %d", reverse);
    return 0;
}
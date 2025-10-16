#include <stdio.h>
int main()
{
    int num;
    int reverse = 0;
    printf("Enter Book Code: ");
    scanf(" %d", &num);
    int original = num;
    while (num != 0)
    {
        int digit = num % 10;
        reverse = reverse * 10 + digit;
        num = num / 10;
    }
    printf("Reverse: %d & Original: %d\n", reverse, original);
    if (reverse != original)
    {
        printf("Not Palindrome!\n");
        printf("Your Code is Invalid!");
    }
    else
    {
        printf("Palindrome!\n");
        printf("Your Code is Valid!");
    }
    return 0;
}
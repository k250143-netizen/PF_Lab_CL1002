#include <stdio.h>
#include <string.h>
int main()
{
    char user_name[10] = "admin";
    char password[10] = "1234";
    char str1[10];
    char str2[10];
    printf("Enter username: ");
    scanf("%s", str1);
    printf("Enter password: ");
    scanf("%s", str2);

    if (strcmp(user_name, str1) == 0 && strcmp(password, str2) == 0)
    {
        printf("Login successful.\n");
    }
    else
    {
        printf("Login failed.\n");
        printf("Incorrect username or password.\n");
    }
    return 0;
}
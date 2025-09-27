#include <stdio.h>
#include <strings.h>
#include<string.h>
int main()
{
    int age;
    char ticket_type[20];
    char movie_type[20];
    int check;
    printf("Program for Movie Theater to chose Ticket Type for Watching Movie\n");
    printf("Please Enter your age = ");
    scanf("%d", &age);

    if (age <= 12)
    {
        strcpy(ticket_type, "child ticket");
        printf("Three types of movies are there, Please, select the movie type on base of your intrest:\n");
        printf("1. Action Movie.\n");
        printf("2. Comedy Movie.\n");
        printf("3. Horror Movie.\n");
        printf("Select movie type (1-3):");
        scanf("%d", &check);
        switch (check)
        {
        case 1:
            strcpy(movie_type, "Action Movie");
            break;
        case 2:
            strcpy(movie_type, "Comedy Movie");
            break;
        case 3:
            strcpy(movie_type, "Horror Movie");
            break;
        default:
            printf("Invalid Movie Type.");
            break;
        }
    }
    else if (age > 12 && age <= 60)
    {
        strcpy(ticket_type, "Adult Ticket");
        printf("Three types of movies are there, Please, select the movie type on base of your intrest:\n");
        printf("1. Action Movie.\n");
        printf("2. Comedy Movie.\n");
        printf("3. Horror Movie.\n");
        printf("Select movie type (1-3):");
        scanf("%d", &check);
        switch (check)
        {
        case 1:
            strcpy(movie_type, "Action Movie");
            break;
        case 2:
            strcpy(movie_type, "Comedy Movie");
            break;
        case 3:
            strcpy(movie_type, "Horror Movie");
            break;
        default:
            printf("Invalid Movie Type.");
            break;
        }
    }
    else if (age > 60)
    {
        strcpy(ticket_type, "Adult Ticket");
        printf("Three types of movies are there, Please, select the movie type on base of your intrest:\n");
        printf("1. Action Movie.\n");
        printf("2. Comedy Movie.\n");
        printf("3. Horror Movie.\n");
        printf("Select movie type (1-3):");
        scanf("%d", &check);
        switch (check)
        {
        case 1:
            strcpy(movie_type, "Action Movie");
            break;
        case 2:
            strcpy(movie_type, "Comedy Movie");
            break;
        case 3:
            strcpy(movie_type, "Horror Movie");
            break;
        default:
            printf("Invalid Movie Type.");
            break;
        }
    }
    else
    {
        printf("Invalid Age");
    }
    printf("Your Ticket Type is %s and Movie Type is %s", ticket_type,movie_type);
    return 0;
}
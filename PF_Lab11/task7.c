#include <stdio.h>
#include <string.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Forecast {
    char luckyColor[20];
    int luckyNumber;
    char advice[100];
};

struct User {
    char name[50];
    struct Date dob;
    char zodiacSign[20];
};

struct ZodiacInfo {
    char signName[20];
    struct Forecast dailyForecast;
};

void determineZodiac(struct User *u) {
    int d = u->dob.day;
    int m = u->dob.month;
    
    if ((m == 3 && d >= 21) || (m == 4 && d <= 19)) strcpy(u->zodiacSign, "Aries");
    else if ((m == 4 && d >= 20) || (m == 5 && d <= 20)) strcpy(u->zodiacSign, "Taurus");
    else if ((m == 5 && d >= 21) || (m == 6 && d <= 20)) strcpy(u->zodiacSign, "Gemini");
    else if ((m == 6 && d >= 21) || (m == 7 && d <= 22)) strcpy(u->zodiacSign, "Cancer");
    else if ((m == 7 && d >= 23) || (m == 8 && d <= 22)) strcpy(u->zodiacSign, "Leo");
    else if ((m == 8 && d >= 23) || (m == 9 && d <= 22)) strcpy(u->zodiacSign, "Virgo");
    else if ((m == 9 && d >= 23) || (m == 10 && d <= 22)) strcpy(u->zodiacSign, "Libra");
    else if ((m == 10 && d >= 23) || (m == 11 && d <= 21)) strcpy(u->zodiacSign, "Scorpio");
    else if ((m == 11 && d >= 22) || (m == 12 && d <= 21)) strcpy(u->zodiacSign, "Sagittarius");
    else if ((m == 12 && d >= 22) || (m == 1 && d <= 19)) strcpy(u->zodiacSign, "Capricorn");
    else if ((m == 1 && d >= 20) || (m == 2 && d <= 18)) strcpy(u->zodiacSign, "Aquarius");
    else strcpy(u->zodiacSign, "Pisces");
}

int main() {
    struct User users[100];
    struct ZodiacInfo zodiacs[12];
    int userCount = 0;
    int choice;
    
    // Initialize some default forecasts
    char *signs[] = {"Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricorn", "Aquarius", "Pisces"};
    for(int i=0; i<12; i++) {
        strcpy(zodiacs[i].signName, signs[i]);
        strcpy(zodiacs[i].dailyForecast.luckyColor, "Blue");
        zodiacs[i].dailyForecast.luckyNumber = 7;
        strcpy(zodiacs[i].dailyForecast.advice, "Today is a good day for new beginnings.");
    }
    
    while(1) {
        printf("\n1. Add User\n2. View Horoscope\n3. Update Forecast\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        if(choice == 1) {
            printf("Enter name: ");
            scanf("%s", users[userCount].name);
            printf("Enter DOB (dd mm yyyy): ");
            scanf("%d %d %d", &users[userCount].dob.day, &users[userCount].dob.month, &users[userCount].dob.year);
            determineZodiac(&users[userCount]);
            printf("User added! Zodiac Sign: %s\n", users[userCount].zodiacSign);
            userCount++;
        }
        else if(choice == 2) {
            char name[50];
            printf("Enter user name: ");
            scanf("%s", name);
            int found = 0;
            for(int i=0; i<userCount; i++) {
                if(strcmp(users[i].name, name) == 0) {
                    found = 1;
                    printf("\nHoroscope for %s (%s):\n", users[i].name, users[i].zodiacSign);
                    for(int j=0; j<12; j++) {
                        if(strcmp(zodiacs[j].signName, users[i].zodiacSign) == 0) {
                            printf("Lucky Color: %s\n", zodiacs[j].dailyForecast.luckyColor);
                            printf("Lucky Number: %d\n", zodiacs[j].dailyForecast.luckyNumber);
                            printf("Advice: %s\n", zodiacs[j].dailyForecast.advice);
                        }
                    }
                }
            }
            if(!found) printf("User not found.\n");
        }
        else if(choice == 3) {
            char sign[20];
            printf("Enter zodiac sign to update: ");
            scanf("%s", sign);
            for(int i=0; i<12; i++) {
                if(strcmp(zodiacs[i].signName, sign) == 0) {
                    printf("Enter new lucky color: ");
                    scanf("%s", zodiacs[i].dailyForecast.luckyColor);
                    printf("Enter new lucky number: ");
                    scanf("%d", &zodiacs[i].dailyForecast.luckyNumber);
                    printf("Enter new advice (one word/string): ");
                    scanf("%s", zodiacs[i].dailyForecast.advice);
                    printf("Forecast updated!\n");
                }
            }
        }
        else {
            break;
        }
    }
    
    return 0;
}

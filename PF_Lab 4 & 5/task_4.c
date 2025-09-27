#include <stdio.h>
int main() {
    int drink;
    int fast_food;
    int valid_drink = 1;
    int valid_fast_food = 1;
    printf("Enter drink choice (1-5): ");
    scanf("%d", &drink);
    printf("Enter fast food choice (1-5): ");
    scanf("%d", &fast_food);
    switch (drink)
    {
    case 1:
        printf("You chose Drink 1 which is cola\n");
        break;
    case 2:
        printf("You chose Drink 2 which is lemonade\n");
        break;
    case 3:
        printf("You chose Drink 3 which is orange juice\n");
        break;
    case 4:
        printf("You chose Drink 4 which is water\n");
        break;
    case 5:
        printf("You chose Drink 5 which is coffee\n");
        break;
    default:
        printf("Invalid drink choice\n");
        valid_drink = 0;
        break;
    }

    switch (fast_food)
    {
    case 1:
        printf("You chose Fast Food 1 which is burger\n");
        break;
    case 2:
        printf("You chose Fast Food 2 which is fries\n");
        break;
    case 3:
        printf("You chose Fast Food 3 which is pizza\n");
        break;
    case 4:
        printf("You chose Fast Food 4 which is salad\n");
        
        break;
    case 5:
        printf("You chose Fast Food 5 which is sushi\n");
        break;
    default:
        printf("Invalid fast food choice\n");
        valid_fast_food = 0;
        break;
    }

    if (valid_drink && valid_fast_food) {
        printf("Enjoy your meal!\n");
    }

    return 0;
}
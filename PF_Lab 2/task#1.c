#include <stdio.h>
int main()
{   
    int subject_1;
    int subject_2;
    int subject_3;

    printf("Enter the marks of first subject out of 100 = ");
    scanf("%d", &subject_1);

    printf("Enter the marks of second subject out of 100 = ");
    scanf("%d", &subject_2);

    printf("Enter the marks of third subject out of 100 = ");
    scanf("%d", &subject_3);

    int ob_marks = subject_1 + subject_2 + subject_3;
    printf("Your obtained marks in over all subject is: %d\n", ob_marks);

    float percentage = (ob_marks / 300.0) * 100;    // 300.0 se division float me hoga agr ye 300 hota to integer me hota to galat ans aata 0 print hota 

    printf("Your percentage is: %.2f", percentage); // %.2f = 2 decimal places

    return 0;
}

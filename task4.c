#include <stdio.h>
int main()
{
    int start_loop = 1;
    float marks;
    float sum = 0;
    int i = 1;
    while (start_loop)
    {
        printf("\nEnter Marks of student%d: ", i);
        scanf(" %f", &marks);
        if (marks < 0)
        {
            printf("Invalid Marks\n");
            break;
        }
        else
        {
            sum = sum + marks;
        }
        i++;
    }
    printf("Sum of All Student Marks: %.3f\n", sum);
    printf("Average Marks of the Class is: %.3f\n", sum / (i - 1));

    return 0;
}
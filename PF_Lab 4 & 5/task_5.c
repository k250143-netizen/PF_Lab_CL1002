#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c;
    printf("Enter the coefficient of quadratic equation (a, b, c).\n");
    printf("a: ");
    scanf("%lf", &a);
    printf("b: ");
    scanf("%lf", &b);
    printf("c: ");
    scanf("%lf", &c);
    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0)
    {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots are real and different.\n");
        printf("Root 1 = %.2lf\n", root1);
        printf("Root 2 = %.2lf\n", root2);
    }
    else if (discriminant == 0)
    {
        double root = -b / (2 * a);
        printf("Roots are real and the same.\n");
        printf("Root = %.2lf\n", root);
    }
    else
    {
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        printf("Roots are complex and different.\n");
        printf("Root 1 = %.2lf + %.2lfi\n", realPart, imaginaryPart);
        printf("Root 2 = %.2lf - %.2lfi\n", realPart, imaginaryPart);
    }

    return 0;
}
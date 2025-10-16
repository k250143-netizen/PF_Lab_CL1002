#include <stdio.h>
#include <math.h>
int main() {
    int geometry;
    printf("Choose a shape to calculate area:\n");
    printf("1. Circle\n");
    printf("2. Rectangle\n");
    printf("3. Triangle\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &geometry);
    int choise;
    printf("Choose area calculation method:\n");
    printf("1. Calculate Area of geometry\n");
    printf("2. Calculate Perimeter of geometry\n");
    printf("Enter your choice (1-2): ");
    scanf("%d", &choise);

    switch (geometry) {
        case 1: {
            switch (choise)
            {
            case 1:{
                double radius;
                printf("Enter the radius of the circle: ");
                scanf("%lf", &radius);
                double area = 3.14 * radius * radius;
                printf("Area of the circle: %.2lf\n", area);
                break;
            }
            case 2: {
                double radius;
                printf("Enter the radius of the circle: ");
                scanf("%lf", &radius);
                double perimeter = 2 * 3.14 * radius;
                printf("Perimeter of the circle: %.2lf\n", perimeter);
                break;
            }
            default:
                printf("Invalid choice.\n");
                break;
            }
            break;
        }
        case 2: {
            switch (choise)
            {
            case 1: {
                double length, width;
                printf("Enter the length and width of the rectangle.");
                printf("length: ");
                scanf("%lf", &length);
                printf("width: ");
                scanf("%lf", &width);
                double area = length * width;
                printf("Area of the rectangle: %.2lf\n", area);
                break;
            }
            case 2: {
                double length, width;
                printf("length: ");
                scanf("%lf", &length);
                printf("width: ");
                scanf("%lf", &width);
                double perimeter = 2 * (length + width);
                printf("Perimeter of the rectangle: %.2lf\n", perimeter);
                break;
            }
            default:
                printf("Invalid choice.\n");
                break;
            }
            break;
        }
        case 3: {
            switch (choise)
            {
            case 1: {
                double side1, side2, side3;
                printf("Enter the base and height of the triangle.");
                printf("side1: ");
                scanf("%lf", &side1);
                printf("side2: ");
                scanf("%lf", &side2);
                printf("side3: ");
                scanf("%lf", &side3);
                double s = (side1 + side2 + side3) / 2;
                double area = sqrt(s * (s - side1) * (s - side2) * (s - side3));
                printf("Area of the triangle: %.2lf\n", area);
                break;
            }
            case 2: {
                double side1, side2, side3;
                printf("Enter the base and height of the triangle.");
                printf("side1: ");
                scanf("%lf", &side1);
                printf("side2: ");
                scanf("%lf", &side2);
                printf("side3: ");
                scanf("%lf", &side3);
                double perimeter = side1 + side2 + side3;
                printf("Perimeter of the triangle: %.2lf\n", perimeter);
                break;
            }
            default:
                printf("Invalid choice.\n");
                break;
            }
            break;
        }
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}
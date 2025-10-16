#include <stdio.h>
int main()
{
    int a;
    int b;
    int c;
    printf("Enter a = ");
    scanf("%d", &a);
    printf("Enter b = ");
    scanf("%d", &b);

    printf("Enter c = ");
    scanf("%d", &c);
    if (a > b && b > c)
    {
        printf("b is second greatest numer which is: %d", b);
    }
    else if (b > a && a > c)
    {
        printf("a is second greatest numer which is: %d", a);
    }
    else if (b > c && c > a)
    {
        printf("c is second greatest numer which is: %d", c);
    }
    else if(c > b && c < a){
        printf("c is second greatest numer which is: %d", c);
    }
    else if (a < b && b < c)
    {
        printf("b is second greatest numer which is: %d", b);
    }
    else if (b < a && a < c)
    {
        printf("a is second greatest numer which is: %d", a);
    }
    else
    {
        printf("wrong relation");
    }
    return 0;
}
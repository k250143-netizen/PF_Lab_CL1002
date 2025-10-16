#include <stdio.h>
int main()
{

    int a;
    printf("Enter the value of a = ");
    scanf("%d", &a);
    int b;
    printf("Enter the value of b = ");
    scanf("%d", &b);
    int c = a;
    a = b;
    b = c;
    printf("The value of a is %d\n", a);
    printf("The value of b is %d\n", b);

    return 0;
}
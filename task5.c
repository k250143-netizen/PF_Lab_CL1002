#include <stdio.h>
int main()
{
    int num;
    long long factorial = 1;
    printf("Enter Score: ");
    scanf(" %d", &num);
    if (num == 0 || num == 1)
    {
        printf("Score After multipying: %lld\n", factorial);
        return 0;
    }
    for (long long i = 2; i <= num; i++)
    {
        factorial = factorial * i;
    }
    printf("Score After multipying: %lld\n", factorial);
    return 0;
}

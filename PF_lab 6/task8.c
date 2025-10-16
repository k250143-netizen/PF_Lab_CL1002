#include <stdio.h>

int main() {
    int n;
    printf("Enter value of n: ");
    scanf("%d", &n);

    long long fact2n = 1, factn = 1, factn1 = 1;
    
    for (int i = 1; i <= 2 * n; i++) {
        fact2n *= i;
    }
    for (int i = 1; i <= n; i++) {
        factn *= i;
    }
    for (int i = 1; i <= n + 1; i++) {
        factn1 *= i;
    }

    long long catalan = fact2n / (factn1 * factn);

    printf("Catalan number C%d = %lld\n", n, catalan);

    return 0;
}

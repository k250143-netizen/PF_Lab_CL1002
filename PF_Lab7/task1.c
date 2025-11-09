#include <stdio.h>

int main(void) {
    int temperatures[] = {23, 34, 25, 28, 31, 29, 35, 26, 30};
    int n = sizeof(temperatures) / sizeof(temperatures[0]);

    if (n == 0) {
        printf("No temperature readings available.\n");
        return 0;
    }

    int max_temp = temperatures[0];
    int min_temp = temperatures[0];

    for (int i = 0; i < n; i++) {
        if (temperatures[i] > max_temp) {
            max_temp = temperatures[i];
        }
        if (temperatures[i] < min_temp) {
            min_temp = temperatures[i];
        }
    }

    printf("Q1: Temperature Sensor Analysis\n");
    printf("Temperature readings: ");
    for (int i = 0; i < n; i++) {
        printf("%d", temperatures[i]);
        if (i < n - 1) printf(", ");
    }
    printf("\n");
    printf("Highest temperature: %d°C\n", max_temp);
    printf("Lowest temperature: %d°C\n", min_temp);

    return 0;
}
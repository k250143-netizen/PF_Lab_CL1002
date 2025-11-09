#include <stdio.h>

int main(void) {
    float power_readings[] = {
        250.5f, 280.7f, 310.2f, 290.5f, 285.6f,
        270.8f, 295.4f, 320.1f, 305.6f, 275.3f,
        260.4f, 285.9f, 300.2f, 315.7f, 290.8f,
        280.3f, 270.5f, 295.8f, 310.4f, 300.6f,
        285.2f, 275.9f, 265.4f, 280.1f
    };
    int n = sizeof(power_readings) / sizeof(power_readings[0]);

    if (n == 0) {
        printf("No power readings available.\n");
        return 0;
    }

    float total = 0.0f;
    for (int i = 0; i < n; i++) {
        total += power_readings[i];
    }

    float average = total / n;

    printf("Q2: Energy Meter Analysis\n");
    printf("Total power usage: %.2f watts\n", total);
    printf("Average power usage: %.2f watts per hour\n", average);

    return 0;
}
#include <stdio.h>

int main(void) {
    int sensor_data[] = {5, 2, 8, 2, 9, 2, 3, 7, 2, 6};
    int n = sizeof(sensor_data) / sizeof(sensor_data[0]);
    int value_to_remove = 2;

    printf("Q3: Sensor Data Cleanup\n");
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d", sensor_data[i]);
        if (i < n - 1) printf(", ");
    }
    printf("\nRemoving value: %d\n", value_to_remove);

    int new_size = 0;
    for (int i = 0; i < n; i++) {
        if (sensor_data[i] != value_to_remove) {
            sensor_data[new_size] = sensor_data[i];
            new_size++;
        }
    }

    printf("Array after removal: ");
    for (int i = 0; i < new_size; i++) {
        printf("%d", sensor_data[i]);
        if (i < new_size - 1) printf(", ");
    }
    printf("\nNew size: %d\n", new_size);

    return 0;
}
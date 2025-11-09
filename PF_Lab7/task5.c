#include <stdio.h>

int main() {
    
    int arr1[5] = {50, 40, 30, 20, 10};
    int arr2[5] = {5, 4, 3, 2, 1};
    int arr3[10];

    for (int i = 0; i < 10; i++) {
        if (i < 5) {
            arr3[i] = arr1[i];
        } else {
            arr3[i] = arr2[i - 5];  
        }
    }

    for (int i = 0; i < 10; i++) {
        printf(" %d ", arr3[i]);
    }

    return 0;
}
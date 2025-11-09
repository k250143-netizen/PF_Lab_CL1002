#include<stdio.h>

int main() {
    int arr[5] = {50, 40, 30, 20, 10};
    int start = 0;
    int end = 4;
    int temp;

    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }

   
    for (int i = 0; i < 5; i++) {
        printf(" %d ", arr[i]);
    }

    return 0;
}
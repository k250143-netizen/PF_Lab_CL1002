#include <stdio.h>

void analyzeData(int *arr, int n, int *max, int *min, float *avg);
int main () {
    int myArr[] = {3,2,6,8,12,65,34};
    int n = 7;
    int max, min;
    float avg;

    analyzeData(myArr,n,&max,&min,&avg);

    printf("Maximum = %d\n", max);
    printf("Minimum = %d\n", min);
    printf("Average = %.2f\n", avg);

return 0;
}

void analyzeData(int *arr, int n, int *max, int *min, float *avg) {
    *max = arr[0]; 
    *min = arr[0];
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > *max) {
            *max = arr[i];
        }
        if (arr[i] < *min) {
            *min = arr[i];
        }
        sum = sum + arr[i];
        
    }
    *avg = (float)sum/n;
}
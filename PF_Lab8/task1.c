#include <stdlib.h>
#include <time.h>


int main() {
	int pixel=8;
	int BRIGHTNESS_INCREASE=20;
    int image[pixel][pixel];
    int brightened[pixel][pixel];
    int i, j;

    srand(time(0));

    printf("---Original Image Matrix---\n");
    for (i = 0; i < pixel; i++) {
        for (j = 0; j < pixel; j++) {
            image[i][j] = rand() % 256; 
            printf("%5d ", image[i][j]); 
        }
        printf("\n");
    }

    printf("\n----Brightened Image Matrix---\n");
    for (i = 0; i < pixel; i++) {
        for (j = 0; j < pixel; j++) {
            brightened[i][j] = image[i][j] + BRIGHTNESS_INCREASE;
            if (brightened[i][j] > 255)
                brightened[i][j] = 255; 
            printf("%5d ", brightened[i][j]);
        }
        printf("\n");
    }

    return 0;
}

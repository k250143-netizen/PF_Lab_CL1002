#include<stdio.h>
int main(){
    int temp;
    int i,j;
    int n=3;
    int matrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int transpose[3][3];


    printf("Original Game Board:\n");
    for (i = 0; i <n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    for ( i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
           transpose[j][i]=matrix[i][j]; 
        }
        
    }
    printf("\n");

    
    printf("Rotated Game Board(90 degree clock wise)\n");
    for ( i = 0; i <n; i++)
    {
        for ( j = n-1; j >=0; j--)
        {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
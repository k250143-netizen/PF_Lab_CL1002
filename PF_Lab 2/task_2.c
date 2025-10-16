#include<stdio.h>
int main (){
    float unit;
    float bill;

    printf("Enter your consuming unit:");
    scanf("%f", &unit);

    if( unit <= 100){
        bill = unit * 5;
    }
    else if(unit > 100 && unit <= 200){
        bill = (100 * 5) + 7 * (unit - 100);
    }
    else if(unit > 200 && unit <= 300){
        bill = (100 * 5) + (7 * 100) + 10 * (unit - 200);
    }
    else if(unit > 300){
        bill = (100 * 5) + (7 * 100) + (10 * 100) + 15 * (unit - 300);
    }

    printf("Your electricity bill is: %.3f", bill);
    return 0;
    
}
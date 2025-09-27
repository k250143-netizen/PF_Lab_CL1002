#include<stdio.h>
#include<math.h>
int main(){
    float principle_amount;
    float time_years;
    float EMI;
    float rate;
    int interest_type;
    printf("\n----EMI CALCULATOR----\n");
    printf("\nPlease Enter your Principle (loan) Amount = ");
    scanf("%f", &principle_amount);
    printf("Please Enter Your Intrest rate in percentage(without divided by 100) = ");
    scanf("%f", &rate);
    printf("Enter Time in Year = ");
    scanf("%f", &time_years);
    printf("\nInterest Type:\n");
    printf("1. Simple Interst.\n");
    printf("2. compound Interst.\n");
    printf("Sellect Your Interest Type (1-2): ");
    scanf("%d",&interest_type);
    switch (interest_type)
    {
        case 1:{
            EMI = (principle_amount + (principle_amount * (rate/100.0) * time_years)) / (time_years * 12.0);
            break;
        }
        case 2:
        {
            float power = pow((1 + (rate/100.0)), time_years);
            float Total_amount = principle_amount * power;
            EMI = Total_amount / (time_years * 12.0);
            break;
        }
        default:{
            printf("Invalid Interest Type.\n");
            break;
            }  
    }
    printf("Your Monthly EMI For this loan %.2f Rs is = %.2f Rs\n",principle_amount, EMI);

    return 0;
}

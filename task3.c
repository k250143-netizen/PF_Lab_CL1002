#include <stdio.h>
int main() {
    int ID;
    int prime = 1;
    int i;
    printf("Enter ID Please:");
    scanf("%d", &ID);
    if(ID > 1){
        for( i = 2; i < ID /2; i++)
        {
            if(ID % i == 0){
                prime = 0;
                break;
            }    
        }
        if (prime){
            printf("ID:%d is valid.\n",ID);
            printf("-----Prime Number from 2 to %d-----\n",ID);        
            for(int j = 2; j <= ID; j++){
                int prime2 = 1;
                for(int k = 2; k < j; k++){
                    if(j % k == 0){
                        prime2 = 0;
                        break;
                    }
                }
                if(prime2){
                    printf("%d\n",j);
                }          
            }  
        }
        else{
            printf("ID:%d is not valid.\n",ID);
        }
    }
    else{
        printf("ID:%d is not valid.\n",ID);
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	int available=0;
	int maxemptyrow=0;
	int maxemptycount=0;
	int seats[10][10];
	int i,j;
	srand (time(NULL));
	for (i=0;i<10;i++){
		for ( j=0;j<10;j++){
			int random=rand() %2;
			seats[i][j]=random;
		}
	}
	
	for ( i=0;i<10;i++){
		int rowempty=0;
		for ( j=0;j<10;j++){
			if (seats[i][j] ==0){
				
				available=available+1;
				rowempty=rowempty+1;
				
			}
		}
		
		if(rowempty > maxemptycount){
		maxemptycount=rowempty;
		rowempty=i-1; 
		
		}
	
	}
	
	printf("The total number of available seats are : %d \n \n",available);
	printf("The row with max number of available seats is %d and the seats are %d \n \n",maxemptyrow,maxemptycount);
	
		
	return 0;
	
	
}

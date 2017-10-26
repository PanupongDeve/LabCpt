#include<stdio.h>

int main(){
	
	int input,
		isPositive=0,
		isNegative=0,
		i=1;
	
	do{
		printf("N%02d: ",i);
		scanf("%d", &input);
		if(input !=0){
			input > 0 ? isPositive++:isNegative++;
		}
		
		
	}while(input !=0);
	
	printf("Positive = %d", isPositive);
	printf("\nNegative = %d", isNegative);
	
	return 0;
}

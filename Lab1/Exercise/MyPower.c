#include<stdio.h>
#include <stdlib.h>

int main(){
	float base = 0;
	float power = 0;
	int i;
	float result = 1;
	
	scanf("%f", &base);
	scanf("%f", &power);
	
	if(power == 0){
		result = 1;
	}else if(power ==1 ){
		result = base;
	}else if(power > 1){
		for(i=0;i<power;i++){
			result *= base;
		}
	}else{
		power = abs(power);
		for(i=0;i<power;i++){
			result *= base;
		}
		
		result = 1/result;
	}
	
	printf("%.2f", result);
	return 0;
}

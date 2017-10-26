#include<stdio.h>

#define maxNum 99
#define minNum 0
#define maxTurn 10

int main(){
	int i=0,
		ans,
		request;
		
	printf("Host Answer: ");
	scanf(" %d", &ans);
	
	if(ans >=minNum && ans <= maxNum ){
		printf("Success! Game Start.... \n");
		
		
		do{	
			printf("T%02d: ", i+1);
			scanf(" %d", &request);	
			
			if( !(request >=minNum && request <= maxNum) ){
				printf("You Found!");
			}else if (request == ans){
				printf("Victory");
				break;
			}else if (request >= ans-3 && request <= ans+3 ){
				printf("Very close\n");
			}else{
				request < ans ? printf("Too sall\n"):printf("Too large\n");
			}
			
			
			if(i == maxTurn-1 && request != ans){
				printf("Game over\n");	
			}
			
			i++;
				
		}while(i<maxTurn);
		
	}else{
		printf("Fail! ");
	}
	
}

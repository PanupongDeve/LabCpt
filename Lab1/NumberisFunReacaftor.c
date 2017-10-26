#include<stdio.h>


#define maxNum 99
#define minNum 0
#define maxTurn 10
#define RangeError 404


int checkRangeAns(int ans);
void NumberisFunApp(int ans);

int main(){
	int ans = 0;
	
	printf("Host Answer: ");
	scanf("%d", &ans);
			

	ans = checkRangeAns(ans);
	if(ans == RangeError){
		printf("Number is not between 0-99.");
		exit(0);
	}
						
	NumberisFunApp(ans);
}


int checkRangeAns(int ans){
	if(ans >=minNum && ans <= maxNum ){
		return ans;
	}else{
		return RangeError;
	}
	
}

void NumberisFunApp(int ans){
		int i = 0,
			request;
		
		printf("Success! Game Start.... \n");
		do{	
			printf("T%02d: ", i+1);
			scanf(" %d", &request);	
				
			request = checkRangeAns(request);
			if(request == RangeError){
				printf("Number is not between 0-99. \n");
				continue;
			}
			
			if (request == ans){
				printf("Victory");
				break;
			}else if (request >= ans-3 && request <= ans+3 ){
				printf("Very close\n");
			}else{
				request < ans ? printf("Too small\n"):printf("Too large\n");
			}
		
				
			if(i == maxTurn-1 && request != ans){
				printf("Game over\n");		
			}
			
			i++;
				
		}while(i<maxTurn);
		
}



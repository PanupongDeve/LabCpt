#include<stdio.h>
#define LEN 5

int* find_max(int *p,int *q);
void inputNum(int *p);
void outputNum(int *max);
void changArray(int *p,int position);
void showlist(int *p); 

int main(){
	int d[LEN],i,check=0,position;
	int *max;	
	
	
	inputNum(&d[0]);		
	max = find_max(&d[0], &d[1]);
	showlist(&d[0]);
	outputNum(max);
	

	while(1){
		printf("\n\nDo you want to change array?\nyes:<1> no:<0>\n :");
		scanf("%d", &check);
		if(check){
			printf("Chose rank array<1 to 5>: ");
			scanf("%d",&position);
			changArray(&d[0], position-1);
			showlist(&d[0]);
			printf("\n\n ----- new Find max-----");
			max = find_max(&d[0], &d[1]);
			outputNum(max);
			
			continue;
		}else{
			printf("Thank you for Wathching.");
			break;
		}
		
	}
		
	return 0;
}


void inputNum(int *p){
	int i;	
	for(i=0; i<LEN;i++){
		printf("N%02d: ", i+1);
		scanf("%d", p+i);
		if(*(p+i) < 0){
			printf("Number is more than zero.");
			i--;
		}
	}	
}

int* find_max(int *p,int *q){

	int* ptr = p;
	int i;
	
	
		for(i=0; i<LEN;i++){
			if(*(ptr) < *(q+i)){
				ptr = q+i;				
			}
			else{
				continue;
			}
			
		}	
	

	return ptr;
}

void outputNum(int *max){
	printf("\nNumber is Max :%d", *max);
}

void changArray(int *p,int position){
	
	printf("New N%02d: ", position+1);
	scanf("%d", (p+position));

}

void showlist(int *p){
	int i;
	
	printf("=");
	for(i=0; i<LEN;i++){
		printf(" %d", *(p+i));
	}
}

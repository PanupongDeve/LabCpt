#include<stdio.h>
#define LEN 5

int* find_max(int *p,int *q);
void inputNum(int *p);
void outputNum(int *max);
void changArray(int *p,int position); 

int main(){
	int d[LEN],i,check=0,position;
	int* max;	
	
	
	inputNum(&d[0]);		
	max = find_max(&d[0], &d[1]);
	outputNum(d);
	
	while(1){
		printf("\nDo you want to change array?\nyes:<1> no:<0>\n :");
		scanf("%d", &check);
		if(check){
			printf("Chose rank array<1 to 5>: ");
			scanf("%d",&position);
			changArray(&d[0],position-1);
			outputNum(max);
			printf("\n ----- new Sort-----\n");
			max = find_max(&d[0], &d[1]);
			outputNum(max);
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
	int tmp = 0;
	int i,j;
	
	for(i=0; i<LEN;i++){
		for(j=0; j<LEN-1;j++){
			if(*(p+j) < *(q+j)){
				tmp = *(q+j);
				*(q+j) = *(p+j);
				*(p+j) = tmp;
			}
			else{
				continue;
			}
		}	
	}

	return p;
}

void outputNum(int *max){
	int i;
	
	printf("=");
	for(i=0; i<LEN;i++){
		printf(" %d", *(max+i));
	}
}

void changArray(int *p,int position){
	
	printf("New N%02d: ", position+1);
	scanf("%d", (p+position));

}

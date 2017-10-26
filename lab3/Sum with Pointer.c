#include<stdio.h>
#define NUM 5

int sum(int *p, int *q);

int main(){
	int i;
	int a[NUM];
	int result = 0;
	
	for(i=0;i<NUM;i++){
		printf("N%02d: ", i+1);
		scanf("%d", &a[i]);
	}
	
	result = sum(&a[0], &a[NUM]);
	printf("=%d\n", result);
	
	
	return 0;
}

int sum(int *p, int *q){
	int total = 0;
	while( p <= q){
		total += *p;
		p++; 
	}
	
	return total;	
}

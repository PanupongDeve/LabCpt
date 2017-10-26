#include<stdio.h>
#include<stdlib.h>

struct set{
	float factor;
	int amount;
	int *values;
};
typedef struct set SET;

struct v{
	int k;
	SET set;
};
typedef struct v V;

void input_v(V *p);
int sum(int *p,int len);
float f_v(V *p);

int main(){
	int values[128];
	float result;
	
	V v;
	v.set.values = values;
	input_v(&v);
	
	result = f_v(&v);
	printf("f = %.1f", result);
	
	
	
	return 0;
}

void input_v(V *p){
	int k;
	float factor;
	int amount;
	int i;
	int value;
	
	printf("k = ");
	scanf("%d", &k);
	p->k = k;

	
	printf("set.factor= ");
	scanf("%f", &factor);
	p->set.factor = factor;

	
	printf("set.amount = ");
	scanf("%d", &amount);
	p->set.amount = amount;

	
	
	
	printf("set.values = ");
	for(i=0;i<amount;i++){	
		value = 0;	
		scanf(" %d", &value);
		p->set.values[i] = value;	
	}
		
}
float f_v(V *p){
	float f;
	int sum_values;
	int i;
	
	sum_values = sum(p->set.values,p->set.amount);
			
	f = p->k + (p->set.factor * sum_values);
	
	return f;
	
}

int sum(int *p, int len){
	int i;
	int sum = 0;
	

	for(i=0;i<len;i++){
		sum += *p;
		p++;
	}
	return sum;
}

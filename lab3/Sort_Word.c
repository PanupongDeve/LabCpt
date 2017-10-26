#include<stdio.h>
#include<stdlib.h>

#define SIZE 3
#define MAXWORD 128

void sort_words(char *w[], int numm);
void string_swap(char *a,char *b);

int main(){
	char *w[SIZE];
	char word[MAXWORD];
	int num, i;
	for(i=0;i<SIZE;i++){
		printf("w[%d] = ", i);
		scanf("%s", word);
		w[i] = calloc(strlen(word)+1, sizeof(char));
		strcpy(w[i], word);
	}
	
	
	printf("------Befor Min Sort--------\n");
	for(i=0;i<SIZE;i++){
		printf("%s\n",w[i]);
	}
	
	sort_words(w, SIZE);
	
	printf("------Befor Min Sort--------\n");
	for(i=0;i<SIZE;i++){
		printf("%s\n",w[i]);
	}
	return 0;
}

void sort_words(char *w[], int num){
	
	int i,j;
	for(i=0;i<num;i++){
		for(j=0;j<num-1;j++){
			if(strlen(*(w+j)) < strlen(*(w+j+1))){
				string_swap(*(w+j),*(w+j+1));
			}
		}
	}
}

void string_swap(char *a,char *b){	
	char *buf;
	buf = a;
	a=b;
	b=buf;
}
	


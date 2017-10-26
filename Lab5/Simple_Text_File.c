#include <stdio.h>
#include <stdlib.h>

int readFile();
int parseInt(char line[]); 

int main(){
	int sum = 0;
	sum = readFile();
	printf("= %d", sum);
	return 0;
}

int readFile(){
	int sum = 0;
	char line[128];
	int number;
	FILE *fp = fopen("num.txt", "r");
	
	while(!feof(fp)){
		fscanf(fp, " %[^\n]s", line);
		printf("%s \n",line);
		number = parseInt(line);
		sum += number;
	}
	
	fclose(fp);
	
	return sum;
}

int parseInt(char line[]){
	int number;
	
	number = atoi(line);
	
	return number;
}

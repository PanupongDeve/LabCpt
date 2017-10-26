#include <stdio.h>

char* replace_space(char* s);

int main(){
	char message[128];
	char* result;
		
	printf("Enter: ");
	gets(message);
	
	result = replace_space(message);
	if(*result == NULL){
		printf("I Have a NULL!!!!!\n");
	}
	printf("= %s",result);
	return 0;
}

char* replace_space(char* s){
	int int_space = (int)' ';
	int int_message;
	int state = 0;
	char* ptr = s; 	
	char charactor; 
	
	printf("Char: ");
	scanf("%c", &charactor);
	
	while(*s != '\0'){
		int_message = (int)*s;
		if(int_message == int_space ){
			state = 1;
			*s = charactor;
		}	
		s++;
	}
	
	if(state){
		return ptr;
	}else{
		*ptr = NULL;
		return ptr;
	}	
}

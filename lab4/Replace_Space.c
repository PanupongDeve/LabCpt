#include <stdio.h>

void replace_space(char* s, char c);

int main(){
	char message[128];
	char charactor;
		
	printf("Enter: ");
	gets(message);
	printf("Char: ");
	scanf("%c", &charactor);
	printf("=");
	
	replace_space(message,charactor);
	return 0;
}

void replace_space(char* s, char c){
	int int_space = (int)' ';
	int int_message;
	char* ptr = s; 
	 
	while(*s != '\0'){
		int_message = (int)*s;
		if(int_message == int_space ){
			*s = c;
		}	
		s++;
	}
	
	printf("%s",ptr);
}

#include<stdio.h>

char* find_char(char s[], int c);

int main(){
	char str[128];
	int cint;
	char c;
	char* result;
	
	printf("S:");
	gets(str);
	printf("C:");
	scanf(" %c", &c);
	cint = (int)c;

	
	result = find_char(str, cint);
	
	printf("= %c", *result);
	
	return 0;
}

char* find_char(char s[], int c){
	char* ptr = &s[0];
	int i;
	int ptrInt;
	
	for(i=0;i<128;i++){
		ptrInt = (int)s[i];
		
		if(c == ptrInt){
			ptr = &s[i]+1;
			return ptr;			
		}else if(s[i] == '\0'){
			ptr = &s[i];
			return ptr;
		}

	} 
	
}


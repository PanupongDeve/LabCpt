#include<stdio.h>

char enc_char(char c);
int check_char(char c);

int main(){
	char c,str[200];
	int i=0,result=0;
	
	printf("msg :");
	
	while(1){
		c = getchar();
		if(c == EOF){
			break;
		}
		c = enc_char(c);
		printf("%c", c);
	}
	

	c = getchar();
	printf("%c", c);


	
	return 0;
}
char enc_char(char c){
	int cInt = 0;
	
	if( check_char(c) == 0 ){
		cInt = (int)c+2;
		return (char)cInt;
	}else if( check_char(c) == 1 ){
		cInt = (int)c-1;
		return (char)cInt;
	}else{
		return c;
	}
}

int check_char(char c){
	int asciibeforea = (int)'a'-1,
		asciiafterz = (int)'z'+1,
		asciibeforeA = (int)'A'-1,
		asciiafterZ = (int)'Z'+1,
		cInt = (int)c;
		
		if(cInt > asciibeforea && cInt < asciiafterz){
			return 0;
		}else if(cInt > asciibeforeA && cInt < asciiafterZ){
			return 1;
		}else {
			return -1;
		}
		
		
		
	
	
}

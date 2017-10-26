#include <stdio.h>
void to_next(char* cptr);
int main(){
	char c;
	printf("Enter: ");
	to_next(&c);
	
	
	
	return 0;
}

void to_next(char* cptr){
	int AsciiBefora = (int)'a'-1;
	int AsciiAfterz = (int)'z'+1;
	int cptrInt;
	char message;
	
	scanf("%c",cptr);
	cptrInt = (int)*cptr;
	printf("=");
	if(cptrInt>AsciiBefora && cptrInt<AsciiAfterz){
		if( cptrInt == AsciiAfterz-1 ){
			printf(" a");
		}else{
			cptrInt++;
			message = (char)cptrInt;
			printf(" %c",message);
		}
	}else{
		printf("Input fail!!!");
	}
}

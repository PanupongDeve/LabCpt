#include<stdio.h>


int main(){
	int AsciiBeforea = (int)'a'-1,
		AsciiAfterz  = (int)'z'+1,
		AsciiBeforeA = (int)'A'-1,
		AsciiAfterZ = (int)'Z'+1;
	char input;
	int inputInt;
		
		
	
	do{ 
		printf("Char: ");
		scanf(" %c", &input);
		inputInt = (int)input;
		
		
		if(inputInt > AsciiBeforea && inputInt < AsciiAfterz){ 
			printf("%d \n", inputInt-AsciiBeforea);		
		}else if(inputInt > AsciiBeforeA && inputInt < AsciiAfterZ ){
			printf("%d \n", inputInt-AsciiBeforeA);
		}else{
			printf("End ");
			break;
		}
	}while(1);
	
}

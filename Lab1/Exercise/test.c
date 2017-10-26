#include<stdio.h>
#define AsciiBeforeUpper 64
#define AsciiAfterUpper 91
#define AsciiBeforeLetter 96
#define AsciiAfterLetter 123
int main(){
	char input = 'D';
	int inputInt,
		result ,
		i = 1 ;
		
	
	do{ 
		printf("Char: ");
		scanf(" %c", &input);
		inputInt = (int)input;
		
		//UpperCheck
		if(inputInt > AsciiBeforeUpper && inputInt < AsciiAfterUpper){
			printf("%d \n", inputInt-AsciiBeforeUpper);		
		}else if(inputInt > AsciiBeforeLetter && inputInt < AsciiAfterLetter ){//LetterCheck
			printf("%d \n", inputInt-AsciiBeforeLetter);
		}else{
			printf("End ");
			break;
		}
	}while(i);
	
}

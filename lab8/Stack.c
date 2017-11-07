#include<stdio.h>

struct listnode{
	int data;
	struct listnode *next;
};

typedef struct listnode ListNode;
typedef ListNode *ListNodePtr;

typedef struct{
	int size;
	ListNodePtr top;
} Stack;

void push(Stack *StackPtr, int value);
int  pop(Stack *StackPtr);
int isOperand(char c);
int isOperator(char c);
int cal(int a, int b, char c);
int getPostFix(Stack *StackPtr,char *text);

//debug function
void showStack(Stack *StackPtr);

//Bonus function
void reverseStack(Stack *StackPtr);

int main(){
	Stack stack ={0,NULL};
	int result = 0;
	char text[128];
	scanf("%[^\n]s",text);
	printf("%d",getPostFix(&stack,text));
	
	
	//push(&stack,7);
	//push(&stack,8);
	//push(&stack,9);
	//showStack(&stack);
	//reverseStack(&stack);
	//showStack(&stack);
	return 0;
}


int getPostFix(Stack *StackPtr,char *text){
	int a;
	int b;
	int result;
	
	while(*text != '\0'){
		if(isOperand(*text)){
			push(StackPtr, *text-48);
		}else if(isOperator(*text)){
			a = pop(StackPtr);
			b = pop(StackPtr);
			push(StackPtr, cal(a,b,*text));
		}else{
			printf("Input Error");
			exit(0);
		}	
		text++;
	}
	
	if(StackPtr->size == 1){
		result = pop(StackPtr);
		return result;
	}else{
		printf("Input Error");
		exit(0);
	}
	
}

int cal(int a,int b,char c) {
	if( c == '+') {
		return a+b;
	}else if( c=='-'){
		return a-b;
	}else if (c=='/'){
		return a/b;
	}else if (c=='*'){
		return a*b;
	}
}

int isOperand(char c){
	if(c >= '0' && c <= '9'){
		return 1;
	} else{
		return 0;
	}
}

int isOperator(char c){
	if(c=='+' || c=='-' || c=='/' || c=='*'){
		return 1;
	} else {
		return 0;
	}
}


void push(Stack *StackPtr, int value){
	ListNodePtr newNodePtr;
	ListNodePtr HeadPtr = StackPtr->top;
	
	//Create New Data
	newNodePtr = (ListNodePtr)malloc(sizeof(ListNode));
	newNodePtr->data = value;
	newNodePtr->next = NULL;
	
	//Chang Top is New Data
	newNodePtr->next = StackPtr->top;
	StackPtr->top = newNodePtr;
	
	//increase Size
	StackPtr->size++;

	
}

int pop(Stack *StackPtr){
	int popvalue = 0;
	
	if(StackPtr->size == 0 ){
		printf("Input Error\n");
		exit(0);
	}
	
	//Chang Top
	ListNodePtr TempPtr = StackPtr->top;
	StackPtr->top = StackPtr->top->next;
	
	//input value pop
	popvalue = TempPtr->data;
	
	//deleteNode
	free(TempPtr);
	
	//decrease Size
	StackPtr->size--;
	return popvalue;
}


void showStack(Stack *StackPtr){
	ListNodePtr HeadPtr = StackPtr->top;
	
	
	printf("Size : %d\n", StackPtr->size);
	
	if(HeadPtr == NULL){
		printf("Stack is Empty");
	}else{
		printf("TOP\n");
		while(HeadPtr != NULL){
			printf("%d\n",HeadPtr->data);	
			HeadPtr = HeadPtr->next;
		}
		printf("NULL\n");		
	}
				
}

void reverseStack(Stack *StackPtr){
	ListNodePtr HeadPtr = StackPtr->top;
	ListNodePtr currentPtr = HeadPtr;
	ListNodePtr currentPtr2 = HeadPtr;
	
	//1st Node
	HeadPtr = HeadPtr->next;
	currentPtr->next = NULL;
	
	while(HeadPtr != NULL){
		currentPtr = HeadPtr;
		HeadPtr = HeadPtr->next;
		currentPtr->next = currentPtr2;
		currentPtr2 = currentPtr;
	}
	
	StackPtr->top = currentPtr;
	
}


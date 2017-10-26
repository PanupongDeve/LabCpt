#include <stdio.h>
#include <stdlib.h>

struct listnode {
	int data;
	struct listnode *next; 
};

typedef struct listnode ListNode;
typedef ListNode *ListNodePtr;

void insert_at_front(ListNodePtr *HeadPtr,int value);
void print(ListNodePtr HeadPtr);
int sum(ListNodePtr HeadPtr);

int main(){
	ListNodePtr Head = NULL;
	int data;
	int result;
	printf("Enter: ");
	do{
		scanf(" %d", &data);
		if(data > 0){
			insert_at_front(&Head, data);
		}
	}while(data > 0);
	
	print(Head);
	result = sum(Head);
	printf("\n= %d", result);
	
	return 0;
}

void insert_at_front(ListNodePtr *HeadPtr,int value){
	ListNodePtr newPtr;
	
	newPtr = (ListNodePtr)malloc(sizeof(ListNode));
	
	newPtr->data = value;
	newPtr->next = NULL;
	
	newPtr->next = *HeadPtr;
	*HeadPtr = newPtr;	
}

void print(ListNodePtr HeadPtr){
	ListNodePtr currentPtr;
	currentPtr  = HeadPtr;
	if(currentPtr == NULL){
		printf("List is Empty\n");
	} else{
		printf("= ");
		while(currentPtr != NULL){
			printf("%d ", currentPtr->data);
			currentPtr = currentPtr->next;
		}
	}
}

int sum(ListNodePtr HeadPtr){
	int result = 0;
	ListNodePtr currentPtr;
	currentPtr  = HeadPtr;
	
	if(currentPtr == NULL){
		return 0;
	} 
	while(currentPtr != NULL){
		result += currentPtr->data;
		currentPtr = currentPtr->next;
	}	
	return result;
}


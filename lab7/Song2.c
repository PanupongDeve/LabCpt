#include<stdio.h>
#include<string.h>

struct song{
	char title[128];
	double duration;
};
typedef struct song Song;

struct listnode{
	Song *sp;
	struct listnode *next;
};
typedef struct listnode ListNode;
typedef ListNode *ListNodePtr;


Song *input_song();
void insert(ListNodePtr *HeadPtr, Song *sp);
void insertSongtoList(Song *SongData, Song *BufferPtr);
ListNodePtr find_tail(ListNodePtr HeadPtr);
double sum_duration(ListNodePtr HeadPtr);
void printSongDetail(ListNodePtr HeadPtr);

int main() {
	ListNodePtr Head = NULL;
	Song *sp = NULL;
	int i;

	
	for(i=0;i<5;i++){
		printf("#### INPUT SONG %d \n",i);
		sp = input_song();
		insert(&Head,sp);
	}
	
	printSongDetail(Head);
	
	printf("= %.2f\n", sum_duration(Head));
	
	
	return 0;
}


void insert(ListNodePtr *HeadPtr, Song *sp){
	ListNodePtr newPtr;
	ListNodePtr tailPtr;
	
	//insert SongData to newPtr;
	newPtr = (ListNodePtr)malloc(sizeof(ListNode));
	newPtr->sp = sp;
	//insertSongtoList(newPtr->sp, sp);
	newPtr->next = NULL;
	
	//find tailPtr
	tailPtr = find_tail(*HeadPtr);
	if(tailPtr == NULL){
		*HeadPtr = newPtr;
	}else{
		tailPtr->next = newPtr;
	}
	
	
}

void insertSongtoList(Song *SongData, Song *BufferPtr){
	strcpy(SongData->title, BufferPtr->title);
	SongData->duration = BufferPtr->duration;
}

double sum_duration(ListNodePtr HeadPtr) {
	double result = 0;
	if(HeadPtr == NULL) {
		return 0;
	}
	
	while(HeadPtr != NULL){
		result += HeadPtr->sp->duration;
		HeadPtr = HeadPtr->next;
	}
	
	return result;
}

Song *input_song(){
	Song *song;
	song = (Song*)malloc(sizeof(Song));
	printf("Title: ");
	scanf("%s", song->title);
	printf("Duration: ");
	scanf("%lf", &song->duration);
	
	return song;	
}

ListNodePtr find_tail(ListNodePtr HeadPtr){
	ListNodePtr tailPtr = NULL;
	
	if(HeadPtr == NULL){
		return NULL;
	}
	
	tailPtr = HeadPtr;
	while(tailPtr->next != NULL){
		tailPtr = tailPtr->next;
	}
	
	return tailPtr;
}

void printSongDetail(ListNodePtr HeadPtr) {
	if(HeadPtr == NULL){
		printf("SongList is Empty!\n");
	}
	
	while(HeadPtr != NULL){
		printf("%s : %.2f\n", HeadPtr->sp->title, HeadPtr->sp->duration);
		HeadPtr = HeadPtr->next;
	}
}



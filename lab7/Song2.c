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
	Song *sp;
	
	sp = input_song();
	
	printf("%s : %.2f",sp->title,sp->duration);
	
	return 0;
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
		printf("SongList is Empty!");
	}
	
	while(HeadPtr != NULL){
		printf("%s : %.2f\n", HeadPtr->sp->title, HeadPtr->sp->duration);
		HeadPtr = HeadPtr->next;
	}
}



#include<stdio.h>
#include<string.h>

struct song{
	char title[128];
	double duration;
};
typedef struct song Song;

struct listnode{
	Song s;
	struct listnode *next;
};

typedef struct listnode ListNode;
typedef ListNode *ListNodePtr;

void insert(ListNodePtr *HeadPtr, Song *sp);
void insertSong(Song *SongData,Song *buf);
void printSongDetail(ListNodePtr HeadPtr);
ListNodePtr find_tail(ListNodePtr HeadPtr);
double sum_duration(ListNodePtr HeadPtr);

int main() {
	ListNodePtr Head = NULL;
	Song buf;
	int i= 0;
	
	for(i=0;i<5;i++){
		printf("Title[%d]: ", i);
		scanf("%s",buf.title);
		printf("duration[%d]: ", i);
		scanf("%lf", &buf.duration);
		insert(&Head,&buf);
	}
	
	printSongDetail(Head);
	
	printf("= %.2f",sum_duration(Head));
	
	
	
	return 0;
}

double sum_duration(ListNodePtr HeadPtr) {
	double result = 0;
	if(HeadPtr == NULL) {
		return 0;
	}
	
	while(HeadPtr != NULL){
		result += HeadPtr->s.duration;
		HeadPtr = HeadPtr->next;
	}
	
	return result;
}

void printSongDetail(ListNodePtr HeadPtr) {
	if(HeadPtr == NULL){
		printf("SongList is Empty!");
	}
	
	while(HeadPtr != NULL){
		printf("%s : %.2f\n",HeadPtr->s.title, HeadPtr->s.duration);
		HeadPtr = HeadPtr->next;
	}
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

void insert(ListNodePtr *HeadPtr,Song *sp){
	ListNodePtr newPtr;
	ListNodePtr tailPtr;
	
	newPtr = (ListNodePtr)malloc(sizeof(ListNode));
	
	insertSong(&newPtr->s, sp);
	newPtr->next = NULL;
	
	tailPtr = find_tail(*HeadPtr);
	
	if(tailPtr == NULL){
		*HeadPtr = newPtr;
	}else {
		tailPtr->next = newPtr;
	}
	
}

void insertSong(Song *SongData, Song *buf){
	strcpy(SongData->title,buf->title);
	SongData->duration = buf->duration;
}

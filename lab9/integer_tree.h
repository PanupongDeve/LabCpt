#include<stdio.h>

struct treenode{
	struct treenode *leftptr;
	int data;
	struct treenode *rightptr;
};

typedef struct treenode TREENODE;
typedef TREENODE *TREE;

void insert_node(TREE *tp, int value) {
	if(*tp == NULL) {
		*tp = malloc(sizeof(TREENODE));
		(*tp)->data = value;
		(*tp)->leftptr = NULL;
		(*tp)->rightptr = NULL;
	} else if(value < (*tp)->data) {
		insert_node(&((*tp)->leftptr),value);
	} else if(value > (*tp)->data) {
		insert_node(&((*tp)->rightptr),value);
	} else{
		printf("duplicate node \n");
		exit(0);
	}
}


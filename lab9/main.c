#include<stdio.h>
#include "integer_tree.h"

int is_completed_tree(TREE t);
int maxDepth(TREE t);
int is_perfect_tree(TREE t);
int is_equal_depth(TREE t);

int main(){
	TREE t = NULL;
	
	int tmp;
	int i=0;
	
	do{	
		printf("N%02d:", i+1);
			scanf("%d", &tmp);
			if(tmp <= 0){
				break;
			}
			insert_node(&t,tmp);
			i++;
	}while(tmp > 0);
	
	
	//printf("%d\n", is_equal_depth(t));
	printf("=%s\n", is_perfect_tree(t) ? "yes" : "No");
	

	return 0;
}



int is_perfect_tree(TREE t){
	if(is_equal_depth(t) && is_completed_tree(t) ){
		return 1;
	} else {
		return 0;
	}
}

int is_equal_depth(TREE t) {
	int ldepth;
	int rdepth;
	
	if(t->leftptr == NULL && t->rightptr == NULL) {
		return 1;
	}
	
	ldepth = maxDepth(t->leftptr);
	rdepth = maxDepth(t->rightptr);
	
	if(ldepth == rdepth){
		return 1;
	} else {
		return 0;
	}
}


int maxDepth(TREE t) {
	int ldepth;
	int rdepth;
	
	if(t == NULL){
		return 0;
	}
	
	ldepth = maxDepth(t->leftptr);
	rdepth = maxDepth(t->rightptr);
	
	if(ldepth > rdepth){
		return (ldepth+1);
	} else {
		return (rdepth+1);
	}
	 
}

int is_completed_tree(TREE t){
	// empty tree is perfect
	if(t == NULL){
		return 1;
	}
	
	//in dept node
	if(t->leftptr == NULL && t->rightptr == NULL){
		//printf("true\n");
		return 1;	
	}
		
	else if(t->leftptr == NULL || t->rightptr == NULL){
		/*printf("%d",t->data);
		printf("BUG\n");*/
		return 0;
	}
	
		
	//have subtree
	return is_perfect_tree(t->leftptr) && is_perfect_tree(t->rightptr);
}

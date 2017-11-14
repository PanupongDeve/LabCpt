#include<stdio.h>
#include "tree.c"

int main(){
	TREE t = NULL;
	
	t = getTree();
	
	/*if(is_empty_tree(t)){
		printf("Tree is Empty!");
	} else {
		printf("Tree have data!!");
	}*/
	
	printf("%d", root_value(t));
	
	
	return 0;
}

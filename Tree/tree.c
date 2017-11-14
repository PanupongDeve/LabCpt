#include<stdio.h>
struct treenode {
	struct treenode *left;
	int data;
	struct treenode *right;
};

typedef struct treenode TREENODE;
typedef TREENODE *TREE;

TREE getTree() {
	TREE t = NULL;
	t = (TREE)malloc(sizeof(TREENODE));
	t->data = 2;
	
	t->left = (TREE)malloc(sizeof(TREENODE));
	t->left->data = 1;
	t->left->left = NULL;
	t->left->right = NULL;
	
	return t;
}

int is_empty_tree(TREE t){
	if(t == NULL)
		return 1;
	else
		return 0;
}

int root_value(TREE t){
	if(is_empty_tree(t)) {
		fprintf(stderr, "Tree is empty \n");
		return -1;
	} else {
		return t->data;
	}
}

TREE mk_tree(int x, TREE left_tree, TREE right_tree) {
	TREE temp;
	
	temp = (TREE) malloc(sizeof(TREENODE));
	temp->data = x;
	temp->left = left_tree;
	temp->right = right_tree;
	
	return temp;
}

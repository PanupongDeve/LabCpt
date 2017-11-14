struct treenode {
	struct treenode *left;
	int data;
	struct treenode *right;
};

typedef struct treenode TREENODE;
typedef TREENODE *TREE;

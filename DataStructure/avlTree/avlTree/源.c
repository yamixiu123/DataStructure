#include<stdio.h>
#include<stdlib.h>

typedef struct root {
	int height;
	int val;
	struct root* leftTree;
	struct root* rightTree;
}root;

typedef struct root* TreeNode;

int getHeight(TreeNode T) {
	if (T == NULL) {
		return -1;
	}
	else {
		return T->height;
	}
	
}

void llRoration(TreeNode *root,TreeNode T){
	TreeNode p=T->leftTree;
	T->leftTree = p->rightTree;
	p->rightTree = T;
	T->height = getMax(getHeight(T->leftTree), getHeight(T->rightTree)) + 1;
	p->height = getMax(getHeight(p->leftTree), getHeight(p->rightTree)) + 1;
	*root = p;
}

void rrRoration(TreeNode* root, TreeNode T) {
	TreeNode p = T->rightTree;
	T->rightTree = p->leftTree;
	p->leftTree = T;
	T->height = getMax(getHeight(T->leftTree), getHeight(T->rightTree)) + 1;
	p->height = getMax(getHeight(p->leftTree), getHeight(p->rightTree)) + 1;
	*root = p;
}

void lrRoration(TreeNode* root, TreeNode T) {
	rrRoration(&(T)->leftTree, T->leftTree);
	llRoration(root, T);
}//×óº¢×ÓÓÒÐý£¬root×óÐý

void rlRoration(TreeNode* root, TreeNode T) {
	llRoration(&(T)->rightTree, T->rightTree);
	rrRoration(root, T);
}


int getMax(int a, int b) {
	return a > b ? a : b;
}

void printTree(TreeNode T) {
	if (T->leftTree != NULL && T->rightTree != NULL) {
		printTree(T->leftTree);
	}
	printf("%d\n", T->val);
	if (T->rightTree != NULL) {
		printTree(T->rightTree);
	}
}
void avlInsert(TreeNode* T, int val) {
	if (*T == NULL) {
		*T = (TreeNode)malloc(sizeof(root));
		if (*T == NULL) {
			printf("Memory is full!\n");
			return;
		}
		(*T)->val = val;
		(*T)->height = 0;
		(*T)->leftTree = (*T)->rightTree = NULL;
	}//³õÊ¼»¯NULL½Úµã
	else if ((*T)->val > val) {  
		avlInsert(&(*T)->leftTree, val);
		int lHeight = getHeight((*T)->leftTree);
		int rHeight = getHeight((*T)->rightTree);
		if (lHeight - rHeight ==2) {
			if (val > (*T)->leftTree->val) {
				lrRoration(&(*T)->leftTree, (*T)->leftTree);
			}
			else {
				llRoration(T,*T);
			}
		}
		else if (rHeight - lHeight == 2) {
			if (val < (*T)->rightTree->val) {
				rlRoration(&(*T)->rightTree, (*T)->rightTree);
			}
			else {
				rrRoration(T, *T);
			}
		}

	}
	// ¸ù×óÊ÷

	else if ((*T)->val < val) {
		avlInsert(&(*T)->rightTree, val);
	}// ¸ùÓÒÊ÷

	(*T)->height = getMax((*T)->leftTree, (*T)->rightTree)+1;
}


int main(void){
	TreeNode T = NULL;
	int nums[5] = { 1,8,6,7,10 };
	for (int i = 0; i < 5; i++) {
		avlInsert(&T, nums[i]);
	}
	printTree(T);


	return 0;
}
#include<stdio.h>
#include<stdlib.h>

struct TreeNode;
typedef struct TreeNode* Position;
typedef struct TreeNode* SearchTree;

SearchTree makeEmpty(SearchTree T);
Position find(int x, SearchTree T);//二分查找
Position findMin(SearchTree T);
Position findMax(SearchTree T);
SearchTree insert(int x, SearchTree T);
SearchTree delete(int x, SearchTree T);
void printTree(SearchTree T);
int retrieve(Position p);

struct TreeNode {
	int val;
	SearchTree leftChild;
	SearchTree rightChild;
};

SearchTree makeEmpty(SearchTree T) {
	if (T != NULL) {
		makeEmpty(T->leftChild);
		makeEmpty(T->rightChild);
		free(T);
	}
	return NULL;
}

Position find(int x, SearchTree T) {
	if (T != NULL) {
		if (T->val > x) {
			return T->leftChild;
		}
		else if (T->val < x) {
			return T->rightChild;
		}
		else
		{
			return T;
		}
	}
	return NULL;
}

Position findMin(SearchTree T) {
	if (T->leftChild != NULL) {
		return findMin(T->leftChild);
	}
	else if (T == NULL) {
		return NULL;
	}
	return T;
}

Position findMax(SearchTree T) {
	if (T->rightChild != NULL) {
		return findMin(T->rightChild);
	}
	else if (T == NULL) {
		return NULL;
	}
	return T;
}

SearchTree insert(int x, SearchTree T) {
	if (T == NULL) {
		T = malloc(sizeof(struct TreeNode));
		if (T == NULL) {
			printf("Memory is full\n");
		}
		else {
			T->val = x;
			T->leftChild = NULL;
			T->rightChild = NULL;
		}
	}//创建新树
	else if (x > T->val) {
		T->rightChild = insert(x, T->rightChild);
	}//大于往右走
	else if (x < T->val) {
		T->leftChild = insert(x, T->leftChild);
	}//小于往左走
	return T;
}

SearchTree delete(int x, SearchTree T) {
	Position tmpCell;
	if (T == NULL) {
		printf("Element not find\n");
	}
	else if (T->val > x) {
		T->leftChild=delete(x, T->leftChild);
	}
	else if (T->val < x) {
		T->rightChild = delete(x, T->rightChild);
	}
	else if (T->leftChild != NULL && T->rightChild != NULL) {
		tmpCell = findMin(T->rightChild);
		T->val = tmpCell->val;
		T->rightChild=delete(tmpCell->val, T->rightChild);
	}//double childs
	else {
		tmpCell = T;
		if (T->rightChild == NULL && T->leftChild != NULL) {
			T = T->leftChild;
		}//no right child
		else if (T->leftChild == NULL && T->rightChild != NULL)
		{
			T = T->rightChild;
		}
		else {
			T = NULL;
		}
		//no left child
		free(tmpCell);
	}//single child
	return T;//返回上层
}

void printTree(SearchTree T) {
	if (T == NULL) {
		printf("Please create Tree first\n");
		return;
	}
	else if (T->leftChild != NULL) {
		printTree(T->leftChild);
	}
	printf("node val is %d\n", T->val);
	if (T->rightChild != NULL) {
		printTree(T->rightChild);
	}
	return;
}



int main() {
	int a = 1;
	int b = a++;

	printf("b=%d,a=%d", b,a);
	return 0;
}

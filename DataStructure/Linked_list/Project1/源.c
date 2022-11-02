#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>





//函数原型声明


struct Node* createHeaderNode(); //返回一个链表类型的指针

void insertFirst(struct Node* header, int x);
void insertLirst(struct Node* header, int x);

struct Node* find(struct Node* header, int x);

struct Node* findKth(struct Node* header, int position);

void delete(struct Node* header, int x);

bool isEmpty(struct Node* header);

int size(struct Node* header);

void printList(struct Node* header);





typedef struct Node {
	int element;//节点内含元素,类型为int
	struct Node*  next;//存储下一个节点的指针
	
}Node;

//创建表头
Node* createHeaderNode() {
	Node* header = NULL; //初始化指针

	header = malloc(sizeof(Node));//动态分配头指针

	if (header == NULL) {

		printf("初始化失败");
		exit(1);
	}

	header->next = NULL;//初始化次节点地址

	return header;

};

//判断表是否为空实现

bool isEmpty(struct Node* header) {

	return header->next == NULL;
}


int main(void) {
	//创建头结点
	Node* header = createHeaderNode();

	//判断表是否为空
	if (isEmpty(header)) {
		printf("List is empty\n");
	}
	else {
		printf("List is not empty\n");
	}

	//从表头插入
	insertFirst(header, 1);
	insertFirst(header, 2);

	//从尾部插入
	insertLast(header, 3);
	insertLast(header, 4);




	return 0;
}
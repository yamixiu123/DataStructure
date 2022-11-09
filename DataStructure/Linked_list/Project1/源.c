#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>





//函数原型声明


struct Node* createHeaderNode(); //返回一个链表类型的指针

void insertFirst(struct Node* header, int x);
void insertLast(struct Node* header, int x);

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

bool isEmpty(Node* header) {

	return header->next == NULL;
}




//从表头插入 

void insertFirst(Node* header, int x) {
	Node* tmp = NULL;
	tmp = (Node*)malloc(sizeof(Node));
	tmp->element = x;//存入值
	tmp->next = header->next;//二号节点次指针指向 头指针的次节点
	header->next = tmp;
}

void insertLast(Node* header, int x) {
	Node* tmp = NULL;
	tmp = (Node*)malloc(sizeof(Node));
	tmp->element = x;//存入值
	tmp->next = NULL;

	Node* p = header;
	while ((p->next)!=NULL) {
		p = p->next;
	}//递推到最后一个元素

	p->next = tmp;//指向tmp
}
void printList(Node* header) {
	Node* p = NULL;

	p = header->next;
	while ((p) != NULL) {
		printf("%d\n", p->element);
		p = p->next;

	}
}

void delete(struct Node* header, int x) {
	Node* p = header->next;
	Node* priviouse = header;
	if (p == NULL) {
		printf("this is a void list\n");
		return;
	}
	while (p != NULL) {
		if (p->element == x) {
			priviouse->next = p->next;
			free(p);
			printf("delete success\n");
			return;
		}
		else {
			priviouse = p;
			p = p->next;
		}
	}


	printf("Can not find the element\n");
}


//find 函数 没找到返回NULL
Node* find(struct Node* header, int x) {
	Node* p = header->next;

	while (p != NULL && p->element != x) {
		p = p->next;
	}
	return p;
}

struct Node* findKth(struct Node* header, int position) {
	int count = 1;
	Node* p = header->next;

	if (position <=0)
	{
		printf("position can not be minus number\n");
		return NULL;
	}

	while (p!=NULL)
	{
		if (count==position)
		{
			printf("have found the %d position node\n", position);
			return p;
		}
		p = p->next;
		count++;
	}
	printf("not find the position\n");
	return p;

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

	//从表头插入，给其赋值为1 ,2 
	insertFirst(header, 1);
	insertFirst(header, 2);

	printList(header);
	printf("====================\n");


	//从尾部插入,给其赋值为3,4
	insertLast(header, 3);
	insertLast(header, 4);

	printList(header);

	Node* node = find(header, 100);
	if (node == NULL) {

		printf("not find....\n");
	}
	else {
		printf("found the node element %d", node->element);
	}

	Node* node1 = findKth(header, 10);

	delete(header, 10);

	printList(header);
	

	return 0;
}
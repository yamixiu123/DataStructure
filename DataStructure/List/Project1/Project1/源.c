#include<stdio.h>
#include<stdbool.h>

#define SIZE 100

struct List* creatList();

//增
void insertFirst(struct List* p, int x);
void insertLast(struct List* p, int x);

//删
void delete(struct List* p, int x);

//查

int find(struct List* p, int x);
int findKth(struct List* p, int position);

//改
void change(struct List* p, int x);
void changeKth(struct List* p, int position);

//打印

void printList(struct List* p);


typedef struct List {
	int elements[SIZE];
	int length;

}List;

//创建空表
List* createList() {
	List* p;
	p = (List*)malloc(sizeof(List));
	p->length = 0;
	return p;
}

bool isEmpty(List* p) {
	return p->length == 0;
}

void printList(struct List* p) {
	int i;
	if (isEmpty(p)) {
		printf("the list is empty\n");
		return;
	}
	for (i = 0; i <(p->length); i++) {
		printf("%d\n", p->elements[i]);
	}
}

void insertFirst(struct List* p, int x) {
	int length = p->length;
	if (length >= SIZE) {
		printf("the list is full\n");
		return;
	}
	for (; length > 0; length--) {
		p->elements[length] = p->elements[length - 1];
	}
	p->elements[0] = x;
	p->length++;
	
}

void insertLast(struct List* p, int x) {
	int length = p->length;

	if (length >= SIZE) {
		printf("the list is full\n");
		return;
	}

	p->elements[length] = x;

	p->length++;
}

void delete(struct List* p, int x) {
	int i;
	int length = p->length;
	for ( i = 0; i < length; i++)
	{
		if (p->elements[i] == x) {
		for (; i < length; i++) {
			 
			p->elements[i] = p->elements[i + 1];
			
		}

		p->length--;
		printf("delete success\n");
		return;
		}

	}
	printf("can not find detination\n");

}

int find(struct List* p, int x) {
	int length = p->length;
	for (int i = 0; i < length; i++) {
		if (p->elements[i]==x)
		{
			printf("find target,kth is %d\n", i);
			return i;
		}
	}
	return -1;
}



int main() {
	List* list1 = createList();
	printList(list1);
	insertFirst(list1, 4);

	printList(list1);

	insertLast(list1, 5);
	insertLast(list1, 6);

	delete(list1, 10);
	int res = find(list1, 5);
	if (res == -1) {
		printf("cant find it");
	}

	



	return 0;
}
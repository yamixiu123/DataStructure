#include<stdio.h>
#include<stdbool.h>

#define SIZE 100

struct List* creatList();

//增
void insert(struct List* p, int x);
void insertFirst(struct List* p, int x);
void insertLirst(struct List* p, int x);

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
	if (p->length == 0) {
		printf("this is a NULL list\n");
		return;
	}


}


int main() {
	List* list1 = createList();
	printList(list1);



	return 0;
}
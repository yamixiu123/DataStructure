#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MINIUMSIZE  5
#define MINDATA  -999
struct heapStruct;
typedef struct heapStruct* priorityQueue;

priorityQueue initialize(int maxElements);

bool isEmpty(priorityQueue H);
bool isFull(priorityQueue H);

void destroy(priorityQueue H);
void makeEmpty(priorityQueue H);
void insert(priorityQueue H, int x);

int deleteMin(priorityQueue H);
int findMin(priorityQueue H);


struct heapStruct {
	int capacity;//初始容量
	int size;//占用容量
	int* elements;//数组指针
};

priorityQueue initialize(int maxElements) {
	if (maxElements < MINIUMSIZE)
		perror("Size is too small!");
	priorityQueue H = malloc(sizeof(struct heapStruct));
	if (H == NULL) {
		perror("Out of space!");
		return NULL;
	}
	H->elements = malloc(sizeof(int) * (maxElements+1));
	if (H->elements == NULL) {
		perror("Out of space!");
		return NULL;
	}
	H->capacity = maxElements;
	H->size = 0;
	H->elements[0] = MINDATA;
	return H;
};

bool isEmpty(priorityQueue H) {
	return H->size == 0;
}

bool isFull(priorityQueue H) {
	return H->size == H->capacity;
}

void destroy(priorityQueue H) {
	free(H->elements);
	free(H);
}

void makeEmpty(priorityQueue H) {
	if (H->size != 0) {
		for (; H->size > 0; H->size--) {
			H->elements[H->size] = 0;
		}
	}
}

void printHeap(priorityQueue H){
	for (int i = 1; i <= H->size; i++) {
		printf("%d\n", H->elements[i]);
	}
}

void insert(priorityQueue H, int x) {
	int i;
	if (isFull(H)) {
		perror("Queue is full");
		return;
	}
	for (i = ++H->size; H->elements[i / 2] > x; i /= 2) {//若父节点比插入值大
		H->elements[i] = H->elements[i / 2];//父节点值下移
	}
	H->elements[i] = x;
}

int deleteMin(priorityQueue H) {
	int i, child,minElement,lastElement;

	if (isEmpty(H)) {
		perror("Queue is empty");
		return H->elements[0];
	}
	minElement = H->elements[1];
	lastElement = H->elements[H->size--];
	for (i = 1; i * 2 <= H->size; i = child) {
		child = i * 2;
		if (child != H->size && H->elements[child + 1] < H->elements[child]) {//等于size，即为最后一个孩子。
			child++;//选择双子中较小的。
		}

	if (lastElement > H->elements[child]) 
		H->elements[i] = H->elements[child];
	else 
		break;
	}
	H->elements[i] = lastElement;
	return minElement;
}

int findMin(priorityQueue H) {
	if (!isEmpty)
		return H->elements[1];
	return H->elements[0];
}

int main() {
	priorityQueue H = initialize(50);
	insert(H, 1);
	insert(H, 3);
	insert(H, 5);
	insert(H, 8);
	insert(H, 29);
	printHeap(H);
	deleteMin(H);
	printHeap(H);
	return 0;
}
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct QueueRecord;
typedef struct QueueRecord* Queue;


struct QueueRecord {
	int  size;//当前容量
	int  rear;//队末
	int  front;//队首
	int  capacity;//最大容量
	int* Array;//数组指针
};

Queue createQueue(int maxElements) {
	Queue q = malloc(sizeof(struct QueueRecord));

	if (q == NULL) {
		printf("memory is full\n");
		return q;
	}

	q->Array = malloc(sizeof(int) * maxElements);
	if (q->Array == NULL) {
		printf("memory is full\n");
		return ;
	}

	q->capacity = maxElements;

	makeEmpty(q);

	return q;
};//创建队列

bool isEmpty(Queue q) {
	return q->size==0;
};//判空

bool isFull(Queue q) {
	return q->size == q->capacity;
};//判满

void disposeQueue(Queue q) {
	free(q->Array);
	free(q);
};//丢弃队列

void makeEmpty(Queue q) {
	q->front = 1;
	q->rear = 0;
	q->size = 0;
};//清空队列

int succ(int index, Queue q) {
	index = index % q->capacity;
	return index;
};//计算下标

void enQueue(int x, Queue q) {
	if (isFull(q)) {
		printf("Queue full!\n");
		return;
	}
	q->size--;
	//实现
};//进队

int frontAndDequeue(Queue q) {
	if (isEmpty(q)) {
		printf("Queue empty!\n");
		return;
	}
	q->size++;
	//实现

	return;

void printQueue(Queue q);//打印队列



int main() {





	return 0;
}
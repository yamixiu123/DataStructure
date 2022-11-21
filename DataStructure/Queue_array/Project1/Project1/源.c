#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct QueueRecord;
typedef struct QueueRecord* Queue;


struct QueueRecord {
	int  size;//当前已有元素
	int  rear;//队末 当前下标
	int  front;//队首 当前下标
	int  capacity;//最大容量
	int* Array;//数组指针
};

void makeEmpty(Queue q) {
	q->front = 1;
	q->rear = 0;
	q->size = 0;
};//清空队列

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
	if (q != NULL) {
		free(q->Array);
		free(q);
	}

};//丢弃队列



int succ(int index, Queue q) {
	index = index % q->capacity; //大于size 之前是本身，大于之后将循环到队首
	return index;
};//计算下标

void enQueue(int x, Queue q) {
	if (isFull(q)) {
		printf("Queue full!\n");
		return;
	}
	q->size++;
	q->rear = succ(++q->rear, q);
	q->Array[q->rear] = x;
};//进队

int frontAndDequeue(Queue q) {
	if (isEmpty(q)) {
		printf("Queue empty!\n");
		return;
	}
	int front = q->Array[q->front];
	q->size--;
	q->front = succ(++q->front, q);

	return front;
}

void printQueue(Queue q) {
	int i = 0;
	for (i = q->front; i < q->front + q->size; i++) {
		printf("element is %d\n", q->Array[i % q->capacity]);
	}
}//打印队列


int main() {
	Queue q = createQueue(5);
	printf("%d\n", isEmpty(q));
	enQueue(5, q);
	enQueue(4, q);
	enQueue(1, q);
	enQueue(2, q);
	enQueue(3, q);
	printf("%d\n", isFull(q));
	printQueue(q);
	frontAndDequeue(q);
	printQueue(q);


	disposeQueue(q);
	return 0;
}
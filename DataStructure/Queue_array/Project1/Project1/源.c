#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct QueueRecord;
typedef struct QueueRecord* Queue;


struct QueueRecord {
	int  size;//��ǰ����
	int  rear;//��ĩ
	int  front;//����
	int  capacity;//�������
	int* Array;//����ָ��
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
};//��������

bool isEmpty(Queue q) {
	return q->size==0;
};//�п�

bool isFull(Queue q) {
	return q->size == q->capacity;
};//����

void disposeQueue(Queue q) {
	free(q->Array);
	free(q);
};//��������

void makeEmpty(Queue q) {
	q->front = 1;
	q->rear = 0;
	q->size = 0;
};//��ն���

int succ(int index, Queue q) {
	index = index % q->capacity;
	return index;
};//�����±�

void enQueue(int x, Queue q) {
	if (isFull(q)) {
		printf("Queue full!\n");
		return;
	}
	q->size--;
	//ʵ��
};//����

int frontAndDequeue(Queue q) {
	if (isEmpty(q)) {
		printf("Queue empty!\n");
		return;
	}
	q->size++;
	//ʵ��

	return;

void printQueue(Queue q);//��ӡ����



int main() {





	return 0;
}
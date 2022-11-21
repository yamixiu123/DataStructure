#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct QueueRecord;
typedef struct QueueRecord* Queue;


struct QueueRecord {
	int  size;//��ǰ����Ԫ��
	int  rear;//��ĩ ��ǰ�±�
	int  front;//���� ��ǰ�±�
	int  capacity;//�������
	int* Array;//����ָ��
};

void makeEmpty(Queue q) {
	q->front = 1;
	q->rear = 0;
	q->size = 0;
};//��ն���

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
	if (q != NULL) {
		free(q->Array);
		free(q);
	}

};//��������



int succ(int index, Queue q) {
	index = index % q->capacity; //����size ֮ǰ�Ǳ�������֮��ѭ��������
	return index;
};//�����±�

void enQueue(int x, Queue q) {
	if (isFull(q)) {
		printf("Queue full!\n");
		return;
	}
	q->size++;
	q->rear = succ(++q->rear, q);
	q->Array[q->rear] = x;
};//����

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
}//��ӡ����


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
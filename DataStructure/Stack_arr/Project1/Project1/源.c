#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define EMPTYTOS -1
#define MINSIZE 5

struct StackRecord;
typedef struct StackRecord* Stack;
bool isEmpty(Stack s);//�п�
bool isFull(Stack s);//����

Stack createStack(int maxElements);//�����ṹ��

void disposeStack(Stack s);//����ջ�ռ�
void makeEmpty(Stack s);//���ջ����
void push(Stack s,int x);//ѹջ
int top(Stack s);//չʾջ��Ԫ��
void pop(Stack s);//����ջ��Ԫ��
int topAndPop(Stack s);//����ջ����չʾ

struct StackRecord {

	int topOfStack;//��ǰջ���±�
	int capacity;//��ʾ��ջ������С
	int* array;//����������Ԫ�� ����������ʹ��

};

bool isEmpty(Stack s) {
	return s->topOfStack == EMPTYTOS;
};

bool isFull(Stack s) {
	return s->capacity == s->topOfStack+1;
};

Stack createStack(int stackSize) {
	if (stackSize < MINSIZE) {
		printf("EORROR:Size is too small!\n");
		return;
	}

	Stack s = malloc(sizeof(struct StackRecord));//���ṹ�����ռ�
	if (s == NULL) {
		printf("Out of space!\n");
		return;
	}

	s->array = malloc(sizeof(int) * stackSize);//���������ռ�
	if (s->array == NULL) {
		printf("Out of space!\n");
		return;
	}

	s->capacity = stackSize;//��Ա���� ������ֵ
	s->topOfStack = EMPTYTOS;//�±긳ֵΪ-1 ��ʾΪ��

	return s;
};

void disposeStack(Stack s) {
	if (s != NULL) {
		free(s->array);
		free(s);
	}
};

void makeEmpty(Stack s) {
	s->topOfStack = EMPTYTOS;
};

void push(Stack s, int x) {
	if (isFull(s)) {
		printf("EORROR:Stack over flow!\n");
	}
	s->array[++s->topOfStack]=x;//���鸳ֵ ++���ȼ����
};

int top(Stack s) {
	if (s->topOfStack!=EMPTYTOS) {
		printf("top element is %d\n", s->array[s->topOfStack]);
		return s->array[s->topOfStack];
	}
};

int topAndPop(Stack s) {
	if (!isEmpty(s)) {
		return s->array[s->topOfStack--];
	}
	printf("ERROR: Empty stack\n");
	return 0;
};//����ջ��


int main() {
	Stack s1 = createStack(1);
	Stack s2 = createStack(50);
	topAndPop(s2);
	push(s2, 5);
	push(s2, 6);
	top(s2);
	topAndPop(s2);
	top(s2);
	disposeStack(s2);

	return 0;
}
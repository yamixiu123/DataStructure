#include<stdio.h>
#include<stdlib.h>//malloc
#include<stdbool.h>//bool����

typedef struct Stack Stack;

Stack* createStack(void) ;//����ԭ�� ������һ�� �ṹ��stack��ָ��

bool isEmpty(Stack* s);//�п�

void disposeStack(Stack* s);//��ʾջԪ��
void makeEmpty(Stack* s);//�ÿ�

void push(int x, Stack* s);//ѹջ

int top(Stack* s);//�鿴ջ��Ԫ��

void pop(Stack* s); //ջ����ջ

typedef struct Stack {
	int element;
	Stack* next;
}Stack;

Stack* createStack(void) {
	Stack* s = malloc(sizeof(Stack));

	if (s == NULL) {
		printf("Out of space!\n");
		return NULL;
	}
	s->next = NULL;
	return s;
}

bool isEmpty(Stack* s) {
	return s->next == NULL;
}

void disposeStack(Stack* s) {
	if (s == NULL) {
		printf("must be createstack first.\n");
		return;
	}
	s = s->next;
	while (s!= NULL) {
		printf("%d\n", s->element);
		s = s->next;
	}
}

void makeEmpty(Stack* s) {
	if (s == NULL) {
		printf("must be createstack first.\n");
		return;
	}
	while (!isEmpty(s)) {
		pop(s);
	}

}

void push(int x, Stack* s) {
	Stack* tmp = malloc(sizeof(Stack));
	if (tmp == NULL) {
		printf("size is full\n");
		return;
	}
	tmp->element = x;
	tmp->next = s->next;
	s->next = tmp;
}

int top(Stack* s) {
	if (s == NULL) {
		printf("must be createstack first.\n");
		return;
	}
	int res = s->next->element;
	return res;
}

void pop(Stack* s) {
	if (s->next== NULL) {
		printf("stack is null");
		return;
	}
	Stack* tmp = s->next;
	s->next = tmp->next;

	free(tmp);
}

int main() {
	Stack* s = createStack();
	push(5, s);
	push(4, s);
	disposeStack(s);
	pop(s);
	disposeStack(s);
	int tp = top(s);
	printf("%d", tp);


}
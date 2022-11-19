#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define EMPTYTOS -1
#define MINSIZE 5

struct StackRecord;
typedef struct StackRecord* Stack;
bool isEmpty(Stack s);//判空
bool isFull(Stack s);//判满

Stack createStack(int maxElements);//创建结构体

void disposeStack(Stack s);//丢弃栈空间
void makeEmpty(Stack s);//清空栈数据
void push(Stack s,int x);//压栈
int top(Stack s);//展示栈顶元素
void pop(Stack s);//丢弃栈顶元素
int topAndPop(Stack s);//丢弃栈顶并展示

struct StackRecord {

	int topOfStack;//当前栈顶下标
	int capacity;//表示该栈容量大小
	int* array;//接收数组首元素 按照数组名使用

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

	Stack s = malloc(sizeof(struct StackRecord));//给结构体分配空间
	if (s == NULL) {
		printf("Out of space!\n");
		return;
	}

	s->array = malloc(sizeof(int) * stackSize);//给数组分配空间
	if (s->array == NULL) {
		printf("Out of space!\n");
		return;
	}

	s->capacity = stackSize;//成员变量 容量赋值
	s->topOfStack = EMPTYTOS;//下标赋值为-1 表示为空

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
	s->array[++s->topOfStack]=x;//数组赋值 ++优先级最低
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
};//丢弃栈顶


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
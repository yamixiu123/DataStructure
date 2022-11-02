#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>





//����ԭ������


struct Node* createHeaderNode(); //����һ���������͵�ָ��

void insertFirst(struct Node* header, int x);
void insertLirst(struct Node* header, int x);

struct Node* find(struct Node* header, int x);

struct Node* findKth(struct Node* header, int position);

void delete(struct Node* header, int x);

bool isEmpty(struct Node* header);

int size(struct Node* header);

void printList(struct Node* header);





typedef struct Node {
	int element;//�ڵ��ں�Ԫ��,����Ϊint
	struct Node*  next;//�洢��һ���ڵ��ָ��
	
}Node;

//������ͷ
Node* createHeaderNode() {
	Node* header = NULL; //��ʼ��ָ��

	header = malloc(sizeof(Node));//��̬����ͷָ��

	if (header == NULL) {

		printf("��ʼ��ʧ��");
		exit(1);
	}

	header->next = NULL;//��ʼ���νڵ��ַ

	return header;

};

//�жϱ��Ƿ�Ϊ��ʵ��

bool isEmpty(struct Node* header) {

	return header->next == NULL;
}


int main(void) {
	//����ͷ���
	Node* header = createHeaderNode();

	//�жϱ��Ƿ�Ϊ��
	if (isEmpty(header)) {
		printf("List is empty\n");
	}
	else {
		printf("List is not empty\n");
	}

	//�ӱ�ͷ����
	insertFirst(header, 1);
	insertFirst(header, 2);

	//��β������
	insertLast(header, 3);
	insertLast(header, 4);




	return 0;
}
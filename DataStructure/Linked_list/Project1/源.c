#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>





//����ԭ������


struct Node* createHeaderNode(); //����һ���������͵�ָ��

void insertFirst(struct Node* header, int x);
void insertLast(struct Node* header, int x);

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



//�ӱ�ͷ���� 

void insertFirst(struct Node* header, int x) {
	Node* tmp = NULL:
	tmp = (Node*)malloc(sizeof(Node));
	tmp->element = x;//����ֵ
	tmp->next = header->next;//���Žڵ��ָ��ָ�� ͷָ��Ĵνڵ�
	header->next = tmp;
}

void insertLast(struct Node* header, int x) {
	Node* tmp = NULL:
	tmp = (Node*)malloc(sizeof(Node));
	tmp->element = x;//����ֵ

	Node* p = header;
	while ((p->next)!=NULL) {
		p = p->next;
	}//���Ƶ����һ��Ԫ��

	p->next = tmp;//ָ��tmp

	free(p); // �ͷ���ʱָ�����
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

	//�ӱ�ͷ���룬���丳ֵΪ1 ,2 
	insertFirst(header, 1);
	insertFirst(header, 2);

	printList(header);
	printf("====================\n")


	//��β������,���丳ֵΪ3,4
	insertLast(header, 3);
	insertLast(header, 4);




	return 0;
}
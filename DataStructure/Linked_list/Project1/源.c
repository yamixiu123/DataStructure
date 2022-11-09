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

bool isEmpty(Node* header) {

	return header->next == NULL;
}




//�ӱ�ͷ���� 

void insertFirst(Node* header, int x) {
	Node* tmp = NULL;
	tmp = (Node*)malloc(sizeof(Node));
	tmp->element = x;//����ֵ
	tmp->next = header->next;//���Žڵ��ָ��ָ�� ͷָ��Ĵνڵ�
	header->next = tmp;
}

void insertLast(Node* header, int x) {
	Node* tmp = NULL;
	tmp = (Node*)malloc(sizeof(Node));
	tmp->element = x;//����ֵ
	tmp->next = NULL;

	Node* p = header;
	while ((p->next)!=NULL) {
		p = p->next;
	}//���Ƶ����һ��Ԫ��

	p->next = tmp;//ָ��tmp
}
void printList(Node* header) {
	Node* p = NULL;

	p = header->next;
	while ((p) != NULL) {
		printf("%d\n", p->element);
		p = p->next;

	}
}

void delete(struct Node* header, int x) {
	Node* p = header->next;
	Node* priviouse = header;
	if (p == NULL) {
		printf("this is a void list\n");
		return;
	}
	while (p != NULL) {
		if (p->element == x) {
			priviouse->next = p->next;
			free(p);
			printf("delete success\n");
			return;
		}
		else {
			priviouse = p;
			p = p->next;
		}
	}


	printf("Can not find the element\n");
}


//find ���� û�ҵ�����NULL
Node* find(struct Node* header, int x) {
	Node* p = header->next;

	while (p != NULL && p->element != x) {
		p = p->next;
	}
	return p;
}

struct Node* findKth(struct Node* header, int position) {
	int count = 1;
	Node* p = header->next;

	if (position <=0)
	{
		printf("position can not be minus number\n");
		return NULL;
	}

	while (p!=NULL)
	{
		if (count==position)
		{
			printf("have found the %d position node\n", position);
			return p;
		}
		p = p->next;
		count++;
	}
	printf("not find the position\n");
	return p;

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
	printf("====================\n");


	//��β������,���丳ֵΪ3,4
	insertLast(header, 3);
	insertLast(header, 4);

	printList(header);

	Node* node = find(header, 100);
	if (node == NULL) {

		printf("not find....\n");
	}
	else {
		printf("found the node element %d", node->element);
	}

	Node* node1 = findKth(header, 10);

	delete(header, 10);

	printList(header);
	

	return 0;
}
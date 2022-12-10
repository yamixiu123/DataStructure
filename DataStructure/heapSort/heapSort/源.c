#include<stdio.h>

#define leftChild(i)(2*(i)+1)//���������±�
#define SIZE 9 

void precDown(int arr[], int i, int arrSize) {
	int child;
	int tmp;

	for (tmp = arr[i]; leftChild(i) < arrSize; i = child) {//tmp��ʱΪ���ڵ�ֵ 
		child = leftChild(i);//�����±�
		if (child != arrSize - 1 && arr[child + 1] > arr[child])//ѡ�����Һ��������ĺ��ӵ��±�
			child++;
		if (tmp < arr[child])//�����ڵ�ֵС�ں��ӽڵ�
			arr[i] = arr[child];//���ڵ�ֵ����С���ӽڵ㽻��
		else
			break;
	}
	arr[i] = tmp;//��ʱΪi���ӽڵ��±� 
}

void heapSort(int arr[], int arrSize) {
	int i;

	for (i = arrSize / 2; i >= 0; i--)/*������*/
		precDown(arr, i, arrSize);
	for (i = arrSize - 1; i > 0; i--) {
		swap(&arr[0], &arr[i]);/*ɾ���*/
		precDown(arr, 0, i);
	}
}
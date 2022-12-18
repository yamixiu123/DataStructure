#include<stdio.h>
#include<stdlib.h>

#define SIZE 9

void merge(int arr[], int tmpArr[], int l_pos, int r_pos, int rightEnd) {//�±��Ϊ���ֵ��������ʼλ��
	int i, leftEnd, numElements, tmpPos;

	leftEnd = r_pos - 1;
	tmpPos = l_pos;
	numElements = rightEnd - l_pos + 1;//�±��ʵ�ʴ�СС1

	/*��ѭ��*/

	while (l_pos <= leftEnd && r_pos <= rightEnd)//���������ʱ�����±����Ԫ�� ���������鷶Χ�ڣ�
		if (arr[l_pos] <= arr[r_pos])//��Ԫ��С�ڵ�����Ԫ��
			tmpArr[tmpPos++] = arr[l_pos++];//���±�Ԫ�ظ��Ƹ���ʱ�����±��Ԫ�� �������±��+1
		else
			tmpArr[tmpPos++] = arr[r_pos++];

	while (l_pos <= leftEnd)
		tmpArr[tmpPos++] = arr[l_pos++];
	while (r_pos <= rightEnd)
		tmpArr[tmpPos++] = arr[r_pos++];

	for (i = 0; i < numElements; i++, rightEnd--)
		arr[rightEnd] = tmpArr[rightEnd];//���ź��������ŵ�Ԫ�����ڷ��أ�������һ������
};

void mSort(int arr[], int tmpArr[], int leftStart, int rightEnd) {
	int center;

	if (leftStart < rightEnd) {
		center = (leftStart + rightEnd) / 2;
		mSort(arr, tmpArr, leftStart, center);
		mSort(arr, tmpArr, center + 1, rightEnd);//�����黮�� Ϊ���ɸ�С���飬��󲢽����ֺ���±괫�� merge����
		merge(arr, tmpArr, leftStart, center + 1, rightEnd);//l_pos,r_pos
	}
};

void mergeSort(int arr[], int arrSize) {
	int* tmpArr;
	tmpArr = (int*)malloc(sizeof(int) * arrSize);
	if (tmpArr != NULL) {
		mSort(arr, tmpArr, 0, arrSize - 1);
	}
	else
	{
		printf("Out of space!!\n");
	}
};


void printArr(int arr[], int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		printf("%d\n", arr[i]);
	}
}

int main() {
	int arr[SIZE] = { 2,3,1,99,6,7,5,24,11 };
	mergeSort(arr, SIZE);
	printArr(arr, SIZE);
	return 0;
}
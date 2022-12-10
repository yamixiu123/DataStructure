#include<stdio.h>

#define leftChild(i)(2*(i)+1)//计算左孩子下标
#define SIZE 9 

void precDown(int arr[], int i, int arrSize) {
	int child;
	int tmp;

	for (tmp = arr[i]; leftChild(i) < arrSize; i = child) {//tmp此时为父节点值 
		child = leftChild(i);//左孩子下标
		if (child != arrSize - 1 && arr[child + 1] > arr[child])//选择左右孩子中最大的孩子的下标
			child++;
		if (tmp < arr[child])//若父节点值小于孩子节点
			arr[i] = arr[child];//父节点值与最小孩子节点交换
		else
			break;
	}
	arr[i] = tmp;//此时为i孩子节点下标 
}

void heapSort(int arr[], int arrSize) {
	int i;

	for (i = arrSize / 2; i >= 0; i--)/*创建堆*/
		precDown(arr, i, arrSize);
	for (i = arrSize - 1; i > 0; i--) {
		swap(&arr[0], &arr[i]);/*删最大*/
		precDown(arr, 0, i);
	}
}
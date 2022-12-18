#include<stdio.h>
#include<stdlib.h>

#define SIZE 9

void merge(int arr[], int tmpArr[], int l_pos, int r_pos, int rightEnd) {//下标均为划分的数组的起始位置
	int i, leftEnd, numElements, tmpPos;

	leftEnd = r_pos - 1;
	tmpPos = l_pos;
	numElements = rightEnd - l_pos + 1;//下标比实际大小小1

	/*主循环*/

	while (l_pos <= leftEnd && r_pos <= rightEnd)//如果两个临时数组下标均有元素 （还在数组范围内）
		if (arr[l_pos] <= arr[r_pos])//左元素小于等于右元素
			tmpArr[tmpPos++] = arr[l_pos++];//左下标元素复制给临时数组下标的元素 ，两者下标均+1
		else
			tmpArr[tmpPos++] = arr[r_pos++];

	while (l_pos <= leftEnd)
		tmpArr[tmpPos++] = arr[l_pos++];
	while (r_pos <= rightEnd)
		tmpArr[tmpPos++] = arr[r_pos++];

	for (i = 0; i < numElements; i++, rightEnd--)
		arr[rightEnd] = tmpArr[rightEnd];//将排好序的数组放到元数组内返回，进行下一轮排序
};

void mSort(int arr[], int tmpArr[], int leftStart, int rightEnd) {
	int center;

	if (leftStart < rightEnd) {
		center = (leftStart + rightEnd) / 2;
		mSort(arr, tmpArr, leftStart, center);
		mSort(arr, tmpArr, center + 1, rightEnd);//将数组划分 为若干个小数组，最后并将划分后的下标传入 merge函数
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
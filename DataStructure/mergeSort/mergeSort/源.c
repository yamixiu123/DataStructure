#include<stdio.h>
#include<stdlib.h>

#define SIZE 9


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
void mSort(int arr[], int tmpArr[], int leftStar, int rightEnd) {
	int center;

	if (leftStar < rightEnd) {
		center = (leftStar + rightEnd) / 2;
		mSort(arr, tmpArr, leftStar, center);
		mSort(arr, tmpArr, center + 1, rightEnd);
		merge(arr, tmpArr, leftStar, center + 1, rightEnd);//l_pos,r_pos
	}
};
void merge(int arr[], int tmpArr[], int l_pos, int r_pos, int rightEnd) {//下标均为划分的数组的起始位置
	int i, leftEnd, numElements, tmpPos;

	leftEnd = r_pos - 1;
	tmpPos = l_pos;
	numElements = rightEnd - l_pos+1;//下标比实际大小小1

};
void printArr(int arr[], int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		printf("%d\n", arr[i]);
	}
}
int main() {
	int arr[SIZE] = { 2,3,1,5,6,3,5,24,11 };
	mergeSort(arr, SIZE);
	printArr(arr, SIZE);
	return 0;
}
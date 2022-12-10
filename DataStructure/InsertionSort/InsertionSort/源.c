#include<stdio.h>

#define SIZE 9

void insertionSort(int arr[],int arrSize){
	int tmp, i , j;
	for (i = 1; i < arrSize; i++) {
		tmp = arr[i];
		for (j = i ; tmp < arr[j-1]&&j>0; j--) {
			arr[j] = arr[j-1];
		}
		arr[j] = tmp;
	}
}
void printArr(int arr[],int arrSize){
	for (int i = 0; i < arrSize; i++) {
		printf("%d\n", arr[i]);
	}
}
int main(void) {
	int arr[SIZE] = { 5,3,6,1,7,7,3,23,2 };
	insertionSort(arr, SIZE);
	printArr(arr, SIZE);
	return 0;
}
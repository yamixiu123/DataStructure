#include<stdio.h>
#define SIZE 9

int partition(int arr[], int i, int j) {
	int pivot = arr[i];
	while (i < j) {
		while (i < j && arr[j] >= pivot)
			j--;
		arr[i] = arr[j];
		while (i < j && arr[i] <= pivot)
			i++;
		arr[j] = arr[i];
	}
	arr[i] = pivot;
	return i;
}


void quickSort(int arr[], int i, int j) {
	if (i < j) {
		int pivot = partition(arr, i, j);
		quickSort(arr, i, pivot - 1);
		quickSort(arr, i, pivot + 1);
	}

}


void printArray(int arr[], int length) {
	for (int i = 0; i < length; i++)
		printf("%d\n", arr[i]);
}
int main(void) {
	int arr[SIZE] = { 21,22,4,5,6,2,3,11,8 };
	quickSort(arr, 0, SIZE - 1);
	printArray(arr, SIZE);
}



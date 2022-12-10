#include<stdio.h>
#define SIZE 9

void shellSort(int arr[],int arrSize){
	int i, j, tmp,increment;
	for (increment = arrSize/2; increment > 0; increment /= 2) {
		for (i = increment; i < SIZE; i++) {
			tmp = arr[i];
			for (j = i; j>=increment&&tmp < arr[j-increment]; j-=increment) {
				arr[j] = arr[j-increment];
			}
			arr[j] = tmp;
		}
	}

}
void printArr(int arr[], int arrSize){
	for (int i = 0; i < arrSize; i++) {
		printf("%d\n", arr[i]);
	}
}


int main() {
	int arr[SIZE] = { 2,4,6,1,3,5,75,22,11 };
	shellSort(arr,SIZE);
	printArr(arr, SIZE);
	return 0;
}
#include <cstdio>
#include <bits/stdc++.h>

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], const int left, const int mid,
           const int right)
{
    const int subArrayOne = mid - left + 1;
    const int subArrayTwo = right - mid;
 
    // Create temp arrays
    int *leftArray = new int[subArrayOne],
        *rightArray = new int[subArrayTwo];
 
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
 
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
 
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
 
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
 
void mergeSort(int* arr, const int begin, const int end){ //Ascend
	if(begin >= end) return;

	int mid = begin + (end-begin)/2;
	mergeSort(arr, begin, mid);
	mergeSort(arr, mid+1, end);
	merge(arr, begin, mid, end);
};

int main(void){
	std::ios::sync_with_stdio(0); //Unsync
	int N;
	scanf("%d", &N);

	int* arr = new int[N];
	for(int i=0; i<N; i++){
		scanf("%d", arr+i);
	}

	mergeSort(arr, 0, N-1);	//Ascend
	
	for(int i=0; i<N; i++){
		printf("%d\n", arr[i]);
	}

	return 0;	
}
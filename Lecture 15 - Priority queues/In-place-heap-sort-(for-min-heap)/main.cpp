#include <iostream>
using namespace std;

void heapSort(int arr[], int n) {
	//Build the heap.
    int heapIndex = -1;
	
	while (heapIndex < n - 1) {
		heapIndex++;  //insertion of a new element
		int elementIndex = heapIndex;
		int parentIndex = (elementIndex - 1) / 2;
		
		if (elementIndex == 0) continue; // indictaing that element is the root, hence no need to do anything.
		
		//up-heapify
		while (arr[parentIndex] > arr[elementIndex]) {
			swap(arr[parentIndex], arr[elementIndex]);
			elementIndex = parentIndex;
			parentIndex = (elementIndex - 1) / 2;
			if (elementIndex == 0) break;
		}
	}
	
	//Sort the heap, using removeMin
	while (heapIndex > -1) {
		swap(arr[0], arr[heapIndex]); //before doing remove min we swap as done in removeMin in priority queue implemnentation.
		heapIndex--; //removeMin
		n--; //Decrease the array size as last index gets deleted after removeMin
		
		if (n == 0 || n == 1) return; //indicating that array is empty or if array has only element then it is sorted.

		int elementIndex = 0;
		int leftChildIndex = 2 * elementIndex + 1;
		int rightChildIndex = 2 * elementIndex + 2;
		
		//down-heapify
		while (leftChildIndex <= n - 1) {
			int smallerChildIndex = -1;
			int smallerChild = INT_MIN;
			
			if (rightChildIndex > n - 1) {
				smallerChild = arr[leftChildIndex];
				smallerChildIndex = leftChildIndex;
			} else {
				smallerChild = min(arr[leftChildIndex], arr[rightChildIndex]);
				if (arr[leftChildIndex] == smallerChild) smallerChildIndex = leftChildIndex;
				else if (arr[rightChildIndex] == smallerChild) smallerChildIndex = rightChildIndex;
			}
 
			if (arr[elementIndex] > arr[smallerChildIndex]) {
				swap(arr[elementIndex], arr[smallerChildIndex]);
				elementIndex = smallerChildIndex;
			} else {
				break;
			}
			leftChildIndex = 2 * elementIndex + 1;
			rightChildIndex = 2 * elementIndex + 2;
		}
	}
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}
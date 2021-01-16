#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//Priority queues Lecture 15 assignments.


//Check Max-Heap
bool isMaxHeap(int arr[], int n) {
	bool ans = false;
    for (int i = 0; i < n; i++) {
		int parentIndex = i;
		int leftChildIndex = 2 * i + 1;
		int rightChildIndex = leftChildIndex + 1;
		
		if (leftChildIndex <= n - 1) {
			if (arr[parentIndex] > arr[leftChildIndex]) {
				ans = true;
			} else ans = false;
		}
		
		if (ans == false) return ans;
		
		if (rightChildIndex <= n - 1) {
			if (arr[parentIndex] > arr[rightChildIndex]) {
				ans = true;
			} else ans = false;
		}
	}
	return ans;
}


//Find the kth largest elements.
int kthLargest(int* arr, int n, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < k; i++) {
		pq.push(arr[i]);
	}
	
	for (int i = k; i < n; i++) {
		if (arr[i] > pq.top()) {
			pq.pop();
			pq.push(arr[i]);
		}
	}
	
	return pq.top();
}

//Merge K sorted arrays //7462020331

class Triplet {
public:
	int element, elementIndex, vectorIndex;
	
    Triplet (int element, int elementIndex, int vectorIndex) {
		this->element = element;
		this->elementIndex = elementIndex;
		this->vectorIndex = vectorIndex;
	}
};

bool operator < (const Triplet &parent, const Triplet &child) {
        return child.element < parent.element;
} 

vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    //priority_queue<Triplet, vector<Triplet>, Comparator> pq;
	priority_queue<Triplet> pq;
	vector<int> output;
	
	//Inital insertion of all the first elements of the vector in the min pq.
	for (int i = 0; i < input.size(); i++) {
		Triplet firstElementOfTheArray(input[i]->at(0), 0, i);
		pq.push(firstElementOfTheArray);
	}
	
	//We can keep pushing and popping until the pq is not empty.
	while (!pq.empty()) { 
		Triplet elementToBePopped = pq.top();
		output.push_back(pq.top().element);
		pq.pop();
		
		//Before pushing next element, check if the next index for that vector is not going out of bounds.
		if (elementToBePopped.elementIndex <= input[elementToBePopped.vectorIndex]->size() - 2) { 
			Triplet elementToBePushed(input[elementToBePopped.vectorIndex]->at(elementToBePopped.elementIndex + 1), elementToBePopped.elementIndex + 1, elementToBePopped.vectorIndex);
			pq.push(elementToBePushed);
		}
	}
	return output;
}


//Running median
void printRunningMedian(int *arr, int n) {
    priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	
	for (int i = 0; i < n; i++) {
		
		//Put the element in the correct heap.
		if (i == 0) {
			maxHeap.push(arr[0]);
		} else {
			if (arr[i] < maxHeap.top()) {
				maxHeap.push(arr[i]);
			}
			else if (arr[i] >= maxHeap.top()) {
				minHeap.push(arr[i]);
			}
		}
		
		//Equally balance both the heaps.
		if (maxHeap.size() > minHeap.size() + 1) {
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		} else if (minHeap.size() > maxHeap.size() + 1) {
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
		
		//Print the median.
		
		//When size differs by 1 print the top of the bigger heap.
		if (maxHeap.size() + 1 == minHeap.size()) {
			cout << minHeap.top() << " ";
		} else if (minHeap.size() + 1 == maxHeap.size()) {
			cout << maxHeap.top() << " ";
		}
		
		//When size of both heaps are equal.
		if (maxHeap.size() == minHeap.size()) {
			cout << (int) ((maxHeap.top() + minHeap.top()) / 2) << " ";
		}
	}
}


//Buy the ticket.
int buyTicket(int *arr, int n, int k) {
    queue<int> q;
	priority_queue<int> pq;
	
	for (int i = 0; i < n; i++) {
		q.push(i);
		pq.push(arr[i]);
	}
	
	int ans = 0;
	while (!q.empty()) {
		if (arr[q.front()] == pq.top()) {
			ans += 1;
			if (q.front() == k) return ans;
			q.pop();
			pq.pop();
		}
		else if (arr[q.front() < pq.top()]) {
			int temp = q.front();
			q.pop();
			q.push(temp);
		}
	}
}


int main() {
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << buyTicket(arr, n, k);

    delete[] arr;
}








#include <iostream>
#include <vector>
using namespace std;

//Priority queue implementation for a min heap.
class priotityQueue {
	vector<int> pq;
	
public:
	bool isEmpty () {
		return pq.size() == 0;
	}
	
	int getSize () {
		return pq.size();
	}
	
	int getMin () {
		if (pq.size() == 0) return -1;
		return pq[0];
	}
	
	void insert (int element) {
		pq.push_back(element);
		if (pq.size() == 1) return;
		
		int elementIndex = pq.size() - 1;
		int parentIndex = (elementIndex - 1) / 2;
		
		while (pq[parentIndex] > pq[elementIndex]) {
			swap(pq[parentIndex], pq[elementIndex]);
			elementIndex = parentIndex;
			parentIndex = (elementIndex - 1) / 2;
			if (elementIndex == 0) return;
		}
	}
	
	int removeMin() {
		if (pq.size() == 0) return -1;
		if(pq.size() == 1) {
			int element = pq[0];
			pq.pop_back();
			return element;
		}
		
		int ans = pq[0];
		pq[0] = pq[pq.size() - 1];
		pq.pop_back();
		int elementIndex = 0;
		int leftChildIndex = 2 * elementIndex + 1;
		int rightChildIndex = 2 * elementIndex + 2;
		
		while (leftChildIndex <= pq.size() - 1 || rightChildIndex <= pq.size() - 1) {
			int smallerChildIndex = -1;
			int smallerChild = INT_MIN;
			
			if (rightChildIndex > pq.size() - 1) {
				smallerChild = pq[leftChildIndex];
				smallerChildIndex = leftChildIndex;
			} else {
				smallerChild = min(pq[leftChildIndex], pq[rightChildIndex]);
				if (pq[leftChildIndex] == smallerChild) smallerChildIndex = leftChildIndex;
				else if (pq[rightChildIndex] == smallerChild) smallerChildIndex = rightChildIndex;
			}
 
			if (pq[elementIndex] > pq[smallerChildIndex]) {
				swap(pq[elementIndex], pq[smallerChildIndex]);
				elementIndex = smallerChildIndex;
			} else {
				break;
			}
			leftChildIndex = 2 * elementIndex + 1;
			rightChildIndex = 2 * elementIndex + 2;
		}
		return ans;
    }
	
	void printHeap () {
		for (int i = 0; i < pq.size(); i++) {
			cout << pq[i] << " ";
		}
		cout << endl;
	}
};

int main() {

	priotityQueue pq;

    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMin
                cout << pq.getMin() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMin() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
				break;
			case 6:
				while (!pq.isEmpty()) {
					cout << pq.removeMin() << " ";
				} cout << endl;
            default:
                return 0;
        }
        
        cin >> choice;
    }
	
	return 0;
}
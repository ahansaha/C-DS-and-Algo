// C++ implementation of De-queue using circular
// array
#include <iostream>
using namespace std;

class Deque {
    // Complete this class
    int * data;
    int capacity;
    int nextIndex;
    int front;
    int rear;
    int size;
    
public:
    
    Deque(int size) {
        data = new int[size]();
        capacity = size;
        nextIndex = 0;
        front = -1;
        rear = -1;
        this -> size = 0;
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    void insertFront(int input) {
        size++;
    }
    
    void insertRear(int input) {
        size++;
    }
    
    void deleteFront() {
        if (isEmpty()) {
            cout << -1;
            return;
        }
    }
    
    void deleteRear() {
        if (isEmpty()) {
            cout << -1;
            return;
        }
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return data[front];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return data[rear];
    }
};

// Driver program to test above function
int main()
{
    Deque dq(10);
    int choice,input;
    while(true) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                dq.insertFront(input);
                break;
            case 2:
                cin >> input;
                dq.insertRear(input);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                cout << dq.getFront() << "\n";
                break;
            case 6:
                cout << dq.getRear() << "\n";
                break;
            default:
                return 0;
        }
    }
    
    return 0;
}


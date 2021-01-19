#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

template <typename T>
class Queue {
    
    T * data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;
    
public:
    
    Queue(int s) {
        data = new T[s];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = s;
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    void enqueue(T element) {
        if (size == capacity) {
            cout << "Queue is full" << endl;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % 5;
        if (firstIndex == -1) {
            firstIndex = 0;
        }
        size++;
    }
    
    T front() {
        if (firstIndex == -1) {
            cout << "Queue is empty" << endl;
            return 0;
        }
        return data[firstIndex];
    }
    
    T dequeue() {
        if (firstIndex == -1) {
            cout << "Queue is empty" << endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        if (size == 0) {
            nextIndex = 0;
            firstIndex = -1;
             
        }
        return ans;
    }
};


int main() {
    
    return 0;
}


//
//  main.cpp
//  stackUsingArray
//
//  Created by Souvik Saha on 17/08/20.
//  Copyright © 2020 Souvik Saha. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;



class StackUsingArray {
    
    int * data;
    int nextIndex;
    int capacity;
    
public:
    
    StackUsingArray() {
        data = new int[5]();
        nextIndex = 0;
        capacity = 5;
    }
    
    int size() {
        return nextIndex;
    }
    
    bool isEmpty() {
        return nextIndex == 0;
    }
    
    int top() {
        if (isEmpty()) {
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
    
private:
    
    void doubleArraySize() {
        int * new_data = new int[2 * capacity]();
        for (int i = 0; i < capacity; i++) {
            new_data[i] = data[i];
        }
        int * array_to_be_deleted = data;
        data = new_data;
        delete [] array_to_be_deleted;
        capacity *= 2;
    }
    
public:
    
    void push(int element) {
        if (size() == capacity) {
            doubleArraySize();
            push(element);
        }
        data[nextIndex++] = element;
    }
    
    void pop() {
        if (!isEmpty()) {
            cout << top() << endl;
            nextIndex--;
            return;
        }
        cout << "Stack is empty" << endl;
    }
};

int main() {
        
    StackUsingArray s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout << s.top() << endl;
    
    s.push(60);
    cout << s.top() << endl;
    return 0;
}

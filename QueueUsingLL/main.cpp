//
//  main.cpp
//  QueueUsingLL
//
//  Created by Souvik Saha on 18/08/20.
//  Copyright © 2020 Souvik Saha. All rights reserved.
//

#include <iostream>
using namespace std;

template <typename T>
class Node {
    
public:
    T data;
    Node<T> * next;
    
    Node(T data) {
        this -> data = data;
        next = NULL;
    }
};

template <typename T>
class Queue {
    Node<T> * head;
    Node<T> * tail;
    int size;
    
public:
    
    Queue() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    void enqueue(T data) {
        size++;
        Node<T> * new_node = new Node<T>(data);
        
        if (head == NULL && tail == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail -> next = new_node;
            tail = tail -> next;
        }
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    T dequeue() {
        // Return 0 if queue is empty
        if (isEmpty()) {
            return 0;
        }
                
        size--;
        Node<T> * node_to_be_deleted = head;
        T ans = head -> data;
        
        if (head == tail) {
            head = NULL;
            tail = NULL;
        } else {
            head = head -> next;
        }
        
        delete node_to_be_deleted;
        return ans;
    }
    
    T front() {
        // Return 0 if queue is empty
        if (isEmpty()) {
            return 0;
        }
        
        return head -> data;
    }
};

int main () {
    Queue<int> q;
    
    int choice;
    cin >> choice;
    int input;
    
    while (choice !=-1) {
        if(choice == 1) {
            cin >> input;
            q.enqueue(input);
        }
        else if(choice == 2) {
            int ans = q.dequeue();
            if(ans != 0) {
                cout << ans << endl;
            }
            else {
                cout << "-1" << endl;
            }
        }
        else if(choice == 3) {
            int ans = q.front();
            if(ans != 0) {
                cout << ans << endl;
            }
            else {
                cout << "-1" << endl;
            }
        }
        else if(choice == 4) {
            cout << q.getSize() << endl;
        }
        else if(choice == 5) {
            if(q.isEmpty()) {
                cout << "true" << endl;
            }
            else {
                cout << "false" << endl;
            }
        }
        cin >> choice;
    }
}

//
//  main.cpp
//  StackUsingLinkedList
//
//  Created by Souvik Saha on 18/08/20.
//  Copyright © 2020 Souvik Saha. All rights reserved.
//

#include<iostream>
using namespace std;


template <typename T>
class Node {
    public :
    T data;
    Node *next;
    
    Node(T data) {
        this -> data = data;
        next = NULL;
    }
};

template <typename T>
class Stack {
    Node<T> *head;
    int size;        // number of elements prsent in stack
    
public :
    
    Stack() {
        //Initially head should point towards NULL,indicating no element is present in the stack.
        head = NULL;
        size = 0;
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        return head == NULL;
    }
    
    void push(T element) {
        Node<T> * new_head = new Node<T>(element);
        size++;
        
        if (head == NULL) {
            head = new_head;
            return;
        }
        
        new_head -> next = head;
        head = new_head;
    }
    
    T pop() {
        // Return 0 if stack is empty. Don't display any other message
        if (isEmpty()) {
            return 0;
        }
        
        size--;
        Node<T> * new_head = head -> next;
        T element = head -> data;
        delete head;
        head = new_head;
        return element;
    }
    
    T top() {
        // Return 0 if stack is empty. Don't display any other message
        if (isEmpty()) {
            return 0;
        }
        
        return head -> data;
    }
};




int main() {
    
    Stack<int> st;
    
    int choice;
    cin >> choice;
    int input;
    
    while (choice !=-1) {
        if(choice == 1) {
            cin >> input;
            st.push(input);
        }
        else if(choice == 2) {
            int ans = st.pop();
            if(ans != 0) {
                cout << ans << endl;
            }
            else {
                cout << "-1" << endl;
            }
        }
        else if(choice == 3) {
            int ans = st.top();
            if(ans != 0) {
                cout << ans << endl;
            }
            else {
                cout << "-1" << endl;
            }
        }
        else if(choice == 4) {
            cout << st.getSize() << endl;
        }
        else if(choice == 5) {
    if(st.isEmpty()){
                cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
        }
        cin >> choice;
    }

}

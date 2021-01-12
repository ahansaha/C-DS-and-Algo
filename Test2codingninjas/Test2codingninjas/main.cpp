#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

Node* NextLargeNumber(Node *head) {
    Node * temp = head;
    Node * change = head;
    
    while (temp -> next != NULL) {
        
        if (temp -> data != 9 && temp -> next -> data == 9) {
            change = temp;
        }
        temp = temp -> next;
    }
    
    if (temp -> data == 9) {
        
        if (change != head) {
            change -> data += 1;
            change = change -> next;
        }
        else if (change == head) {
            Node * new_head = new Node(1);
            new_head -> next = head;
            head = new_head;
        }
        
        while (change != NULL) {
            change -> data = 0;
            change = change -> next;
        }
        return head;
    }
    
    temp -> data += 1;
    return head;
}

int main() {
    Node *head = takeinput();
    
    head = NextLargeNumber(head);
    print(head);
    return 0;
}





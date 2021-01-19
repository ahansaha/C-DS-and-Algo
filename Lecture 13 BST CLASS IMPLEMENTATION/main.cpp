//
//  main.cpp
//  Lecture 13 BST CLASS IMPLEMENTATION
//
//  Created by Souvik Saha on 01/09/20.
//  Copyright © 2020 Souvik Saha. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    
    BinaryTreeNode(T data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {
    BinaryTreeNode<int> * root;

    
//SEARCHING IN A BST.
private:
    bool hasData(BinaryTreeNode<int> * node, int data) {
        if (node == NULL) {
            return false;
        }
        if (data == node->data) {
            return true;
        }
        else if (data < node->data) {
            return hasData(node->left, data);
        }
        else if (data > node->data) {
            return hasData(node->right, data);
        }
        else {
            return false;
        }
    }
public:
    bool hasData(int data) {
        return hasData(this->root, data);
    }
    
//INSERTING IN A BST.
private:
    BinaryTreeNode<int> * insert(BinaryTreeNode<int> * node, int data) {
        if (node == NULL) {
            BinaryTreeNode<int> * n = new BinaryTreeNode<int>(data);
            node = n;
            return node;
        }
        else if (data < node->data) {
            BinaryTreeNode<int> * left_node = insert(node->left, data);
            node->left = left_node;
            return node;
        }
        else {
            BinaryTreeNode<int> * right_node = insert(node->right, data);
            node->right = right_node;
            return node;
        }
    }
    
public:
    void insert(int data) {
        this->root = insert(this->root, data);
    }
    
//DELETING IN A BST.
private:
    BinaryTreeNode<int> * deleteData(BinaryTreeNode<int> * node, int data) {
        if (node == NULL) {
            return NULL;
        }
        //If the node itself has to be deleted.
        if (node->data == data) {
            
            //If  the nodes left and right don't exist.
            if (node->left == NULL && node->right == NULL) {
                delete node;
                return NULL;
            }
            
            //If the nodes left exists but right doesn't exist.
            else if (node->left != NULL && node->right == NULL) {
                BinaryTreeNode<int> * node_left = node->left;
                delete node;
                return node_left;
            }
            
            //If the nodes right exists but left doesn't exist.
            else if (node->left == NULL && node->right != NULL) {
                BinaryTreeNode<int> * node_right = node->right;
                delete node;
                return node_right;
            }
            
            //If the nodes left and right exist.
            else {
                //Find the replacement from the right side by finding the minimum of the right subtree.(can also find from the left side).
                BinaryTreeNode<int> * min_right = node->right;
                while (min_right->left != NULL) {
                    min_right = min_right->left;
                }
                
                //Replace the root node's data with the found minimum data.
                node->data = min_right->data;
                
                //And delete the found minimum from the right subtree.
                node->right = deleteData(node->right, min_right->data);
                return node;
            }
        }
        
        //If the node to be deleted resides on the left.
        else if (data < node->data) {
            BinaryTreeNode<int> * left_ans = deleteData(node->left, data);
            node->left = left_ans;
            return node;
        }
        //If the node tobe deleted resides on the right.
        else {
            BinaryTreeNode<int> * right_ans = deleteData(node->right, data);
            node->right = right_ans;
            return node;
        }
    }
    
public:
    void deleteData(int data) {
        this->root = deleteData(this->root, data);
    }
    
//PRINT THE BST RECURSIVELY.
private:
    void printTree(BinaryTreeNode<int> * node) {
        if (node == NULL) {
            return;
        }
        cout << node->data << ":";
        if (node->left != NULL) {
            cout << "L:" << node->left->data << ",";
        }
        if (node->right != NULL) {
            cout << "R:" << node->right->data;
        }
        cout << endl;
        printTree(node->left);
        printTree(node->right);
    }
    
public:
    void printTree() {
        printTree(this->root);
    }
    
};

int main(){
    BST *tree = new BST();
    int choice, input;
    while(true){
        cin>>choice;
        switch(choice){
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->deleteData(input);
                break;
            case 3:
                cin >> input;
                if(tree->hasData(input)) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
                break;
            default:
                tree->printTree();
                return 0;
                break;
        }
    }
}


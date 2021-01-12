//
//  main.cpp
//  BST assignments lecture 13
//
//  Created by Souvik Saha on 02/09/20.
//  Copyright © 2020 Souvik Saha. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <cmath>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
    q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if(first == NULL) {
            if(q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first -> data << " ";
        if(first -> left != NULL) {
            q.push(first -> left);
        }
        if(first -> right != NULL) {
            q.push(first -> right);
        }
    }
}

//CREATE AND INSERT DUPLICATE NODE.
//Given a Binary Tree with N number of nodes,
//for each node create a new duplicate node,
//and insert that duplicate as left child of the original node.
void insertDuplicateNode(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return;
    }
    
    BinaryTreeNode<int> * left_sub_tree = root->left;
    BinaryTreeNode<int> * duplicate_node = new BinaryTreeNode<int>(root->data);
    root->left = duplicate_node;
    duplicate_node->left = left_sub_tree;
    
    insertDuplicateNode(left_sub_tree);
    insertDuplicateNode(root->right);
}

//PAIR SUM IN A BINARY TREE.
//Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
void pairSum(int input[], int size, int x) {
    //Step - 1 :- Sort the array
    sort(input, input + size);
    
    //Initialize the 2 iterators at the arrays extreme ends si, ei.
    int si = 0;
    int ei = size - 1;
    
    while (si < ei) {
        
        //Step - 2 :- If sum of si's and ei's elements  are not equal to x.
        if (input[si] + input[ei] != x) {
            //If the sum is greater than x.
            if (input[si] + input[ei] > x) {
                ei--;
            }
            //else if the sum is less than x.
            else {
                si++;
            }
        }
        
        //Step - 3 :- If the sum is equal to x.
        else {
            //If the elements at si and ei are not the same,
            if (input[si] != input[ei]) {
                //then do this :-
                //Count the no. of si elements which have the same value.
                int si_count = 0;
                int si_number_whose_count_has_to_be_kept = input[si];
                while (input[si] == si_number_whose_count_has_to_be_kept) {
                    si_count++;
                    si++;
                }
                
                //Count the no. of ei elements which have the same value.
                int ei_count = 0;
                int ei_number_whose_count_has_to_be_kept = input[ei];
                while (input[ei] == ei_number_whose_count_has_to_be_kept) {
                    ei_count++;
                    ei--;
                }
                
                //Print the si and the ei elements (si_count x ei_count) times.
                for (int i = 0; i < (si_count * ei_count); i++) {
                    cout << si_number_whose_count_has_to_be_kept << " " << ei_number_whose_count_has_to_be_kept << endl;
                }
            }
            
            //Else if the elements at si and ei are the same,
            else {
                //Find the size of the sub-array which has all elements identical.
                int sub_size = ei - si + 1;
                
                //Find the natural sum of the fist sub_size elements.
                int natural_sub_size = ((sub_size) * (sub_size - 1)) / 2;
                
                //Print till the natural sub size.
                for (int i = 0; i < natural_sub_size; i++) {
                    cout << input[si] << " " << input[si] << endl;
                }
                
                //After this no more elements in the whole array need to be checked.
                //Because this condition is only reached at the end.
                break;
            }
        }
    }
}

void tree_to_array(BinaryTreeNode<int> * root, vector<int> * input) {
    if (root == NULL) {
        return;
    }
    input->push_back(root->data);
    tree_to_array(root->left, input);
    tree_to_array(root->right, input);
}

void nodesSumToS(BinaryTreeNode<int> *root, int sum) {
    //Put the tree into a vector.
    vector<int> * v = new vector<int>();
    tree_to_array(root, v);
    
    //Put the tree into an array.
    int * arr = new int[v->size()]();
    for (int i = 0; i < v->size(); i++) {
        arr[i] = v->at(i);
    }
    
    //Call the pair sum function.
    pairSum(arr, v->size(), sum);
    
    //Delete the dynamically created vector.
    delete [] arr;
}

//LCA of a binary tree.
int lcaBinaryTree(BinaryTreeNode <int>* root , int val1, int val2) {
    if (root == NULL) {
        return INT_MIN;
    }
    if (root->data == val1 || root->data == val2) {
        return root->data;
    }
    int left_ans = lcaBinaryTree(root->left, val1, val2);
    int right_ans = lcaBinaryTree(root->right, val1, val2);
    
    if (left_ans == INT_MIN && right_ans == INT_MIN) return INT_MIN;
    else if (left_ans != INT_MIN && right_ans == INT_MIN) return left_ans;
    else if (left_ans == INT_MIN && right_ans != INT_MIN) return right_ans;
    else return root->data;
}

//LCA of a binary search tree.
int lcaInBST(BinaryTreeNode<int>* root , int val1 , int val2){
    //Base Case.
    if (root == NULL) {
        return INT_MIN;
    }
    
    //You work only on the root.
    if (root->data == val1 || root->data == val2) {
        return root->data;
    }
    
    //if the roots data is greater than both val1 ans val2, LCA will be there on the right side if it exists.
    if (root->data > val1 && root->data > val2) {
        return lcaInBST(root->left, val1, val2);
    }
    
    //if the roots data is less than both val1 ans val2, LCA will be there on the left side if it exists.
    else if (root->data < val1 && root->data < val2) {
        return lcaInBST(root->right, val1, val2);
    }
    
    //Else if the root's data lies in between val1 and val2.
    int left_ans = lcaInBST(root->left, val1, val2);
    int right_ans = lcaInBST(root->right, val1, val2);
    if (left_ans == INT_MIN && right_ans == INT_MIN) return INT_MIN;
    else if (left_ans != INT_MIN && right_ans == INT_MIN) return left_ans;
    else if (left_ans == INT_MIN && right_ans != INT_MIN) return right_ans;
    else return root->data;
}


//Largest BST
//Given a Binary tree, find the largest BST subtree.
//That is, you need to find the BST with maximum height in the given binary tree.
class isBST_quadruplet {
public:
    int minimum;
    int maximum;
    int height;
    bool x;
};

isBST_quadruplet * largestBSTSubtree_helper(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        isBST_quadruplet * ans = new isBST_quadruplet();
        ans->minimum = INT_MAX;
        ans->maximum = INT_MIN;
        ans->height = 0;
        ans->x = true;
        return ans;
    }

    isBST_quadruplet * left_ans = largestBSTSubtree_helper(root->left);
    isBST_quadruplet * right_ans = largestBSTSubtree_helper(root->right);
    
    bool result = (root->data > left_ans->maximum) && (root->data <= right_ans->minimum) && left_ans->x && right_ans->x;
    
    isBST_quadruplet * ans = new isBST_quadruplet();
    ans->minimum = min(root->data, min(left_ans->minimum, right_ans->minimum));
    ans->maximum = max(root->data, max(left_ans->maximum, right_ans->maximum));
    
    if (result == true) {
         ans->height = 1 + max(left_ans->height, right_ans->height);
    }
    else{
        ans->height = max(left_ans->height, right_ans->height);
    }
    
    ans->x = result;
    return ans;
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    return largestBSTSubtree_helper(root)->height;
}

//Replace with Sum of greater nodes
//Given a binary search tree, replace each nodes' data with the sum of all nodes' which are greater or equal than it.
//You need to include the current node's data also.
//That is, if in given BST there is a node with data 5,
//you need to replace it with sum of its data (i.e. 5) and all nodes whose data is greater than or equal to 5.

//void replaceWithLargerNodesSum(BinaryTreeNode<int> * root) {
//    int sum = replaceWithLargerNodesSum_helper(root, 0);
//}

//Path Sum Root to Leaf
//Given a binary tree and a number k,
//print out all root to leaf paths where the sum of all nodes value is same as the given number k.

void rootToLeafPathsSumToK_helper(BinaryTreeNode<int> *root, int k, string path) {
    if (root == NULL) {
        return;
    }
    
    if (root->left == NULL && root->right == NULL && root->data == k) {
        path = path + " " + to_string(root->data);
        cout << path.substr(1) << endl;
    }
    
    rootToLeafPathsSumToK_helper(root->left, k - root->data, path + " " + to_string(root->data));
    rootToLeafPathsSumToK_helper(root->right, k - root->data, path + " " + to_string(root->data));
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    rootToLeafPathsSumToK_helper(root, k, "");
}


//Print nodes at k distance from node.
//Given a binary tree, a node and an integer K, print nodes which are at K distance from the the given node.
void print_nodes_at_level_k(BinaryTreeNode<int> * root, int k) {
    if (root == NULL) {
        return;
    }
    if (k == 1) {
        cout << root->data << " ";
    }
    print_nodes_at_level_k(root->left, k - 1);
    print_nodes_at_level_k(root->right, k - 1);
}

int nodesAtDistanceK_helper(BinaryTreeNode<int> *root, int node, int k) {
    if (root == NULL) {
        return -1;
    }
    if (root->data == node) {
        print_nodes_at_level_k(root, k);
        return 0;
    }
    int left_distance = nodesAtDistanceK_helper(root->left, node, k - 1);
    
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    nodesAtDistanceK_helper(root, node, k);
}


//Sample input's.
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------
6 3 2 1 5 4 1 2 -1 -1 -1 1 -1 3 8 -1 -1 -1 -1 -1 -1 -1 -1
5 6 7 2 3 -1 1 -1 -1 -1 9 -1 -1 -1 -1
6 3 8 2 5 7 9 -1 -1 -1 -1 -1 -1 -1 -1
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
--------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int k; cin >> k;
    print_nodes_at_level_k(root,k);
    delete root;
}























//BINARY SEARCH TREES.
//LECTURE 13.
//CODING NINJAS.

#include <iostream>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
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
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

//Search an element in a BST.
BinaryTreeNode<int>* searchInBST(BinaryTreeNode<int> *root , int k){
    if (root == NULL) {
        return NULL;
    }
    
    BinaryTreeNode<int> * ans;
    if (root -> data == k) {
        ans = root;
    }
    else if (k < root -> data) {
        ans = searchInBST(root -> left, k);
    }
    else {
        ans = searchInBST(root -> right, k);
    }
    return ans;
}


//Print elements from a given range in a BST.
//Sample input
//8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
//6 10
void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
    if (root == NULL) {
        return;
    }
    
    if (root->data > k1) {
        elementsInRangeK1K2(root->left, k1, k2);
    }
    if (root->data >= k1 && root->data <= k2) {
        cout << root->data << " ";
    }
    if (root->data < k2) {
        elementsInRangeK1K2(root->right, k1, k2);
    }
}

//Check if a BT is BST.
//Given a binary tree with N number of nodes,
//check if that input tree is BST (Binary Search Tree) or not. If yes, return true, return false otherwise.
//Duplicate elements should be in right subtree.
//APPROACH 1.
//int minimum(BinaryTreeNode<int> * root) {
//    if (root == NULL) {
//        return INT_MAX;
//    }
//    int ans = min(root->data, min(minimum(root->left), minimum(root->right)));
//    return ans;
//}
//
//int maximum(BinaryTreeNode<int> * root) {
//    if (root == NULL) {
//        return INT_MAX;
//    }
//    int ans = max(root->data, max(maximum(root->left), maximum(root->right)));
//    return ans;
//}
//bool isBST(BinaryTreeNode<int> *root){
//    if (root == NULL) {
//        return true;
//    }
//    bool ans = (root->data > maximum(root->left)) && (root->data <= minimum(root->right)) && isBST(root->left) && isBST(root->right);
//    return ans;
//}

//APPROACH 2 (a)
//Using the inbuilt pairclass.
//pair<pair<int, int>, bool> isBST_helper(BinaryTreeNode<int> *root){
//    if (root == NULL) {
//        pair<pair<int, int>, bool> p;
//        p.first.first = INT_MAX;   //Minimum
//        p.first.second = INT_MIN;  //Maximum
//        p.second = true;           //isBST.
//        return p;
//    }
//    pair<pair<int, int>, bool> left_ans = isBST_helper(root->left);
//    pair<pair<int, int>, bool> right_ans = isBST_helper(root->right);
//    bool ans = (root->data > left_ans.first.second) && (root->data <= right_ans.first.first) && (left_ans.second) && (right_ans.second);
//
//    pair<pair<int, int>, bool> p;
//    p.first.first = min(root->data, min(left_ans.first.first, right_ans.first.first));
//    p.first.second = max(root->data, max(left_ans.first.second, right_ans.first.second));
//    p.second = ans;
//    return p;
//}

//APPROACH 2 (b)
//Using our own class.
//class isBST_class {
//public:
//    int minimum;
//    int maximum;
//    bool isBST_class_variable;
//};
//
//isBST_class isBST_helper(BinaryTreeNode<int> * root) {
//    if (root == NULL) {
//        isBST_class obj;
//        obj.minimum = INT_MAX;
//        obj.maximum = INT_MIN;
//        obj.isBST_class_variable = true;
//        return obj;
//    }
//    isBST_class left_ans = isBST_helper(root->left);
//    isBST_class right_ans = isBST_helper(root->right);
//    bool ans = (root->data > left_ans.maximum) && (root->data <= right_ans.minimum) && (left_ans.isBST_class_variable) && (right_ans.isBST_class_variable);
//
//    isBST_class obj;
//    obj.minimum = min(root->data, min(left_ans.minimum, right_ans.minimum));
//    obj.maximum = max(root->data, max(left_ans.maximum, right_ans.maximum));
//    obj.isBST_class_variable = ans;
//    return obj;
//}
//
//bool isBST(BinaryTreeNode<int> * root) {
//    return isBST_helper(root).isBST_class_variable;
//}

//APPROACH 3.
//TOP BOTTOM APPROACH
bool isBST_helper(BinaryTreeNode<int> *root, int minima = INT_MIN, int maxima = INT_MAX) {
    if (root == NULL) {
        return true;
    }
    
    if (root->data >= minima && root->data <= maxima) {
        return isBST_helper(root->left, minima, root->data - 1) && isBST_helper(root->right, root->data, maxima);
    } else {
        return false;
    }
}

bool isBST(BinaryTreeNode<int> * root) {
    return isBST_helper(root);
}


//CONSTRUCT A BST FROMA SORTED ARRAY.
//Given a sorted integer array A of size n which contains all unique elements.
//You need to construct a balanced BST from this input array. Return the root of constructed BST.
void preOrder(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return;
    }
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

BinaryTreeNode<int>* constructTree_helper(int *input, int si, int ei) {
    if (si > ei) {
        return NULL;
    }
    int mid = (si + ei) / 2;
    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(input[mid]);
    root->left = constructTree_helper(input, si, mid - 1);
    root->right = constructTree_helper(input, mid + 1, ei);
    return root;
}

BinaryTreeNode<int>* constructTree(int *input, int n) {
    return constructTree_helper(input, 0, n - 1);
}

//BST TO SORTED LL.
//Given a BST, convert it into a sorted linked list. Return the head of LL.
template <typename T>
class Node{
public:
    T data;
    Node<T> *next;
    Node(T data){
        this -> data = data;
        this -> next = NULL;
    }
};

class LL_pair{
public:
    Node<int> * head;
    Node<int> * tail;
    LL_pair(){
        head = NULL;
        tail = NULL;
    }
};

LL_pair constructBST_helper(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        LL_pair n;
        return n;
    }
    
    LL_pair left_ans = constructBST_helper(root->left);
    LL_pair right_ans = constructBST_helper(root->right);
    
    LL_pair ans;
    Node<int> * n = new Node<int>(root->data);
    ans.head = n;
    ans.tail = n;
    
    //if left LL exits.
    if (left_ans.head != NULL) {
        left_ans.tail->next = n;
        ans.head = left_ans.head;
    }
    
    //if right LL exists.
    if (right_ans.head != NULL) {
        n->next = right_ans.head;
        ans.tail = right_ans.tail;
    }
    
    return ans;
}

Node<int>* constructBST(BinaryTreeNode<int>* root) {
    return constructBST_helper(root).head;
}

//Root to node path in a binary tree (NOT BST).
vector<int> * get_root_to_node_path(BinaryTreeNode<int> * root, int k){
    if (root == NULL) {
        return NULL;
    }
    
    //If root itself hold the data tehn return vectorwith only root node.
    if (root->data == k) {
        vector<int> * output = new vector<int>;
        output->push_back(root->data);
        return output;
    }
    
    //Else check on the left-subtree.
    vector<int> * left_output = get_root_to_node_path(root->left, k);
    if (left_output != NULL) {
        left_output->push_back(root->data);
        return left_output;
    }
    
    //Else check on the right sub-tree.
    vector<int> * right_output = get_root_to_node_path(root->right, k);
    if (right_output != NULL) {
        right_output->push_back(root->data);
        return right_output;
    }
    
    //else return empty vector
    return NULL;
}


//Given a BST and an integer k.
//Find and return the path from the node with data k and root (if a node with data k is present in given BST).
//Return null otherwise. Assume that BST contains all unique elements.
vector<int>* findPath(BinaryTreeNode<int> *root , int data){
    if (root == NULL) {
        return NULL;
    }
    
    //If you can find the data at the root itself.
    if (root->data == data) {
        vector<int> * output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    
    //If the data is greater than or equal to root then the node must be on the rigth.
    if (data > root->data) {
        vector<int> * right_output = findPath(root->right, data);
        if (right_output != NULL) {
            right_output->push_back(root->data);
            return right_output;
        }
    }
    
    //If the data is smaller than the root then the data must beon the left.
    if (data < root->data) {
        vector<int> * left_output = findPath(root->left, data);
        if (left_output != NULL) {
            left_output->push_back(root->data);
            return left_output;
        }
    }
    
    //else no vector can be found.
    return NULL;
}



//Binary Tree inputs.
/*------------------------------------------------------------------------------------------------------------------------------
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
4 2 6 1 10 5 7 -1 -1 -1 -1 -1 -1 -1 -1
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
1 2 3 4 5 6 7 -1 -1 8 -1 -1 9 -1 -1 -1 -1 -1 -1
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
1 2 3 4 5 6 7 -1 -1 8 -1 -1 -1 -1 -1 -1
-------------------------------------------------------------------------------------------------------------------------------*/
int main() {
    BinaryTreeNode<int>* root = takeInput();
    int k;
    cin >> k;
    vector<int> *output = findPath(root, k);
    if(output != NULL) {
        for(int i = 0; i < output -> size(); i++) {
            cout << output -> at(i) << endl;
        }
    }
    delete root;
}


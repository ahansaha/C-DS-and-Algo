#include <iostream>
#include <climits>
#include <stack>
#include <queue>
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

void printLevelWise(BinaryTreeNode<int> * root) {
    queue<BinaryTreeNode<int> *> pending_nodes;
    pending_nodes.push(root);
    
    while (!pending_nodes.empty()) {
        BinaryTreeNode<int> * front = pending_nodes.front();
        pending_nodes.pop();
        cout << front -> data << ":";
        
        if (front -> left != NULL) {
            cout << "L:" << front -> left -> data << ",";
        } else {
            cout << "L:" << -1 << ",";
        }
        
        if (front -> right != NULL) {
            cout << "R:" << front -> right -> data << endl;
        } else {
            cout << "R:" << -1 << endl;
        }
        
        if (front -> left != NULL) pending_nodes.push(front -> left);
        if (front -> right != NULL) pending_nodes.push(front -> right);
    }
}


//Count the number of nodes.
int count_nodes(BinaryTreeNode<int> * root) {
    if (root == NULL) return 0;
    int s1 = count_nodes(root -> left);
    int s2 = count_nodes(root -> right);
    return 1 + s1 + s2;
}

//Find a node.
bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    if (root == NULL) return false;
    
    if (root -> data == x) {
        return true;
    }
    
    bool ans = false;
    ans = isNodePresent(root -> left, x);
    if (ans) return ans;
    ans = isNodePresent(root -> right, x);
    return ans;
}

//Height of a binary tree.
int height(BinaryTreeNode<int> *root) {
    if (root == NULL) return 0;
    return max(height(root -> left), height(root -> right)) + 1;
}

//Mirror
//Mirror the given binary tree.
//That is, right child of every nodes should become left and left should become right.
//void printLevelATNewLine(BinaryTreeNode<int> *root) {
//        queue<BinaryTreeNode<int>*> q;
//        q.push(root);
//        q.push(NULL);
//        while(!q.empty()) {
//            BinaryTreeNode<int> *first = q.front();
//            q.pop();
//            if(first == NULL) {
//                if(q.empty()) {
//                    break;
//                }
//                cout << endl;
//                q.push(NULL);
//                continue;
//            }
//            cout << first -> data << " ";
//            if(first -> left != NULL) {
//                q.push(first -> left);
//            }
//            if(first -> right != NULL) {
//                q.push(first -> right);
//            }
//        }
//}

//Mirror a binary tree.
//Mirror the given binary tree.
//That is, right child of every nodes should become left and left should become right.
void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    if (root == NULL) return;
    mirrorBinaryTree(root -> left);
    mirrorBinaryTree(root -> right);
    swap(root -> left, root -> right);
}

void postOrder(BinaryTreeNode<int> *root) {
    if (root == NULL) return;
    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data << " ";
}



//Construct tree from preOrder and inOrder.
//Input
/*
12
1 2 3 4 15 5 6 7 8 10 9 12
4 15 3 2 5 1 6 10 8 7 9 12
*/
BinaryTreeNode<int>* buildTree_helper(int *preorder, int *inorder, int pre_start, int pre_end, int in_start, int in_end) {
    
    //Base case.
    if (in_start > in_end || pre_start > pre_end) {
        return NULL;
    }
    //Find and create the root node.
    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(preorder[pre_start]);
    
    //Find the root in the inOrder array.
    int root_index = 0;
    for (root_index = in_start; root_index <= in_end; root_index++) {
        if (inorder[root_index] == preorder[pre_start])
            break;
    }
    
    //Calulate the left child's  left-preorder and left-inorder, and make connection  with root.
    int left_inorder_start = in_start;
    int left_inorder_end = root_index - 1;
    int left_preorder_start = pre_start + 1;
    int left_preorder_end = left_inorder_end - left_inorder_start + left_preorder_start;
    root -> left =  buildTree_helper(preorder, inorder, left_preorder_start, left_preorder_end, left_inorder_start, left_inorder_end);
    
    //Calculate theright child's right-preorder and right_inorder, and make connection  with root.
    int right_inorder_start = root_index + 1;
    int right_inorder_end = in_end;
    int right_preorder_start = left_preorder_end + 1;
    int right_preorder_end = pre_end;
    root -> right = buildTree_helper(preorder, inorder, right_preorder_start, right_preorder_end, right_inorder_start, right_inorder_end);
    
    return root;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLenght, int *inorder, int inLength) {
    return buildTree_helper(preorder, inorder, 0, preLenght - 1, 0, inLength - 1);
}


//Construct tree from preOrder and inOrder.
//Input
/*
8
8 4 5 2 6 7 3 1
4 8 2 5 1 6 3 7
*/

BinaryTreeNode<int>* getTreeFromPostorderAndInorder_helper
 (int *postorder, int *inorder, int post_start, int post_end, int in_start, int in_end) {
    
    //Base case.
    if (in_start > in_end || post_start > post_end) {
        return NULL;
    }
    //Find and create the root node.
    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(postorder[post_end]);
    
    //Find the root in the inOrder array.
    int root_index = 0;
    for (root_index = in_start; root_index <= in_end; root_index++) {
        if (inorder[root_index] == postorder[post_end])
            break;
    }
    
    //Calulate the left child's  left-postorder and left-inorder, and make connection  with root.
    int left_inorder_start = in_start;
    int left_inorder_end = root_index - 1;
    int left_postorder_start = post_start;
    int left_postorder_end = left_inorder_end - left_inorder_start + left_postorder_start;
    root -> left =  getTreeFromPostorderAndInorder_helper
     (postorder, inorder, left_postorder_start, left_postorder_end, left_inorder_start, left_inorder_end);
    
    //Calculate theright child's right-postorder and right_inorder, and make connection  with root.
    int right_inorder_start = root_index + 1;
    int right_inorder_end = in_end;
    int right_postorder_start = left_postorder_end + 1;
    int right_postorder_end = post_end - 1;
    root -> right = getTreeFromPostorderAndInorder_helper
     (postorder, inorder, right_postorder_start, right_postorder_end, right_inorder_start, right_inorder_end);
    
    return root;
}

BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder, int postLenght, int *inorder, int inLength) {
    return getTreeFromPostorderAndInorder_helper(postorder, inorder, 0, postLenght - 1, 0, inLength - 1);
}

//Diameter of the binay tree, a better approach.
pair<int, int> heightDiameter(BinaryTreeNode<int> * root) {
    if (root == NULL) {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int,int> rightAns = heightDiameter(root->right);
    int ld = leftAns.second;
    int lh = leftAns.first;
    int rd = rightAns.second;
    int rh = rightAns.first;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));
    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
}

//Min and max of a binary tree.
//Given a binary tree, find and return the min and max data value of given binary tree.
class PairAns {
public :
    int min;
    int max;
};

PairAns minMax(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        PairAns ans;
        ans.min = INT_MAX;
        ans.max = INT_MIN;
        return ans;
    }
    
    PairAns final_ans;
    final_ans.min = root -> data;
    final_ans.max = root -> data;
    
    PairAns left_ans = minMax(root -> left);
    final_ans.min = min(left_ans.min, final_ans.min);
    final_ans.max = max(left_ans.max, final_ans.max);
    
    PairAns right_ans = minMax(root -> right);
    final_ans.min = min(right_ans.min, final_ans.min);
    final_ans.max = max(right_ans.max, final_ans.max);
    
    return final_ans;
}



//ASSIGNMENT QUESTIONS ON BINARY TREES LECTURE 12.


//SUM OF ALL NODES.
//Given a binary tree, find and return the sum of all nodes.
int sumOfAllNodes(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return 0;
    }
    return root -> data + sumOfAllNodes(root -> left) + sumOfAllNodes(root -> right);
}

//BALANCED.
//Given a binary tree, check if its balanced
//i.e. depth of left and right subtrees of every node differ by at max 1.
//Return true if given binary tree is balanced, false otherwise.

//Approach 1.

//bool isBalanced(BinaryTreeNode<int> *root) {
//    if (root == NULL) {
//        return true;
//    }
//
//    int left_height = height(root -> left);
//    int right_height = height(root -> right);
//    int height_diff = abs(left_height - right_height);
//
//    bool ans;
//    if (height_diff <= 1) {
//        ans = true;
//        ans = isBalanced(root -> left) && isBalanced(root -> right);
//    } else {
//        return false;
//    }
//
//    return ans;
//}

//Approach 2.

pair<int, bool> isBalanced_helper(BinaryTreeNode<int> * root) {
    if (root == NULL) {
        pair<int, bool> p;
        p.first = 0;
        p.second = true;
        return p;
    }
    
    pair<int, bool> left_ans = isBalanced_helper(root -> left);
    pair<int, bool> right_ans = isBalanced_helper(root -> right);
    
    int hd = abs(left_ans.first - right_ans.first);
    bool x = left_ans.second && right_ans.second;
    int root_height = 1 + max(left_ans.first, right_ans.first);
    
    pair<int, bool> p;
    p.first = root_height;
    
    if (hd <= 1 && x == true) {
        p.second = true;
    } else {
        p.second = false;
    }
    
    return p;
}

bool isBalanced(BinaryTreeNode<int> *root) {
    return isBalanced_helper(root).second;
}

//Level Order Traversal.
//Given a binary tree, print the level order traversal. Make sure each level start in new line.
void printLevelATNewLine(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return;
    }
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    
    while (!q.empty()) {
        BinaryTreeNode<int> * front = q.front();
        q.pop();
        
        if (front == NULL && q.empty()) {
            break;
        }
        else if (front == NULL && !q.empty()) {
            cout << endl;
            q.push(NULL);
        }
        else if (front != NULL) {
            cout << front -> data << " ";
            if (front -> left != NULL) {
                q.push(front -> left);
            }
            if (front -> right != NULL) {
                q.push(front -> right);
            }
        }
    }
}
//REMOVE LEAF NODES.
//Remove all leaf nodes from a given Binary Tree. Leaf nodes are those nodes, which don't have any children.
BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return root;
    }
    
    if (root -> left == NULL && root -> right == NULL) {
        return NULL;
    }
    
    BinaryTreeNode<int> * left_ans = removeLeafNodes(root -> left);
    BinaryTreeNode<int> * right_ans = removeLeafNodes(root -> right);
    
    root -> left = left_ans;
    root -> right = right_ans;
    return root;
}


//Level wise linkedlist.
//Given a binary tree, write code to create a separate linked list for each level.
//You need to return the array which contains head of each level linked list.
template <typename T>
class node{
public:
    T data;
    node<T> * next;
    node(T data){
        this->data=data;
        this->next=NULL;
    }
};

void print(node<int> *head) {
    node<int> *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

vector<node<int>*> createLLForEachLevel(BinaryTreeNode<int> *root) {
    vector<node<int> *> v;
    if (root == NULL) {
        return v;
    }
    
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    
    node<int> * head = new node<int>(root -> data);
    v.push_back(head);
    node<int> * temp = head;
    node<int> * tail = head;
    
    while (!q.empty()) {
        BinaryTreeNode<int> * front = q.front();
        q.pop();
        
        if (front == NULL && q.empty()) {
            break;
        }
        else if (front == NULL && !q.empty()) {
            q.push(NULL);
            if (q.front() != NULL) {
                head = new node<int>(q.front() -> data);
                tail = head;
                v.push_back(head);
            }
        }
        else if (front != NULL) {
            if (front -> left != NULL) {
                q.push(front -> left);
            }
            if (front -> right != NULL) {
                q.push(front -> right);
            }
            if (q.front() != NULL) {
                temp = new node<int>(q.front() -> data);
                tail -> next = temp;
                tail = tail -> next;
            }
        }
    }
    return v;
}


//ZIG ZAG TREE.
//Given a binary tree, print the zig zag order
//i.e print level 1 from left to right, level 2 from right to left and so on.
//This means odd levels should get printed from left to right and even level right to left.
void zigZagOrder(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return;
    }
    stack<BinaryTreeNode<int> *> s1, s2;
    s1.push(root);
    
    while (!(s1.empty() && s2.empty())) {
        
        while (!s1.empty()) {
            cout << s1.top() -> data << " ";
            if (s1.top() -> left != NULL) {
                s2.push(s1.top() -> left);
            }
            if (s1.top() -> right != NULL) {
                s2.push(s1.top() -> right);
            }
            s1.pop();
        }
        cout << endl;
        
        while (!s2.empty()) {
            cout << s2.top() -> data << " ";
            if (s2.top() -> right != NULL) {
                s1.push(s2.top() -> right);
            }
            if (s2.top() -> left != NULL) {
                s1.push(s2.top() -> left);
            }
            s2.pop();
        }
        cout << endl;
    }
}

//Nodes without sibling
//Given a binary tree, print all nodes that don’t have a sibling.
void nodesWithoutSibling(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return;
    }
    
    if (root -> left != NULL && root -> right == NULL) {
        cout << root -> left -> data << endl;
    }
    if (root -> left == NULL && root -> right != NULL) {
        cout << root -> right -> data << endl;
    }
    
    nodesWithoutSibling(root -> left);
    nodesWithoutSibling(root -> right);
}

//Binary Tree inputs
/*------------------------------------------------------------------------------------------------------------------------------
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
1 2 3 4 5 6 7 -1 -1 8 -1 -1 9 -1 -1 -1 -1 -1 -1
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
1 2 3 4 5 6 7 -1 -1 8 -1 -1 -1 -1 -1 -1
-------------------------------------------------------------------------------------------------------------------------------*/
int main() {
    BinaryTreeNode<int>* root = takeInput();
    nodesWithoutSibling(root);
}
















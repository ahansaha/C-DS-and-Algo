#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;


//LECTURE 11 TRESS AND ASSIGNMENT QUESTIONS.


template <typename T>
class TreeNode {

public:
    T data;
    vector<TreeNode<T> *> children;
    
    TreeNode(T data) {
        this -> data = data;
    }
    
    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

void print_recursively(TreeNode<int> * root) {
    
    cout << root -> data << " : " ;
    
    for (int i = 0; i < root -> children.size(); i++) {
        cout << root -> children.at(i) -> data << ", ";
    }
    
    cout << endl;
    
    for (int i = 0; i < root -> children.size(); i++) {
        print_recursively(root -> children[i]);
    }
}

TreeNode<int> * take_input_recursively() {
    
    int root_data;
    cout << "Enter the root data" << endl;
    cin >> root_data;
    TreeNode<int> * root = new TreeNode<int>(root_data);
    
    int n;
    cout << "Enter the number of children for the node " << root_data << endl;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        TreeNode<int> * child = take_input_recursively();
        root -> children.push_back(child);
    }
    
    return root;
}

TreeNode<int> * takeInputLevelWise() {
    
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    
    queue<TreeNode<int>*> pendingNodes;
    
    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void printLevelWise(TreeNode<int>* root) {
    
    queue<TreeNode<int> *> pending_nodes;
    pending_nodes.push(root);
    
    while (!pending_nodes.empty()) {
        
        cout << pending_nodes.front() -> data << ":";
        TreeNode<int> * front = pending_nodes.front();
        pending_nodes.pop();
        
        for (int i = 0; i < front -> children.size(); i++) {
            
            if (i + 1 == front -> children.size()) {
                cout << front -> children.at(i) -> data;
            }
            else {
                cout << front -> children.at(i) -> data << ",";
            }
            
            pending_nodes.push(front -> children.at(i));
        }
        cout << endl;
    }
}


//Find the number of nodes in a tree recursively.
int node_count(TreeNode<int> * root) {
    
    int small_count = 0;
    for (int i = 0; i < root -> children.size(); i++) {
        small_count += node_count(root -> children.at(i));
    }
    return small_count + 1;
    
}

//Given a generic tree, count and return the sum of all nodes present in the given tree.
int sumOfNodes(TreeNode<int>* root) {
    int sum = 0;
    for (int i = 0; i < root -> children.size(); i++) {
        sum += sumOfNodes(root -> children.at(i));
    }
    return sum + root -> data;
}


//Given a generic tree, find and return the node with maximum data.
//You need to return the complete node which is having maximum data.
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    
    TreeNode<int> * max_node;
    
    if (root -> children.size() != 0) {
        max_node = root -> children.at(0);
    } else {
        return root;
    }
    
    for (int i = 0; i < root -> children.size(); i++) {
        TreeNode<int> * temp = maxDataNode(root -> children.at(i));
        if (max_node -> data < temp -> data) {
            max_node = temp;
        }
    }
    
    if (max_node -> data > root -> data) {
        return max_node;
    } else {
        return root;
    }
    
}


//Find the height of a tree.
int height(TreeNode<int>* root) {
    if (root == NULL) return 0;
    
    int total_height = 0;
    for (int i = 0; i < root -> children.size(); i++) {
        int child_height = height(root -> children.at(i));
        if (total_height < child_height) {
            total_height = child_height;
        }
    }
    return total_height + 1;
    
}

//Print nodes at a particular level or depth.
void print_nodes_at_level_K(TreeNode<int> * root, int k) {
    if (k == 0) {
        cout << root -> data << " ";
        return;
    }
    
    for (int i = 0; i < root -> children.size(); i++) {
        print_nodes_at_level_K(root -> children.at(i), k - 1);
    }
    
}

//Count the number of leaf nodes in a tree.
int numLeafNodes(TreeNode<int>* root) {
    //edge case
    if (root == NULL) {
        return 0;
    }
    
    if (root -> children.empty()) {
        return 1;
    }
    
    int count = 0;
    for (int i = 0; i < root -> children.size(); i++) {
        count += numLeafNodes(root -> children.at(i));
    }
    
    return count;
}


//Preorder traversal of a tree.
void preorder(TreeNode<int> * root) {
    if (root == NULL) return;
    cout << root -> data << " ";
    for (int i = 0; i < root -> children.size(); i++) {
        preorder(root -> children.at(i));
    }
}

//Post order traversal of a tree.
void postOrder(TreeNode<int>* root) {
    if (root == NULL) return;
    for (int i = 0; i < root -> children.size(); i++) {
        postOrder(root -> children.at(i));
    }
    cout << root -> data << " ";
}


/*---------------------------------------------------------------------------------------------------------------------------*/


//ASSIGNMENT
            //QUESTIONS
                       //FOR
                            //LECTURE 11


/*---------------------------------------------------------------------------------------------------------------------------*/

//CONTAINS X
//Given a generic tree and an integer x,
//check if x is present in the given tree or not.
//Return true if x is present, return false otherwise.
bool containsX(TreeNode<int>* root, int x) {
    if (root == NULL) return false;
    
    for (int i = 0 ; i < root -> children.size(); i++) {
        bool ans = containsX(root -> children.at(i), x);
        if (ans) {
            return true;
        }
    }
    
    if (root -> data == x) {
        return true;
    }
    
    return false;
}

//COUNT NODES
//Given a tree and an integer x,
//find and return the number of Nodes which are greater than x.
int nodesGreaterThanX(TreeNode<int> *root, int x) {
    if (root == NULL) return 0;
    int count = 0;
    if (root -> data > x) {
        count++;
    }
    for (int i = 0; i < root -> children.size(); i++) {
        count += nodesGreaterThanX(root -> children.at(i), x);
    }
    return count;
}

//NODE WITH MAXIMUM CHILD SUM
//Given a tree, find and return the node for which sum of data of all children and the node itself is maximum.
//In the sum, data of node itself and data of immediate children is to be taken.
class myClass {
public:
    TreeNode<int> * n;
    int sum;
};

myClass maxSumNode_helper(TreeNode<int> * root) {
    if (root == NULL) {
        myClass null;
        null.n = NULL;
        null.sum = -1;
        return null;
    }
    
    myClass max_obj;
    max_obj.n = root;
    max_obj.sum = root -> data;
    for (int i = 0; i < root -> children.size(); i++) {
        max_obj.sum += root -> children.at(i) -> data;
    }
        
    for (int i = 0; i < root -> children.size(); i++) {
        myClass child_obj = maxSumNode_helper(root -> children.at(i));
        if (child_obj.sum > max_obj.sum) {
            max_obj = child_obj;
        }
    }
    
    return max_obj;
}

TreeNode<int>* maxSumNode(TreeNode<int> *root){
    
    //Approach 1.
    
//    if (root == NULL) return root;
//
//    TreeNode<int> * max_node = root;
//    int root_sum = root -> data;
//    for (int i = 0; i < root -> children.size(); i++) {
//        root_sum += root -> children.at(i) -> data;
//    }
//
//    for (int i = 0; i < root -> children.size(); i++) {
//        TreeNode<int> * child_node = maxSumNode(root -> children.at(i));
//        int child_sum = child_node -> data;
//        for (int i = 0; i < child_node -> children.size(); i++) {
//            child_sum += child_node -> children.at(i) -> data;
//        }
//
//        if (child_sum > root_sum) {
//            max_node = child_node;
//        }
//    }
//    return max_node;
    
    //Approach 2. (Better approach)
    
    myClass max_obj = maxSumNode_helper(root);
    return max_obj.n;
}


//STRUCTURALLY IDENTICAL.
//Given two Generic trees, return true if they are structurally identical
//i.e. they are made of nodes with the same values arranged in the same way.
bool isIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    else if ((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL)) {
        return false;
    }
    
    if (root1 -> data != root2 -> data) {
        return false;
    }
    
    int i = 0, j = 0;
    for (i = 0, j = 0; i < root1 -> children.size() && j < root2 -> children.size(); i++, j++) {
        bool ans = isIdentical(root1 -> children.at(i), root2 ->children.at(j));
        if (ans == false) {
            return ans;
        }
    }
    
    return true;
}

//NEXT LARGER.
//Given a generic tree and an integer n. Find and return the node with next larger element in the Tree
//i.e. find a node with value just greater than n.
template <typename T>
class nextLargerElement_pair {
public:
    TreeNode<T> * node;
    T nextLarger;
};

nextLargerElement_pair<int> * nextLargerElement_helper(TreeNode<int> *root, int n) {
    if (root == NULL) {
        nextLargerElement_pair<int> * root_obj = new nextLargerElement_pair<int>;
        root_obj -> node = NULL;
        root_obj -> nextLarger = INT_MIN;
        return root_obj;
    }
    
    nextLargerElement_pair<int> * ans_obj = new nextLargerElement_pair<int>;
    if (n >= root -> data) {
        ans_obj -> node = NULL;
        ans_obj -> nextLarger = INT_MIN;
    }
    else {
        ans_obj -> node = root;
        ans_obj -> nextLarger = root -> data;
    }
    
    
    for (int i = 0; i < root -> children.size(); i++) {
        
        nextLargerElement_pair<int> * small_obj = nextLargerElement_helper(root -> children.at(i), n);
        
        if (ans_obj -> node == NULL) {
            ans_obj -> node = small_obj -> node;
            ans_obj -> nextLarger = small_obj -> nextLarger;
        }
        else if (ans_obj -> nextLarger > small_obj -> nextLarger && small_obj -> nextLarger > n) {
            ans_obj -> node = small_obj -> node;
            ans_obj -> nextLarger = small_obj -> nextLarger;
        }
    }
    
    return ans_obj;
}

TreeNode<int>* nextLargerElement(TreeNode<int> *root, int n) {
    //Appproach 1.
    //return nextLargerElement_helper(root, n) -> node;
    
    //Approach 2, (approach 1 is kinda useless).
    if (root == NULL) return NULL;
    
    TreeNode<int> * ans;
    if (n >= root -> data) {
        ans = NULL;
    } else {
        ans = root;
    }
    
    for (int i = 0; i < root -> children.size(); i++) {
        TreeNode<int> * small_ans = nextLargerElement(root -> children.at(i), n);
        
        if (ans == NULL) {
            ans = small_ans;
        }
        else if ((small_ans != NULL) && (small_ans -> data < ans -> data) && (small_ans -> data > n)) {
            ans = small_ans;
        }
    }
    
    return ans;
}

//SECOND LARGEST ELEMENT IN TREE.
//Given a generic tree, find and return the node with second largest value in given tree.
//Return NULL if no node with required value is present.
template <typename T>
class myPair {
public:
    TreeNode<T> * max;
    TreeNode<T> * smax;
    myPair(TreeNode<T> * max, TreeNode<T> * smax) {
        this -> max = max;
        this -> smax = smax;
    }
};

myPair<int> * secondLargest_helper(TreeNode<int> *root) {
    if (root == NULL) {
        myPair<int> * ans = new myPair<int>(NULL, NULL);
        return ans;
    }

    myPair<int> * ans = new myPair<int>(root, NULL);

    for (int i = 0; i < root -> children.size(); i++) {
        myPair<int> * temp = secondLargest_helper(root ->children.at(i));
        /*-----------------------------------------------------------------------------------------------------------------------------*/
        if (ans -> smax == NULL && temp -> smax == NULL) {
            if (ans -> max -> data < temp -> max -> data) {
                TreeNode<int> * x = ans -> max;
                ans -> max = temp -> max;
                ans -> smax = x;
            }
            else if (ans -> max -> data > temp -> max -> data) {
                ans -> smax = temp -> max;
            }
            else if (ans -> max -> data == temp -> max -> data) {
                ans -> smax = NULL;
            }
        }/*----------------------------------------------------------------------------------------------------------------------------*/
        else if (ans -> smax == NULL && temp -> smax != NULL) {
            if (ans -> max -> data < temp -> max -> data) {
                TreeNode<int> * x = ans -> max;
                ans -> max = temp -> max;
                ans -> smax = (x -> data < temp -> smax -> data) ? temp -> smax : x;
            }
            else if (ans -> max -> data > temp -> max -> data) {
                ans -> smax = temp -> max;
            }
            else if (ans -> max -> data == temp -> max -> data) {
                ans -> smax = temp -> smax;
            }
        }/*----------------------------------------------------------------------------------------------------------------------------*/
        else if (ans -> smax != NULL && temp -> smax == NULL) {
            if (ans -> max -> data < temp -> max -> data) {
                TreeNode<int> * x = ans -> max;
                ans -> max = temp -> max;
                ans -> smax = x;
            }
            else if (ans -> max -> data > temp -> max -> data) {
                ans -> smax = (ans -> smax -> data < temp -> max -> data) ? temp -> max : ans -> smax;
            }
            else if (ans -> max -> data == temp -> max -> data) {
                ans -> smax = ans -> smax;
            }/*------------------------------------------------------------------------------------------------------------------------*/
        }
        else if (ans -> smax != NULL && temp -> smax != NULL) {
            if (ans -> max -> data < temp -> max -> data) {
                TreeNode<int> * x = ans -> max;
                ans -> max = temp -> max;
                ans -> smax = (x -> data < temp -> smax -> data) ? temp -> smax : x;
            }
            else if (ans -> max -> data > temp -> max -> data) {
                ans -> smax = (ans -> smax -> data < temp -> max -> data) ? temp -> max : ans -> smax;
            }
            else if (ans -> max -> data == temp -> max -> data) {
                ans -> smax = (ans -> smax -> data < temp -> smax -> data) ? temp -> smax : ans -> smax;
            }/*------------------------------------------------------------------------------------------------------------------------*/
        }
    }
    return ans;
}

TreeNode <int>* secondLargest(TreeNode<int> *root) {
    return secondLargest_helper(root) -> smax;
}

//template <typename T>
//class lol{
//    public:
//    TreeNode<T> *l;
//    TreeNode<T> *Sl;
//    lol(TreeNode<T> *f, TreeNode<T> *s){
//        this->l=f;
//        this->Sl=s;
//    }
//};
//lol<int>* secondLargestHelper(TreeNode<int> *root){
//    if(root==NULL){
//        lol<int> *ans= new lol<int>(NULL,NULL);
//        return ans;
//    }
//
//    lol<int> *ans = new lol<int>(root,NULL);
//    for(int i=0; i<root->children.size(); i++){
//        lol<int> *temp= secondLargestHelper(root->children[i]);
//
//        if(temp->l->data > ans->l->data){
//            if(temp->Sl==NULL){
//                ans->Sl=ans->l;
//                ans->l= temp->l;
//            }
//            else{
//                if(temp->Sl->data > ans->l->data){
//                    ans->Sl=temp->Sl;
//                    ans->l=temp->l;
//                }
//                else{
//                    ans->Sl=ans->l;
//                    ans->l=temp->l;
//                }
//            }
//        }
//        else{
//            if(ans->l->data != temp->l->data && (ans->l->data > temp->l->data)){
//                ans->Sl=temp->l;
//            }
//        }
//    }
//    return ans;
//}
//TreeNode <int>* secondLargest(TreeNode<int> *root) {
//    return secondLargestHelper(root)->Sl;
//}

//REPLACE WITH DEPTH.
//In a given Generic Tree, replace each node with its depth value.
//You need to just update the data of each node, no need to return or print anything.
void printLevelATNewLine(TreeNode<int> *root) {
    queue<TreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        TreeNode<int> *first = q.front();
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
        for(int i = 0; i < first -> children.size(); i++) {
            q.push(first -> children[i]);
        }
    }
}

void replaceWithDepthValue_helper(TreeNode<int> *root, int depth) {
    if (root == NULL) {
        return;
    }
    
    root -> data = depth;
    for (int i = 0; i < root -> children.size(); i++) {
        replaceWithDepthValue_helper(root -> children.at(i), depth + 1);
    }
}

void replaceWithDepthValue(TreeNode<int> *root){
    replaceWithDepthValue_helper(root, 0);
}

//Sample tree input(s).
/*-------------------------------------------------------------------------------------------------------------------------------
10 3 20 30 40 2 40 50 0 0 0 0
10 3 5 6 12 2 9 8 2 100 3 0 0 0 0 0
5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0
-------------------------------------------------------------------------------------------------------------------------------*/
int main() {
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = secondLargest(root);
    if(ans == NULL) {
        cout << INT_MIN << endl;
    }
    else {
        cout << ans -> data << endl;
    }
}

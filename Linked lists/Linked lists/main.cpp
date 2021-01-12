#include <iostream>
#include <algorithm>
#include <string>

//LINKED LIST 1 AND 2 PROGRAMS FROM CODING NINJAS.

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};


//To take the input of the node.
Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

//To print the linked list.
void print(Node *head) {
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

//To find the length of the node.
int length(Node *head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head -> next;
    }
    return len + 1;
}

//Print ith node.
void printIthNode(Node *head, int i) {
    int idex = 0;
    while (head != NULL) {
        if (idex == i - 1) {
            cout << head -> data;
            break;
        }
        idex++;
        head = head -> next;
        
    }
}

//Delete a node from a linked list.
Node *deleteNode(Node *head, int pos) {
    
    //If the node is the first one.
    if (pos == 0) {
        Node * temp = head -> next;
        delete head;
        return temp;
    }
    
    Node *temp = head;
    while (temp != NULL && pos != 1) {
        temp = temp -> next;
        pos--;
    }
    
    if ( temp == NULL || temp -> next == NULL) {
        return head;
    }
    
    
    //If the node is the last one.
    if (temp -> next -> next == NULL) {
        Node * node_to_be_deleted = temp -> next;
        temp -> next = NULL;
        delete node_to_be_deleted;
        return head;
    }
    
    //If node lies in between.
    Node * node_to_be_deleted = temp -> next;
    temp -> next = temp -> next -> next;
    delete node_to_be_deleted;
    return head;
}

//Lenght of LL recursive.
int length_recursive(Node *head) {
    if (head == NULL) {
        return 0;
    }
    int small_length = length_recursive(head -> next);
    return small_length + 1;
}

//Insert a node recursively.
Node* insertNodeRec(Node *head, int i, int data) {
    //Base case.
    if (head == NULL) {
        return head;
    }
    
    //Small calculations to be done only on the zeroth index.
    if (i == 0) {
        Node * newNode = new Node(data);
        newNode -> next = head;
        return newNode;
    }
    
    //If i is not equal to zero, tell recursion to perform the node insertion.
    Node * new_head = insertNodeRec(head -> next, i - 1, data);
    
    //Recursion will return you the head of the linked list that you passed to it.
    //We need to attach the zeroth node that we have with ourselves
    //in the beginning of th linked list that recursion returns.
    head -> next = new_head;
    return head;
}

//Delete a node recursively.
Node* deleteNodeRec(Node *head, int i) {
    //Base case
    if (head == NULL) {
        return head;
    }
    
    //Small calculation to be done on the zeroth index only.
    if (i == 0) {
        Node * temp = head -> next;
        delete head;
        return temp;
    }
    
    //Else tell recursion to delete the ith node.
    Node * new_head = deleteNodeRec(head -> next, i - 1);
    
    //Same explaination here as the explanation in the above function.
    head -> next = new_head;
    return head;
}

//Find a node in a linked list, return the nodes index for the data 'n'.
int findNode(Node *head, int n) {
    
    Node * temp = head;
    int index = 0;
    
    while (temp != NULL) {
        if (temp -> data == n) {
            return index;
        }
        temp = temp -> next;
        index++;
    }
    
    return -1;
}

//Append last n to first.
Node *appendLastNToFirst(Node *head, int n) {
    
    if (n <= 0) {
        return head;
    }
    
    int len = length_recursive(head);
    cout << endl << len << endl;
    Node * temp = head;
    Node * new_head = NULL;
    
    if (len <= 1 || n <= 0) {
        return head;
    }
    
    int k = len - n - 1;
    while (temp != NULL && k != 0) {
        temp = temp -> next;
        k--;
    }
    
    new_head = temp -> next;
    temp -> next = NULL;
    
    temp = new_head;
    while (1) {
        if (temp -> next == NULL) {
            temp -> next = head;
            break;
        }
        temp = temp -> next;
    }
    
    return new_head;
}


//Eliminates duplicates from a LL.
Node *removeDuplicates(Node *head) {
    Node * temp = head;
    
    while (temp != NULL && temp -> next != NULL) {
        
        if (temp -> data == temp -> next -> data) {
            Node * node_to_be_deleted = temp ->next;
            temp -> next = temp -> next -> next;
            delete node_to_be_deleted;
        }
        else {
            temp = temp -> next;
        }
    }
    
    return head;
}

//Print reverse of a LL.
Node * reverse(Node *head)
{
    if (head == NULL) {
        return head;
    }
    else if (head -> next == NULL) {
        //cout << head -> data;
        return head;
    }
    
    Node * temp_1 = head;
    Node * temp_2 = head -> next;
    Node * temp_3 = head -> next -> next;
    head -> next = NULL;
    
    while (temp_3 != NULL) {
        
        temp_2 -> next = temp_1;
        
        //Update the pointers.
        temp_1 = temp_2;
        temp_2 = temp_3;
        temp_3 = temp_3 -> next;
        
    }
    
    temp_2 -> next = temp_1;
    
    //print(temp_2);
    
    return temp_2;
}

//Palindrome linked list.
bool isPalindrome(Node *head) {
    
    if (head == NULL || head -> next == NULL) {
        return true;
    }
    
    //Find the mid.
    int len = length_recursive(head);
    int mid = len/2;
    Node * temp = head;
    
    //Go till mid index - 1;
    while (temp != NULL && mid != 1) {
        temp = temp -> next;
        mid--;
    }
    
    //Reverse the second half of the LL.
    Node * head2 = (len % 2 == 0) ? temp -> next : temp -> next -> next;
    Node * temp2 = head2;
    
    head2 = reverse(head2);

    
    //Compare both the LL's.
    temp = head;
    temp2 = head2;
    
    while (temp2 != NULL) {
        if (temp -> data == temp2 -> data) {
            temp = temp -> next;
            temp2 = temp2 -> next;
        }
        else {
            return false;
        }
    }
    return true;
    
}

//Code : Midpoint of LL.
Node* midpoint_linkedlist(Node *head) {
    
    Node * slow = head;
    Node * fast = head;
    
    while (fast -> next != NULL && fast -> next -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    
    return slow;
}

//Merge two sorted LL's.
Node* mergeTwoLLs(Node *head1, Node *head2) {
    
    Node * l1 = head1, * l2 = head2;
    Node * head = NULL;
    Node * curr = NULL;
    bool x = true;
    
    while (1) {
        
        if (l1 -> data < l2 -> data) {
            
            //Decide head
            if (x) {
                head = head1;
                curr = head;
                if (l1 -> next != NULL) {
                    l1 = l1 -> next;
                }
                else {
                    l1 -> next = l2;
                    break;
                }
                x = false;
            }
            else {
                curr -> next = l1;
                curr = curr -> next;
                if (l1 -> next != NULL) {
                    l1 = l1 -> next;
                }
                else {
                    l1 -> next = l2;
                    break;
                }
            }
            
        }
        else {
            
            //Decide head
            if (x) {
                head = head2;
                curr = head;
                if (l2 -> next != NULL) {
                    l2 = l2 -> next;
                }
                else {
                    l2 -> next = l1;
                    break;
                }
                x = false;
            }
            else {
                curr -> next = l2;
                curr = curr -> next;
                if (l2 -> next != NULL) {
                    l2 = l2 -> next;
                }
                else {
                    l2 -> next = l1;
                    break;
                }
            }
        }
    }
    
    return head;
}

//Merge sort a LL.
Node* mergeSort(Node *head) {
   
    //Base case
    if (head == NULL || head -> next == NULL) {
        return head;
    }
    
    //Find the midpoint of the linked list.
    Node * mid = midpoint_linkedlist(head);
    
    //Split the LL.
    Node * head2 = mid -> next;
    mid -> next = NULL;
    
    //Call merge sort on left half and right half.
    Node * l1 = mergeSort(head);
    Node * l2 = mergeSort(head2);
    
    //Merge the two sorted LL's after calling the merge sorts on both halves.
    Node * output_head = mergeTwoLLs(l1, l2);
    return output_head;
}

//Reverse a LL recursively.
Node *reverse_linked_list_rec(Node *head) {
    
    if (head == NULL || head -> next == NULL) {
        return head;
    }
    
    //Tell recursion to reverse n - 1 nodes.
    Node * new_head = reverse_linked_list_rec(head -> next);
    
    //Small calculation to be performed only on the node that you kept for yourself. Just attach this node to the end of the
    //node that the recursion function has returned after reversing the linked list.
    head -> next -> next = head;
    head -> next = NULL;
    return new_head;
}

//Linked list 2 assignment.


//Find a node in LL recursively.
int indexOfNRecursive(Node *head, int n) {
    if (head == NULL) {
        return -1;
    }
    
    if (head -> data == n) {
        return 0;
    }
    
    int idex = indexOfNRecursive(head -> next, n);
    return (idex == -1) ? -1 : idex + 1;
}

//Even after odd Linked list.
Node* arrange_LinkedList(Node* head) {
    
    if (head == NULL || head -> next == NULL) {
        return head;
    }

    Node * even_head = NULL, * even_temp = NULL, * odd_head = NULL, * odd_temp = NULL;

    //Initialize the odd or even pointer.
    if (head -> data % 2 == 0) {
        even_head = head;
        even_temp = head;

        while (even_temp -> next != NULL) {
            if (even_temp -> next -> data % 2 == 0) {
                even_temp = even_temp -> next;
            }
            else if (even_temp -> next -> data % 2 != 0) {
                odd_head = even_temp -> next;
                odd_temp = odd_head;
                break;
            }
        }
        if (even_temp -> next == NULL) {
            return even_head;
        }
    }
    else {
        odd_head = head;
        odd_temp = head;

        while (1) {
            if (odd_temp -> next == NULL) {
                return odd_head;
            }
            if (odd_temp -> next -> data % 2 != 0) {
                odd_temp = odd_temp -> next;
            }
            else if (odd_temp -> next -> data % 2 == 0) {
                odd_temp = odd_head;
                break;
            }
        }
    }

    while (odd_temp != NULL && odd_temp -> next != NULL) {

        if (odd_temp -> next -> next == NULL && odd_temp -> next -> data % 2 == 0) {
            even_temp -> next = odd_temp -> next;
            even_temp = odd_temp -> next;
            odd_temp -> next = even_head;
            return odd_head;
        }

        if (odd_temp -> next -> data % 2 != 0) {
            odd_temp = odd_temp -> next;
        }
        else {

            if (even_head == NULL) {
                even_head = odd_temp -> next;
                even_temp = even_head;
            }
            else {
                even_temp -> next = odd_temp -> next;
                even_temp = odd_temp -> next;
            }

            odd_temp -> next = odd_temp -> next -> next;
        }
    }

    if (odd_temp -> next == NULL) {
        odd_temp -> next = even_head;
        even_temp -> next = NULL;
        return odd_head;
    }

    odd_temp -> next -> next = even_head;
    even_temp -> next = NULL;
    return odd_head;
    
}

//Delete every N node.
Node* skipMdeleteN(Node *head, int M, int N) {
        
        if (M == 0 || N == 0) {
            return NULL;
        }
        
        
        int M_idex = 0, N_idex = 0;
        Node * M_temp = head;
        bool flag = false;
        
        while (M_temp!=NULL) {
            
            while (M_idex != M - 1) {
                
                if (M_temp -> next != NULL) {
                    M_temp = M_temp -> next;
                } else {
                    flag = true;
                }
                M_idex++;
            }
            
            Node * N_temp = M_temp -> next;
            while (N_idex != N-1 && N_temp!=NULL) {
                
                if (N_temp -> next != NULL) {
                    Node* temp=N_temp;
                    N_temp = N_temp -> next;
                    free(temp);
                } else {
                    flag = true;
                }
                N_idex++;
            }
            if(N_temp!=NULL)
            M_temp -> next = N_temp -> next;
            
            if (flag) {
                return head;
            }
            
            M_temp = M_temp -> next;
            M_idex = 0;
            N_idex = 0;
        }
        
        return head;
}

//Swap two node's of LL.
Node* swap_nodes(Node *head,int i,int j) {
    
    if (i > j) {
        swap(i, j);
    }
    
    if (i == j) {
        return head;
    }
    
    Node * t1 = head;
    Node * t2 = head;
    
    //When swapping is related to the first node and j is the next node itself.
    if (i == 0 && j == 1) {
        t2 = t2 -> next;
        Node * new_head = t2;
        t1 -> next = t2 -> next;
        t2 -> next = t1;
        return new_head;
    }
    
    //Reach to the correct swapping positions.
    for (int p = 0; p < i - 1; p++) {
        
        if (t1 == NULL) {
            return head;
        }
    
        t1 = t1 -> next;
    }
    
    for (int q = 0; q < j - 1; q++) {
        
        if (t2 == NULL) {
            return head;
        }
        
        t2 = t2 -> next;
    }
    
    if (t2 -> next == NULL) {
        return head;
    }
    
    //Pre-saving the required addresses
    Node * t1_next = t1 -> next;
    Node * t2_next = t2 -> next;
    Node * t1_next_next = t1 -> next -> next;
    Node * t2_next_next = t2 -> next -> next;
    
    //Swapping operations.
    
    //When swapping is related to the first node.
    if (i == 0) {
        Node * new_head = t2_next;
        t2 -> next -> next = t1_next;
        t2 -> next = t1;
        t1 -> next = t2_next_next;
        return new_head;
    }
    
    //When two adjacent nodes have to be swapped.
    if (j - i == 1) {
        t1 -> next = t2_next;
        t2 -> next -> next = t2;
        t2 -> next = t2_next_next;
        return head;
    }
    
    //When two distant nodes have to be swapped.
    t1 -> next = t2 -> next;
    t2 -> next -> next = t1_next_next;
    t2 -> next = t1_next;
    t2 -> next -> next = t2_next_next;
    return head;
}

//You need to reverse first K elements then reverse next k elements and join the linked list and so on.
Node* kReverse(Node * head,int n) {
    
    if (head == NULL) {
        return head;
    }
    
    //Tell recursion to leave the first k-nodes and work on the rest of them.
    Node * temp = head;
    int counter = n;
    
    while (temp -> next != NULL && counter != 1) {
        temp = temp -> next;
        counter--;
    }
    
    Node * kth_head = temp -> next;
    temp -> next = NULL;
    
    Node * small_head = kReverse(kth_head, n);
    Node * reversed_head = reverse_linked_list_rec(head);
    
    head -> next = small_head;
    return reversed_head;
}

//Bubble sort a LL.
Node* bubble_sort_LinkedList_itr(Node* head) {

    int len = length_recursive(head);
    Node * temp = head;
    
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            
            if (temp -> data > temp -> next -> data) {
                head = swap_nodes(head, j, j + 1);
                print(head);
            }
            else {
                temp = temp -> next;
            }
        }
        temp = head;
    }
    return head;
}

int main() {
    
    Node* head=takeinput();
    head=bubble_sort_LinkedList_itr(head);
    print(head);
}



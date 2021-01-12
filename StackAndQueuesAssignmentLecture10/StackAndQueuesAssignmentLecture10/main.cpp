//
//  main.cpp
//  StackAndQueuesAssignmentLecture10
//
//  Created by Souvik Saha on 18/08/20.
//  Copyright © 2020 Souvik Saha. All rights reserved.
//
#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;


//Reverse the given stack.
void reverseStack_helper (stack<int> &input, stack<int> &extra) {
    
    if (extra.empty()) {
        return;
    }
    
    int x = extra.top();
    extra.pop();
    
    reverseStack_helper(input, extra);
    
    input.push(x);
    
}

void reverseStack(stack<int> &input, stack<int> &extra) {
    
    while (!input.empty()) {
        extra.push(input.top());
        input.pop();
    }
    
    reverseStack_helper(input, extra);
}


//Reverse the given queue.
void reverseQueue(queue<int> &q) {
    
    if (q.empty()) {
        return;
    }
    
    int x = q.front();
    q.pop();
    
    reverseQueue(q);
    
    q.push(x);
}

//Check redundant brackets.
bool checkRedundantBrackets(char *input) {
    
    int counter = 0;
    
    for (int i = 0; i < strlen(input) - 1; i++) {
        
        if (input[i] == '(' && input[i + 1] == ')') {
            return true;
        }
        
        if (input[i] == '(' && input[i + 1] == '(') {
            counter++;
        }
        else if (input[i] == ')' && input[i + 1] == ')' && counter == 1) {
            return true;
        }
    }
    
    return counter == 2;
}

//Stock span.
int* stockSpan(int *price, int size) {
    
    int * output = new int[size](); output[0] = 1;
    stack<int> s;
    s.push(0);
    int flag = false;
    
    for (int i = 1; i < size; i++) {
        
        while (!s.empty()) {
            if (price[i] > price[s.top()]) {
                s.pop();
            }
            else if (price[i] <= price[s.top()]) {
                output[i] = i - s.top();
                s.push(i);
                flag = true;
                break;
            }
        }
        
        if (flag == true) {
            flag = false;
            continue;
        }
        
        output[i] = i + 1;
        s.push(i);
    }
    return output;
}

//Minimum bracket reversal.
int countBracketReversals(char input[]){
    
    if (strlen(input) % 2 != 0) {
        return -1;
    }
    
    stack<char> s;
    for (int i = 0; i < strlen(input); i++) {
        
        if (input[i] == '{') {
            s.push(input[i]);
        }
        else if (!s.empty() && input[i] == '}' && s.top() == '{') {
            s.pop();
        }
        else if ((s.empty() || s.top() == '}') && input[i] == '}') {
            s.push(input[i]);
        }
        else if (!s.empty() && s.top() == '}' && input[i] == '{') {
            s.push(input[i]);
        }
    }
    
//    if (s.empty()) {
//        return 0;
//    }
//    
    char c1, c2; int count = 0;
    while (!s.empty()) {
        c1 = s.top();
        s.pop();
        c2 = s.top();
        s.pop();
        
        if (c1 == c2) {
            count++;
        }
        else if (c1 == '{' && c2 == '}') {
            count += 2;
        }
//        else if (c1 == '{' && c2 == '}') {
//            s.pop();
//        }
    }
    return count;
}



int main() {
    char input[10000];
    cin >> input;
    cout << countBracketReversals(input) << endl;
}

//
//  main.cpp
//  Stack || balanced parenthesis
//
//  Created by Souvik Saha on 18/08/20.
//  Copyright © 2020 Souvik Saha. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool checkBalanced(char *exp) {
    
    stack<char> s;
    
    for (int i = 0; i < strlen(exp); i++) {
        
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            s.push(exp[i]);
        }
        
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            
            if (s.empty()) {
                return false;
            }
            
            else if ((exp[i] == ')' && s.top() == '(') || (exp[i] == ']' && s.top() == '[') || (exp[i] == '}' && s.top() == '{')) {
                s.pop();
            }
            
            else return false;
    
        }
    }
    
    
    return s.empty();
}

int main() {
    char input[100000];
    cin.getline(input, 100000);
//    cin >> input;
    if(checkBalanced(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}


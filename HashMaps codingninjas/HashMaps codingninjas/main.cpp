//
//  main.cpp
//  HashMaps codingninjas
//
//  Created by Souvik Saha on 11/10/20.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;



int highestFrequency(int *input, int n){
    unordered_map<int, int> int_count;
    int max_frequency = 0;
    
    for (int i = 0; i < n; i++) {
        int_count[input[i]] += 1;
        if (max_frequency < int_count[input[i]]) {
            max_frequency = int_count[input[i]];
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (max_frequency == int_count[input[i]]) {
            return input[i];
        }
    }
    
    return -1;
}


//Code : Pair Sum to 0
void pairSum(int *input, int n) {
    unordered_map<int, int> my_map;
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        if (my_map[-(input[i])] >= 1) {
            ans = ans + my_map[-(input[i])];
        }
        my_map[input[i]] += 1;
    }
    
   cout << ans;
}


int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    pairSum(arr, n);

    delete[] arr;
}

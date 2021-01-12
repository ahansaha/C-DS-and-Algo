//
//  main.cpp
//  Hashmap assignments Lecture 14.
//
//  Created by Souvik Saha on 05/01/21.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;


//Extract unique characters. eg -> ababacd to abcd
string uniqueChar(string str) {
    string output = "";
    unordered_map<char, int> seen;
    for (int i = 0; i < str.length(); i++) {
        if (seen.count(str[i]) > 0) {
            continue;
        }
        seen[str[i]] += 1;
        output += str[i];
    }
    return output;
}

//Longest consecutive Sequence.
int getFirstElement(int * arr, int a, int b, int n) {
    int indexOfa = -1, indexOfb = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == a) {
            indexOfa = i;
        }
        else if (arr[i] == b) {
            indexOfb = i;
        }
    }
    int first = arr[min(indexOfa, indexOfb)];
    return first;
}
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    unordered_map<int, bool> map;
    vector<int> output;
    for (int i = 0; i < n; i++) {
        map[arr[i]] = false;
    }
    
    int max_length = 0, length = 0;
    for (int i = 0; i < n; i++) {
        if (map[arr[i]] == false) {
            map[arr[i]] = true;
            length++;
        } else {
            continue;
        }
        
        int number = arr[i], st = arr[i], end = arr[i];
        while (map.count(number + 1) > 0) {
            map[number + 1] = true;
            length++;
            number++;
        } end = number;
        
        
        number = arr[i];
        while (map.count(number - 1) > 0) {
            map[number - 1] = true;
            length++;
            number--;
        } st = number;
        
        if (length == max_length) {
            int first_element = getFirstElement(arr, output[0], st, n);
            if (first_element == st) {
                output.erase(output.begin(), output.end());
                output.push_back(st);
                if (st != end) output.push_back(end);
            }
        }
        else if (length > max_length) {
            output.erase(output.begin(), output.end());
            output.push_back(st);
            if (st != end) output.push_back(end);
            max_length = length;
        }
        length = 0;
        
    }
    
    return output;
}

//Pairs with difference K
//int getPairsWithDifferenceK(int *arr, int n, int k) {
//
//    Best solution.
//    unordered_map<int, int> freq;
//    int pairCount = 0;
//
//    for (int i = 0; i < n; ++i) {
//        int complement = arr[i] + k;
//        pairCount += freq[complement];
//
//        if (k != 0) {
//            complement = arr[i] - k;
//            pairCount += freq[complement];
//        }
//
//        ++freq[arr[i]];
//    }
//
//    return pairCount;
//
//}


int main() {
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}

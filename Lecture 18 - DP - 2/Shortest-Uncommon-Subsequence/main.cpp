#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;

//Recursive soln
//T(N) = O(N)
int solve(string s, string v) {
    if ((s.size() == 0 && v.size() != 0) || (s.size() == 0 && v.size() == 0)) {
        //Return worst possible answer.
        //We can return +infinity but constraint of s and v are up to 1000 so you can return 1001.
        return 1001;
    }
    
    if (s.size() != 0 && v.size() == 0) {
        return 1;
    }

    int ans1 = solve(s.substr(1), v);
    int ans2 = 1; //Assuming that s[0] will not be found in v.

    int idx = -1;
    for (int i = 0; i < v.size(); i++) {
        if (s[0] == v[i]) {
            idx = i;
            break; //We need to break in case of duplicate answers, in which case we consider the first possible s[0] found in v.
        }
    }

    if (idx != -1) {
        ans2 = solve(s.substr(1), v.substr(idx + 1)) + 1;
    }

    return min(ans1, ans2);
}

//Memoization
int solve_mem(string s, string v, int ** arr) {
    if ((s.size() == 0 && v.size() != 0) || (s.size() == 0 && v.size() == 0)) {
        //Return worst possible answer.
        //We can return +infinity but constraint of s and v are up to 1000 so you can return 1001.
        return 1001;
    }
    
    if (s.size() != 0 && v.size() == 0) {
        return 1;
    }
    
    if (arr[s.size()][v.size()] != -1) {
        return arr[s.size()][v.size()];
    }

    int ans1 = solve_mem(s.substr(1), v, arr);
    int ans2 = 1; //Assuming that s[0] will not be found in v.

    int idx = -1;
    for (int i = 0; i < v.size(); i++) {
        if (s[0] == v[i]) {
            idx = i;
            break; //We need to break in case of duplicate answers, in which case we consider the first possible s[0] found in v.
        }
    }

    if (idx != -1) {
        ans2 = solve_mem(s.substr(1), v.substr(idx + 1), arr) + 1;
    }
    
    arr[s.size()][v.size()] = min(ans1, ans2);
    return arr[s.size()][v.size()];
}

int solve_mem(string s, string v) {
    int ** arr = new int * [s.size() + 1];
    for (int i = 0; i < s.size() + 1; i++) {
        arr[i] = new int[v.size() + 1];
        fill_n(arr[i], v.size() + 1, -1);
    }

    int result = solve_mem(s, v, arr);

    for (int i = 0; i < s.size() + 1; i++) {
        delete [] arr[i];
    }
    delete [] arr;
    return result;
}

//Optimized Memoization
int solve_mem2(string s, string v, int ** arr, int ** next) {
    if ((s.size() == 0 && v.size() != 0) || (s.size() == 0 && v.size() == 0)) {
        //Return worst possible answer.
        //We can return +infinity but constraint of s and v are up to 1000 so you can return 1001.
        return 1001;
    }
    
    if (s.size() != 0 && v.size() == 0) {
        return 1;
    }
    
    if (arr[s.size()][v.size()] != -1) {
        return arr[s.size()][v.size()];
    }

    int ans1 = solve_mem2(s.substr(1), v, arr, next);
    int ans2 = 1; //Assuming that s[0] will not be found in v.

    int idx = next[s.size()][v.size()];

    if (idx != -1) {
        ans2 = solve_mem2(s.substr(1), v.substr(idx + 1), arr, next) + 1;
    }
    
    arr[s.size()][v.size()] = min(ans1, ans2);
    return arr[s.size()][v.size()];
}

int solve_mem2(string s, string v) {
    //Make the dp array.
    int ** arr = new int * [s.size() + 1];
    for (int i = 0; i < s.size() + 1; i++) {
        arr[i] = new int[v.size() + 1];
        fill_n(arr[i], v.size() + 1, -1);
    }
    
    //Make the next array.
    int ** next = new int * [s.size() + 1];
    for (int i = 0; i < s.size() + 1; i++) {
        next[i] = new int[v.size() + 1];
        fill_n(next[i], v.size() + 1, -1);
    }

    //Build the next array. i, j represent the size of the s and v strings respectively.
    for (int i = 0; i < s.size() + 1; i++) {
        for (int j = 0; j < v.size() + 1; j++) {
            int idx_1 = s.size() - i;
            int idx_2 = v.size() - j;

            for (int k = idx_2; k < v.size(); k++) {
                if (s[idx_1] == v[k]) {
                    next[i][j] = k - (v.size() - j);
                    break;
                }
            }
        }
    }

    int result = solve_mem2(s, v, arr, next);

    for (int i = 0; i < s.size() + 1; i++) {
        delete [] arr[i];
        delete [] next[i];
    }
    delete [] arr;
    delete [] next;
    return result;
}

int main() {
    string s, v;
    cin >> s >> v;
    cout << solve(s, v) << endl;
    cout << solve_mem(s, v) << endl;
    cout << solve_mem2(s, v) << endl;
}

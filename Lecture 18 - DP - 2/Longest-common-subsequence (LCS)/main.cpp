#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;


//BRUTE FORCE
int lcs (string s, string t) {
    if (s.empty() || t.empty())
        return 0;
    
    if (s[0] == t[0])
        return lcs(s.substr(1), t.substr(1)) + 1;
    
    int a = lcs(s, t.substr(1));
    int b = lcs(s.substr(1), t);
    return max({a, b});
}

//MEMOIZATION
int lcs_mem (string s, string t, int ** arr) {
    if (s.empty() || t.empty())
        return 0;
    
    if (arr[s.size()][t.size()] != -1)
        return arr[s.size()][t.size()];
    
    int ans = -1;
    if (s[0] == t[0])
        ans = lcs_mem(s.substr(1), t.substr(1), arr) + 1;
    else {
        int a = lcs_mem(s, t.substr(1), arr);
        int b = lcs_mem(s.substr(1), t, arr);
        ans = max({a, b});
    }
    
    arr[s.size()][t.size()] = ans;
    return ans;
}

int lcs_mem (string s, string t) {
    int ** arr = new int * [s.size() + 1];
    for (int i = 0; i < s.size() + 1; i++) {
        arr[i] = new int[t.size() + 1];
        fill_n(arr[i], t.size() + 1, -1);
    }
    int result = lcs_mem(s, t, arr);
    for (int i = 0; i < s.size() + 1; i++) {
        delete [] arr[i];
    }
    delete [] arr;
    return result;
}

//DP
int lcs_DP (string s, string t) {
    int ** arr = new int * [s.size() + 1];
    for (int i = 0; i < s.size() + 1; i++) {
        arr[i] = new int[t.size() + 1];
        fill_n(arr[i], t.size() + 1, -1);
    }
    
    for (int i = 0; i < s.size() + 1; i++) { //Fill zeroes for 0th row.
        arr[i][0] = 0;
    }
    
    for (int j = 0; j < t.size() + 1; j++) { //Fill zeroes for the 0th column.
        arr[0][j] = 0;
    }
    
    for (int i = 1; i < s.size() + 1; i++) {
        for (int j = 1; j < t.size() + 1; j++) {
            
            if (s[s.size() - i] == t[t.size() - j]) { //Here you have to check for the string's at this particular iteration, hence                                         in every iteration you have to calculate both the sub strings.
                arr[i][j] = 1 + arr[i - 1][j - 1];
                
            } else {
                arr[i][j] = max({arr[i - 1][j], arr[i][j - 1]});
                
            }
        }
    }
    
    int result = arr[s.size()][t.size()];
    for (int i = 0; i < s.size() + 1; i++) {
        delete [] arr[i];
    }
    delete [] arr;
    return result;
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << lcs(s, t) << endl;
    cout << lcs_mem(s, t) << endl;
    cout << lcs_DP(s, t) << endl;
}


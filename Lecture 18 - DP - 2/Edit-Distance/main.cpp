#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


//BRUTE FORCE
int editDistance (string s1, string s2) {
    if (s1.length() == 0)
        return (int) s2.length();
    else if (s2.length() == 0)
        return (int) s1.length();
    
    if (s1[0] == s2[0])
        return editDistance(s1.substr(1), s2.substr(1));
    
    int a = 1 + editDistance(s1.substr(1), s2);
    int b = 1 + editDistance(s1, s2.substr(1));
    int c = 1 + editDistance(s1.substr(1), s2.substr(1));
    return min({a, b, c});
}

//MEMOIZATION
int editDistance_mem (string s1, string s2, int ** arr) {
    if (s1.size() == 0 || s2.size() == 0)
        return (int) max(s1.size(), s2.size());
    
    if (arr[s1.size()][s2.size()] != -1)
        return arr[s1.size()][s2.size()];
    
    int ans = -1;
    if (s1[0] == s2[0]) {
        ans = editDistance_mem(s1.substr(1), s2.substr(1), arr);
    }
    else {
        int a = 1 + editDistance_mem(s1.substr(1), s2, arr);
        int b = 1 + editDistance_mem(s1, s2.substr(1), arr);
        int c = 1 + editDistance_mem(s1.substr(1), s2.substr(1), arr);
        ans = min({a, b, c});
    }
    arr[s1.size()][s2.size()] = ans;
    return ans;
}

int editDistance_mem (string s1, string s2) {
    int ** arr = new int * [s1.size() + 1];
    for (int i = 0; i < s1.size() + 1; i++) {
        arr[i] = new int[s2.size() + 1];
        fill_n(arr[i], s2.size() + 1, -1);
    }
    int result = editDistance_mem(s1, s2, arr);
    for (int i = 0; i < s1.size() + 1; i++) {
        delete [] arr[i];
    }
    delete [] arr;
    return result;
}

//DP
int editDistance_DP (string s1, string s2) {
    int ** arr = new int * [s1.size() + 1];
    for (int i = 0; i < s1.size() + 1; i++) {
        arr[i] = new int[s2.size() + 1];
        fill_n(arr[i], s2.size() + 1, -1);
    }
    
    for (int j = 0; j < s2.size() + 1; j++) arr[0][j] = j;
    for (int i = 0; i < s1.size() + 1; i++) arr[i][0] = i;
    
    for (int i = 1; i < s1.size() + 1; i++) {
        for (int j = 1; j < s2.size() + 1; j++) {
            
            if (s1[s1.size() - i] == s2[s2.size() - j]) {
                arr[i][j] = arr[i - 1][j - 1];
            } else {
                arr[i][j] = min({1 + arr[i - 1][j],
                                 1 + arr[i - 1][j - 1],
                                 1 + arr[i][j - 1]});
            }
        }
    }
    
    int result = arr[s1.size()][s2.size()];
    for (int i = 0; i < s1.size() + 1; i++) {
        delete [] arr[i];
    }
    delete [] arr;
    return result;
}

int main() {
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2) << endl;
    cout << editDistance_mem(s1, s2) << endl;
    cout << editDistance_DP(s1, s2) << endl;
}

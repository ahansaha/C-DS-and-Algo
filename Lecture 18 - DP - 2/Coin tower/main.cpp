#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;


//BRUTE FORCE
//T(N) = O(3 ^ N)
string findWinner(int n, int x, int y) {
    if (n <= 1 || n == x || n == y)
        return "Beerus";
    
    string a = findWinner(n - 1, x, y);
    string b = findWinner(n - x, x, y);
    string c = findWinner(n - y, x, y);
    
    if (a == "Whis") return "Beerus";
    else if (b == "Whis") return "Beerus";
    else if (c == "Whis") return "Beerus";
    else return "Whis";
}

//MEMOIZATION
//T(N) = O(N)
//T(N) = O(N)
string findWinner_memo (int n, int x, int y, string * arr) {
    if (n <= 1 || n == x || n == y)
        return "Beerus";
    
    if (arr[n] != "")
        return arr[n];
    
    string a = findWinner_memo(n - 1, x, y, arr);
    string b = findWinner_memo(n - x, x, y, arr);
    string c = findWinner_memo(n - y, x, y, arr);
    
    string ans = "";
    if (a == "Whis") ans = "Beerus";
    else if (b == "Whis") ans = "Beerus";
    else if (c == "Whis") ans = "Beerus";
    else ans = "Whis";
    
    arr[n] = ans;
    return arr[n];
}

string findWinner_memo (int n, int x, int y) {
    string * arr = new string[n + 1];
    fill_n(arr, n + 1, "");
    string result = findWinner_memo(n, x, y, arr);
    delete [] arr;
    return result;
}

//DP
//T(N) = O(N)
//T(N) = O(N)
string findWinner_DP (int n, int x, int y) {
    string * arr = new string[n + 1];
    fill_n(arr, n + 1, "");
    
    string a = "", b = "", c = "";
    
    arr[0] = "Beerus";
    arr[1] = "Beerus";
    for (int i = 2; i < n + 1; i++) {
        
        if (i == x || i == y) {
            arr[i] = "Beerus";
            continue;
        }
        
        a = arr[i - 1];
        b = (i - x >= 0) ? arr[i - x] : "";
        c = (i - y >= 0) ? arr[i - y] : "";
        
        if (a == "Whis") arr[i] = "Beerus";
        else if (b == "Whis") arr[i] = "Beerus";
        else if (c == "Whis") arr[i] = "Beerus";
        else arr[i] = "Whis";
       
    }
    
    string result = arr[n];
    delete [] arr;
    return result;
}

int main () {
    int n, x, y;
    cin >> n >> x >> y;
    cout << findWinner(n, x, y) << endl;
    cout << findWinner_memo(n, x, y) << endl;
    cout << findWinner_DP(n, x, y) << endl;
}


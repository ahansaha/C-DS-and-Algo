#include <iostream>
#include <climits>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

//BRUTE FORCE
int getAllWays(int a, int b, int i = 1) {
    if (pow(i, b) > a)
        return 0;
    if (pow(i, b) == a)
        return 1;

    int x = getAllWays(a - pow(i, b), b, i + 1);
    int y = getAllWays(a, b, i + 1);
    return x + y;
}

//MEMOIZATION
int getAllWays_mem(int a, int b, int ** arr, int i = 1) {
    if (pow(i, b) > a)
        return 0;
    if (pow(i, b) == a)
        return 1;
    
    if (arr[a][i] != -1)
        return arr[a][i];

    int x = getAllWays_mem(a - pow(i, b), b, arr, i + 1);
    int y = getAllWays_mem(a, b, arr, i + 1);
    
    arr[a][i] = x + y;
    return x + y;
}

int getAllWays_mem (int a, int b) {
    int ** arr = new int * [a + 1];
    for (int i = 0; i < a + 1; i++) {
        int siz = (int) pow(a, 1.0/b);
        arr[i] = new int[siz + 1];
        for (int j = 0; j < siz + 1; j++) {
            arr[i][j] = -1;
        }
    }
    int result = getAllWays_mem(a, b, arr);
    
    for (int i = 0; i < a + 1; i++) {
        delete arr[i];
    }
    delete [] arr;
    return result;
}

//DP
long getAllWays_DP(long a, long b) {
    long upto = (long) pow(a, 1.0/b) + 1;
    int * arr = new int[a + 1];
    fill_n(arr, a + 1, 0);
    arr[0] = 1;
    
    cout << upto << endl;
    for(int index = 1; index <= upto; ++index){
        for(long j = a; j >= pow(index, b); j--){
            arr[j] += arr[j - (int) pow(index, b)];
        }
    }
    return arr[a];
}


int main() {
    int a, b; cin >> a >> b;
    
    cout << getAllWays_DP(a, b) << endl;
//    cout << getAllWays_mem(a, b) << endl;
//    cout << getAllWays(a, b) << endl;
    return 0;
}

#include <iostream>
#include <cmath>
#define lli long long int
using namespace std;

//BRUTE FORCE
long long int balancedBTs(int n) {
    if (n == 1 || n == 0) return 1;
    if (n < 1) return 0;
	long long int mod = 1e9 + 7;
	
// 	int a = (balancedBTs (n - 1) * balancedBTs (n - 1)) % mod;
// 	int b = (balancedBTs (n - 1) * balancedBTs (n - 2)) % mod; 
// 	int c = (balancedBTs (n - 2) * balancedBTs (n - 1)) % mod;
// 	return (a + b + c) % mod;

    long long int a = balancedBTs (n - 1) % mod;
	long long int b = balancedBTs (n - 2) % mod; 
	
	// return (((a * a)) % mod + ((a * b)) % mod + ((b * a)) % mod) % mod;
	
    return     (((a * a))     % mod 
        	+  (2 * a * b)   % mod)
            % mod;
}

//Memoization
long long int balancedBTs_Memoization (int n, long long int * arr) {
	if (n <= 1) return 1; 
	long long int mod = 1e9 + 7;
	
	if (arr[n] != -1) return arr[n];
	
    long long int a = balancedBTs_Memoization (n - 1, arr) % mod;
	long long int b = balancedBTs_Memoization (n - 2, arr) % mod; 
	
	arr[n] =  (((a * a)  % mod)  +  ((2 * a * b)  % mod)) % mod;
    return arr[n];
}

long long int balancedBTs_Memoization (int n) {
	long long int * arr = new long long int[n + 1];
	fill_n(arr, n + 1, -1);
	long long int result = balancedBTs_Memoization(n, arr);
	delete [] arr;
	return result;
}

//DP

//long long int as lli for easy coding. Check macro below header file. Don't do this during development though. 
lli balancedBTs_DP (int n) {
	lli * arr = new lli[n + 1];
	
	arr[0] = 1;
	arr[1] = 1;
	lli mod = 1e9 + 7;
	
	for (lli i = 2; i < n + 1; i++) {
		
		lli a = arr[i - 1];
		lli b = arr[i - 2];
		
		arr[i] = (((a * a)  % mod)  +  ((2 * a * b)  % mod)) % mod;
	}
	
	lli result = arr[n];
	delete [] arr;
	return result;
}



int main() {
    int n;
    cin >> n;
//    cout << balancedBTs (n);
//	cout << balancedBTs_Memoization (n);
	cout << balancedBTs_DP (n);
}

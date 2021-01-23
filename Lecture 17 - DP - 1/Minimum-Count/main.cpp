#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

//Brute force
int minCount(int n) {
	if (n <= 1) return n;
	
	int ans = INT_MAX;
	for (int i = 1; pow(i, 2) <= pow(sqrt(n), 2); i++) {
		
		int temp = minCount (n - pow(i, 2)) + 1;
		ans = min({ans, temp});
	}
	
	return ans;
}

//MEMOIZATION
int minCount_Memoization(int n, int * arr) {
	if (n <= 1) return n;
	if (arr[n] != -1) return arr[n];
	
	int ans = INT_MAX;
	for (int i = 1; pow(i, 2) <= pow(sqrt(n), 2); i++) {
		
		int temp = minCount_Memoization (n - pow(i, 2), arr) + 1;
		ans = min({ans, temp});
	}
	arr[n] = ans;
	return ans;
}

int minCount_Memoization (int n) {
	int * arr = new int[n + 1];
	fill_n(arr, n + 1, -1);
	int result = minCount_Memoization (n, arr);
	delete [] arr;
	return result;
}

//DP
int minCount_DP (int n) {
	int * arr = new int[n + 1];
	arr[0] = 0;
	arr[1] = 1;
	
	int ans = INT_MAX;
	for (int i = 2; i < n + 1; i++) {
		for (int j = 1; pow(j, 2) <= i; j++) {
			int temp = arr[i - (int) pow(j, 2)] + 1; //For some reason 'pow' function here keep throwing data type double expected error, hence I type casted it.
			ans = min({ans, temp});
		}
		arr[i] = ans;
		ans = INT_MAX;  
		// Make sure you reset the value of ans for ervery ith iteration to calculate the correct value for evry ith number,
		//otherwise you would be using the previous value of ans in every iteration resulting in an incorrect result.
	}
	
	int result = arr[n];
	delete [] arr;
	return result;
}

int main()
{
	int n;
	cin >> n;
//	cout << minCount(n);
//	cout << minCount_Memoization(n);	
	cout << minCount_DP(n);
}
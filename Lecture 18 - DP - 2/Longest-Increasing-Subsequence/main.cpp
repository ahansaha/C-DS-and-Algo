#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;


//BRUTE FORCE
//T(N) = O(N ^ 2)
//S(N) = O(N)
int longestIncreasingSubsequence (int* arr, int n, int prev = INT_MIN) {
	if (n <= 0)
		return 0;
		
	int a = INT_MIN;
	if (prev < arr[0])
		a = 1 + longestIncreasingSubsequence(arr + 1, n - 1, arr[0]);
		
	int b = longestIncreasingSubsequence(arr + 1, n - 1, prev);
	return max(a, b);
}

//MEMOIZATION
//T(N) = O(N * prev)
//S(N) = O(N * prev)
int longestIncreasingSubsequence_mem (int* arr, int ** output, int n, int prev = INT_MIN) {
	if (n <= 0)
		return 0;
	
	if (prev != INT_MIN) {
		if (output[n][prev] != -1) {
			return output[n][prev];
		}
	}
	
	int a = INT_MIN;
	if (prev < arr[0])
		a = 1 + longestIncreasingSubsequence_mem(arr + 1, output, n - 1, arr[0]);
		
	int b = longestIncreasingSubsequence_mem(arr + 1, output, n - 1, prev);
	
	if (prev != INT_MIN) {
		output[n][prev] = max(a, b);
		return output[n][prev];
	}
	return max(a, b);
}

int find_max_prev (int * arr, int n) {
	int ans = arr[0];
	for (int i = 1; i < n; i++) {
		if (ans < arr[i]) {
			ans = arr[i];
		}
	}
	return ans;
}

int longestIncreasingSubsequence_mem (int * arr, int n) {
	int prev = find_max_prev(arr, n);
	int ** output = new int * [n + 1];
	for (int i = 0; i < n + 1; i++) {
		output[i] = new int[prev + 1];
		fill_n(output[i], prev + 1, -1);
	}
	int result = longestIncreasingSubsequence_mem(arr, output, n);
	for (int i = 0; i < n + 1; i++) {
		delete [] output[i];
	}
	delete [] output;
	return result;
}

//DP
//T(N) = O(N ^ 2)
//S(N) = O(N)
int longestIncreasingSubsequence_DP (int * arr, int n) {
	int * output = new int[n];
	output[0] = 1;
	
	for (int i = 1; i < n; i++) {
		output[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] >= arr[i]) {
				continue;
			}
			int possibleAns = 1 + output[j];
			if (possibleAns > output[i]) {
				output[i] = possibleAns;
			}
		}
	}
	
	int maxLength = output[0];
	for (int i = 1; i < n; i++) {
		if (maxLength < output[i]) {
			maxLength = output[i];
		}
	}
	
	delete [] output;
	return maxLength;
}

//DP and BINARY SEARCH
//T(N) = O(N LOG N)
//S(N) = O(N)
int binarySearch (vector<int> output, int si, int ei, int x) {
	if (si > ei) {
		return si;
	}

	int mid = (si + ei) / 2;
	
	if (output[mid] == x) {
		return mid;
	}
	else if (output[mid] > x) {
		return binarySearch(output, si, mid - 1, x);
	} 
	else {
		return binarySearch(output, mid + 1, ei, x);
	}
}

int longestIncreasingSubsequence_DP_BinarySearch (int * arr, int n) {
	vector<int> output;
	for (int i = 0; i < n; i++) {
		int outputIndex = binarySearch(output, 0, output.size() - 1, arr[i]);
		
		int lastIndexOfOutput = output.size() - 1;
		if (outputIndex > lastIndexOfOutput) {
			output.push_back(arr[i]);
		} else {
			output[outputIndex] = arr[i];
		}
	}
	return output.size();
}


int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

	cout << longestIncreasingSubsequence(arr, n) << endl;
	cout << longestIncreasingSubsequence_mem(arr, n) << endl;
	cout << longestIncreasingSubsequence_DP(arr, n) << endl;
	cout << longestIncreasingSubsequence_DP_BinarySearch(arr, n) << endl;
}

#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;


//BRUTE FORCE
//T(N) = O(N ^ N)
int matrixChainMultiplication (int* arr, int si, int ei) {
	
	if (si >= ei || ei - si == 1) return 0;
	
	int ans = INT_MAX;
	for (int i = si + 1; i <= ei - 1; i++) {
		int temp = matrixChainMultiplication(arr, si, i) + matrixChainMultiplication(arr, i, ei) + (arr[si] * arr[i] * arr[ei]);
		ans = min(ans, temp);
	}
	return ans;
}

int matrixChainMultiplication (int* arr, int n) {
	//Since arr size is n + 1, we pass ei as n.
    return matrixChainMultiplication(arr, 0, n);
}

//MEMOIZATION
int matrixChainMultiplication_mem (int* arr, int ** output, int si, int ei) {
	
	if (si >= ei || ei - si == 1) return 0;
	
	if (output[si][ei] != -1) {
		return output[si][ei];
	}
	
	int ans = INT_MAX;
	for (int i = si + 1; i <= ei - 1; i++) {
		int temp = matrixChainMultiplication_mem(arr, output, si, i) + matrixChainMultiplication_mem(arr, output, i, ei) + (arr[si] * arr[i] * arr[ei]);
		ans = min(ans, temp);
	}
	
	output[si][ei] = ans;
	return ans;
}

int matrixChainMultiplication_mem (int* arr, int ei, int si = 0) {
	//si can go from 0 to n - 1, or form to 0 to ei - 1, same thing. Hence size needed for 0 to ei - 1 is ei.
	//ei can go from 1 to n, or from 1 to ei, hence size needed will be ei + 1. 
	
	int ** output = new int * [ei];
	for (int i = 0; i < ei; i++) {
		output[i] = new int[ei + 1];
		fill_n(output[i], ei + 1, -1);
	}
	int result = matrixChainMultiplication_mem(arr, output, si, ei);
	for (int i = 0; i < ei; i++) {
		delete output[i];
	}
	delete [] output;
	return result;
}

//DP
//T(N) = O(N ^ 3)
//S(N) = O(N * N)
int matrixChainMultiplication_DP (int* arr, int ei) {
	int ** output = new int * [ei];
	for (int i = 0; i < ei; i++) {
		output[i] = new int[ei + 1];
		fill_n(output[i], ei + 1, 2);
	}
	
	int row = ei;
	int col = ei + 1;
	
	for (int j = 1; j < col; j++) {
		output[j - 1][j] = 0;
	}
	
	int i = 0;
	int j = 2;
	int q = 2;

	while (q < col) {
		while (j < col) {
			int ans = INT_MAX;
			for (int k = i + 1; k <= j - 1; k++) {
				int temp = output[i][k] + output[k][j] + (arr[i] * arr[k] * arr[j]);
				ans = min(ans, temp);
			}
			output[i][j] = ans;
			i++; j++;
		}
		q++;
		i = 0;
		j = q;
	}
	
	int result = output[0][ei];
	for (int i = 0; i < ei; i++) {
		delete output[i];
	}
	delete [] output;
	return result;
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
    }

    cout << matrixChainMultiplication(arr, n) << endl;
	cout << matrixChainMultiplication_mem(arr, n) << endl;
	cout << matrixChainMultiplication_DP(arr, n) << endl;

    delete[] arr;
}
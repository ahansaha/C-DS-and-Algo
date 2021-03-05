#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

//DP
//T(N) = O(N ^ 2)
int findMaxSquareWithAllZeros (int ** arr, int row, int col) {
	int ** output = new int * [row];
	for (int i = 0; i < row; i++) {
		output[i] = new int[col];
	}

	int maximum = 0;
	for (int i = 0; i < row; i++) {
		if (arr[i][0] == 1) {
			output[i][0] = 0;
		}
		else {
			output[i][0] = 1;
			maximum = 1;
		}
	}

	for (int j = 0; j < col; j++) {
		if (arr[0][j] == 1) {
			output[0][j] = 0;
		}
		else {
			output[0][j] = 1;
			maximum = 1;
		}
	}
	
	for (int i = 1; i < row; i++) {
		for (int j = 1; j < col; j++) {
			if (arr[i][j] == 0) {
				output[i][j] = min(min(output[i][j - 1], output[i - 1][j]), output[i - 1][j - 1]) + 1;
			}
			else {
				output[i][j] = 0;
			}
			if (output[i][j] > maximum) {
				maximum = output[i][j];
			}
		}
	}

	return maximum;
}

int main() {
    int ** arr, n, m, i, j;
    cin >> n >> m;
    arr = new int *[n];
    
    for (i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << findMaxSquareWithAllZeros(arr, n, m) << endl;

    delete[] arr;

    return 0;
}


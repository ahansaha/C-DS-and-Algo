#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


//BRUTE FORCE
int minCostPath (int ** input, const int &a, const int &b, int m = 0, int n = 0) {
    
    if (m == a - 1 && n == b - 1)
        return input[a - 1][b - 1];
    
    int right = INT_MAX, diagonal = INT_MAX, down = INT_MAX;
    
    if (n == b - 1)
        down = minCostPath (input, a, b, m + 1, n);
    
    else if (m == a - 1)
        right = minCostPath (input, a, b, m, n + 1);
        
    else {
        right = minCostPath (input, a, b, m, n + 1);
        diagonal = minCostPath (input, a, b, m + 1, n + 1);
        down = minCostPath (input, a, b, m + 1, n);
    }
    
    return min ({right, diagonal, down}) + input[m][n];
}

//CODING NINJAS BRUTE FORCE
int minCostPath_CodingNinjas (int ** input, const int &a, const int &b, int m = 0, int n = 0) {
    
    if (m == a - 1 && n == b - 1)
        return input[a - 1][b - 1];
    
    if (m > a - 1 || n > b - 1)
        return INT_MAX;
    
    int right = minCostPath (input, a, b, m, n + 1);
    int diagonal = minCostPath (input, a, b, m + 1, n + 1);
    int down = minCostPath (input, a, b, m + 1, n);
    
    return min ({right, diagonal, down}) + input[m][n];
}

//MEMOIZATION
int minCostPath_Memoization (int ** input, int ** arr, const int &a, const int &b, int m = 0, int n = 0) {
    
    if (m == a - 1 && n == b - 1)
        return input[a - 1][b - 1];
    
    if (m > a - 1 || n > b - 1)
        return INT_MAX;
    
    if (arr[m][n] != INT_MIN)
        return arr[m][n];
    
    int right = minCostPath_Memoization (input, arr, a, b, m, n + 1);
    int diagonal = minCostPath_Memoization (input, arr, a, b, m + 1, n + 1);
    int down = minCostPath_Memoization (input, arr, a, b, m + 1, n);
    
    arr[m][n] = min ({right, diagonal, down}) + input[m][n];
    return arr[m][n];
}

int minCostPath_Memoization (int ** input, int m, int n) {
    int ** arr = new int * [m];
    for (int i = 0; i < m; i++) {
        arr[i] = new int[n];	
        for (int j = 0; j < n; j++) {
            arr[i][j] = INT_MIN;
        }
    }
    int result = minCostPath_Memoization(input, arr, m, n);
    for (int i = 0; i < m; i++) {
        delete [] arr[i];
    }
    delete [] arr;
    return result;
}

//DP
int minCostPath_DP (int ** input, int m, int n) {
    int ** arr = new int * [m];
    for (int i = 0; i < m; i++) {
        arr[i] = new int[n];	
        for (int j = 0; j < n; j++) {
            arr[i][j] = INT_MIN;
        }
    }
	
	for (int i = m - 1; i >= 0; i--) {
		for (int j = n - 1;j >= 0; j--) {
			
			if (i == m - 1 && j == n - 1) {
				arr[i][j] = input[i][j];
				continue;
			}
			
			int right = INT_MAX, diagonal = INT_MAX, down = INT_MAX;
			
			if (j == n - 1) 
				down = arr[i + 1][j];
			
			else if (i == m - 1) 
				right = arr[i][j + 1];
				
			else {
				right = arr[i][j + 1];
				diagonal = arr[i + 1][j + 1];
				down = arr[i + 1][j];
			}
			
			arr[i][j] = min ({right, diagonal, down}) + input[i][j];
		}
	}	
	
    int result = arr[0][0];
    for (int i = 0; i < m; i++) {
        delete [] arr[i];
    }
    delete [] arr;
    return result;
}

int main () {
    int **arr, n, m;
    cin >> n >> m;
    arr = new int *[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
//    cout << minCostPath(arr, n, m) << endl;
//    cout << minCostPath_CodingNinjas(arr, n, m) << endl;
//    cout << minCostPath_Memoization(arr, n, m) << endl;
		cout << minCostPath_DP(arr, n, m) << endl;
}

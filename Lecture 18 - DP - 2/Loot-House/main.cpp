#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

//BRUTE FORCE
 int maxMoneyLooted (int *arr, int n) {
     if (n <= 0)
         return 0;
    
     int a = arr[0] + maxMoneyLooted(arr + 2, n - 2);
     int b = maxMoneyLooted(arr + 1, n - 1);
     return max(a, b);
 }

//MEMOIZATION
 int maxMoneyLooted_mem (int *arr, int n, int * output) {
     if (n <= 0)
         return 0;
    
     if (output[n] != -1) return output[n];
    
     int a = arr[0] + maxMoneyLooted_mem(arr + 2, n - 2, output);
     int b = maxMoneyLooted_mem(arr + 1, n - 1, output);
    
     output[n] = max(a, b);
     return output[n];
 }

 int maxMoneyLooted_mem (int *arr, int n) {
     int * output = new int[n + 1];
     fill_n(output, n + 1, -1);
     int result = maxMoneyLooted_mem(arr, n, output);
     delete [] output;
     return result;
 }

//DP
int maxMoneyLooted_DP (int *arr, int n) {
    int * output = new int[n + 1];
    fill_n(output, n + 1, -1);
    
    output[0] = 0;
    output[1] = arr[n - 1];
    
    for (int i = 2; i < n + 1; i++) {
        int a = arr[n - i] + output[i - 2];
        int b = output[i - 1];
        output[i] = max(a, b);
    }
    
    int result = output[n];
    delete [] output;
    return result;
}

int main() {
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << maxMoneyLooted(arr, n) << endl;
	cout << maxMoneyLooted_mem(arr, n) << endl;
	cout << maxMoneyLooted_DP(arr, n) << endl;
	

	delete[] arr;
}
#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;


//BRUTE FORCE
//T(N) = O(2 ^ numDenominations)
//S(N) = O(1)
int countWaysToMakeChange(int denominations[], int numDenominations, int value){
	
	if (numDenominations <= 0) {
		return 0;
	}
	else if (value == 0) {
		return 1;
	}
	else if (value < 0) {
		return 0;
	}

	int a = countWaysToMakeChange(denominations, numDenominations, value - denominations[0]);
	int b = countWaysToMakeChange(denominations + 1, numDenominations - 1, value);
	return a + b;
}

//MEMOIZATION
//T(N) = O(numDenominations * value)
//S(N) = O(numDenominations * value)
int countWaysToMakeChange_mem(int denominations[], int numDenominations, int value, int ** arr){
	
	if (numDenominations <= 0) {
		return 0;
	}
	else if (value == 0) {
		return 1;
	}
	else if (value < 0) {
		return 0;
	}
	
	if (arr[numDenominations][value] != -1) 
		return arr[numDenominations][value];
	
	int a = countWaysToMakeChange_mem(denominations, numDenominations, value - denominations[0], arr);
	int b = countWaysToMakeChange_mem(denominations + 1, numDenominations - 1, value, arr);
	
	arr[numDenominations][value] = a + b;
	return arr[numDenominations][value];
}

int countWaysToMakeChange_mem(int denominations[], int numDenominations, int value){
	int ** arr = new int * [numDenominations + 1];
	for (int i = 0; i < numDenominations + 1; i++) {
		arr[i] = new int[value + 1];
		fill_n(arr[i], value + 1, -1);
	}
	int result = countWaysToMakeChange_mem(denominations, numDenominations, value, arr);
	delete [] arr;
	return result;
}

//DP
//T(N) = O(numDenominations * value)
//S(N) = O(numDenominations * value)
int countWaysToMakeChange_DP (int * denominations, int numDenominations, int value) {
	int ** arr = new int * [numDenominations + 1];
	for (int i = 0; i < numDenominations + 1; i++) {
		arr[i] = new int[value + 1];
	}
	
	for (int j = 0; j < value + 1; j++) {
		arr[0][j] = 0;
	}
	
	for (int i = 1; i < numDenominations + 1; i++) {
		arr[i][0] = 1;
	}
	
	for (int j = 1; j < value + 1; j++) {
		for (int i = 1; i < numDenominations + 1; i++) {
			
			if (j - denominations[numDenominations - i] < 0) {
				arr[i][j] = 0;
			} 
			else
				arr[i][j] = arr[i - 1][j] + arr[i][j - denominations[numDenominations - i]];
		}
	}
	
	int result = arr[numDenominations][value];
	for (int i = 0; i < numDenominations + 1; i++) {
		delete [] arr[i];
	}
	delete [] arr;
	return result;
}

int main()
{

	int numDenominations;
	cin >> numDenominations;
	
	int *denominations = new int[numDenominations];
	
	for (int i = 0; i < numDenominations; i++)
	{
		cin >> denominations[i];
	}

	int value;
	cin >> value;
	cout << endl;
	cout << countWaysToMakeChange(denominations, numDenominations, value) << endl;
	cout << countWaysToMakeChange_mem(denominations, numDenominations, value) << endl;
	cout << countWaysToMakeChange_DP(denominations, numDenominations, value) << endl;

	delete[] denominations;
}
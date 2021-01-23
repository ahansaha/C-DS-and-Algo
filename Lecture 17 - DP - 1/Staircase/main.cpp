#include <iostream>
using namespace std;

//Brute force
long staircase(int n) {
	if (n == 1 || n == 0) return 1;
	else if (n < 0) return 0;
	
	long a = staircase (n - 1);
	long b = staircase (n - 2);
	long c = staircase (n - 3);
	
	return a + b + c;
}

//DP
long staircase_DP (int n) {
	long * arr = new long[n + 1];
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 2;
	
	for (long i = 3; i < n + 1; i++) {
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}
	
	int result = arr[n];
	delete [] arr;
	return result;
}

int main() {
	int n;
	cin >> n;
	cout << staircase(n);
}
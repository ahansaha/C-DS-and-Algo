#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


//BRUTE FORCE. 
int countMinStepsToOne (int n) {
	if (n <= 1) return 0;
	
	int x = countMinStepsToOne(n - 1);
	
	int y = (n % 2 == 0) ? countMinStepsToOne(n / 2) : INT_MAX;
	
	int z = (n % 3 == 0) ? countMinStepsToOne(n / 3) : INT_MAX;
	
	//	cout << min({1,2,3,4,5,6,7,8,9});
	return min({x, y, z}) + 1;
}


//MEMOIZATION
int countMinStepsToOne_Memoization (int n, int * ans) {
	if (n <=1) return 0;
	
	int x = INT_MAX, y = INT_MAX, z = INT_MAX;
	
	x = (ans[n - 1] != -1) ? ans[n - 1] : countMinStepsToOne_Memoization (n - 1, ans);
	ans[n - 1] = x;
	
	if (n % 2 == 0) {
		y = (ans[n / 2] != -1) ? ans[n / 2] : countMinStepsToOne_Memoization (n / 2, ans);
		ans[n / 2] = y;
	}
		
	if (n % 3 == 0) {
		z = (ans[n / 3] != -1) ? ans[n / 3] : countMinStepsToOne_Memoization (n / 3, ans);
		ans[n / 3] = z;
	}
	
	for (int i = 0; i < 100; i++) {
		cout << ans[i] << " ";
	} 
	cout << endl; cout << endl;
	
	return min({x, y, z}) + 1;
}

int countMinStepsToOne_Memoization (int n) {
	int * ans = new int[n + 1];
	fill_n (ans, n + 1, -1); //To fill the array with -1. Internally this function uses loop only but its easier for us to write this way.
	return countMinStepsToOne_Memoization (n, ans);
}

//DP
int countMinStepsToOne_DP (int n) {
	int * arr = new int[n + 1];
	arr[0] = 0;
	arr[1] = 0;
	
	for (int i = 2; i <= n; i++) {
		
		int x = arr[i - 1];
		int y = (i % 2 == 0) ? arr[i / 2] : INT_MAX;
		int z = (i % 3 == 0) ? arr[i / 3] : INT_MAX;
		arr[i] = min({x, y, z}) + 1;
	}
	
	int result = arr[n];
	delete [] arr;
	return result;
}


int main()
{
	int n;
	cin >> n;
	//cout << countMinStepsToOne (n);
	//cout << countMinStepsToOne_Memoization (n);
	cout << countMinStepsToOne_DP (n);
}
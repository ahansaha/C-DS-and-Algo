#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;


//BRUTE FORCE
int knapsack (int *weights, int *values, int n, int maxWeight) {
    if (n <= 0) {
        return 0;
    }
    
    int a = INT_MIN;
    if (maxWeight - weights[0] >= 0)
        a = knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0]) + values[0];
    
    int b = knapsack(weights + 1, values + 1, n - 1, maxWeight);
    
    return max(a, b);
    
}

//MEMOIZATION
int knapsack_mem (int *weights, int *values, int n, int maxWeight, int ** arr) {
    if (n <= 0) {
        return 0;
    }
    
    if (arr[n][maxWeight] != -1) return arr[n][maxWeight];
    
    int a = INT_MIN;
    if (maxWeight - weights[0] >= 0)
        a = values[0] + knapsack_mem(weights + 1, values + 1, n - 1, maxWeight - weights[0], arr);
    
    int b = knapsack_mem(weights + 1, values + 1, n - 1, maxWeight, arr);
    
    arr[n][maxWeight] = max(a, b);
    return arr[n][maxWeight];
}

int knapsack_mem (int *weights, int *values, int n, int maxWeight) {
    int ** arr = new int * [n + 1];
    for (int i = 0; i < n + 1; i++) {
        arr[i] = new int[maxWeight + 1];
        fill_n(arr[i], maxWeight + 1, -1);
    }
    int result = knapsack_mem(weights, values, n, maxWeight, arr);
    for (int i = 0; i < n + 1; i++) {
        delete [] arr[i];
    }
    delete [] arr;
    return result;
}

//DP
int knapsack_DP (int *weights, int *values, int n, int maxWeight) {
    int ** arr = new int * [n + 1];
    for (int i = 0; i < n + 1; i++) {
        arr[i] = new int[maxWeight + 1];
        fill_n(arr[i], maxWeight + 1, -1);
    }
    
    for (int j = 0; j < maxWeight + 1; j++) {
        arr[0][j] = 0;
    }
    
    for (int i = 1; i < n + 1; i++) {
        for (int j = 0; j < maxWeight + 1; j++) {
            
            int a = INT_MIN;
            if (j - weights[n - i] >= 0) {
                a = values[n - i] + arr[i - 1][j - weights[n - i]];
            }
            int b = arr[i - 1][j];
            
            arr[i][j] = max(a, b);
        }
    }
    
    int result = arr[n][maxWeight];
    for (int i = 0; i < n + 1; i++) {
        delete [] arr[i];
    }
    delete [] arr;
    return result;
}


int main()
{
    int n;
    cin >> n;

    int *weights = new int[n];
    int *values = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    int maxWeight;
    cin >> maxWeight;

    cout << knapsack(weights, values, n, maxWeight) << endl;
    cout << knapsack_mem(weights, values, n, maxWeight) << endl;
    cout << knapsack_DP(weights, values, n, maxWeight) << endl;

    delete[] weights;
    delete[] values;
}

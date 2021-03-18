#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

//Check if the graph is connected or not.
void DFS (int ** edges, int n, int sv, bool * visited) {
    visited[sv] = true;
    for (int i = 0; i < n; i++) {
        if (i == sv) {
            continue;
        }
        if (edges[sv][i] == 1 && visited[i] == false) {
            DFS(edges, n, i, visited);
        }
    }
}

bool isConnected (int ** edges, int n) {
    bool * visited = new bool[n];
    fill_n(visited, n, false);
    
    DFS(edges, n, 0, visited);

    bool ans = true;
    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            ans = false;
            break;
        }
    }
    delete [] visited;
    return ans;
}

int main(){
    int n, e;
    cin >> n >> e;

    int ** edges = new int * [n];
    for (int i = 0; i < n; i++) {
        edges[i] = new int[n];
        fill_n(edges[i], n, 0);
    }

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        edges[a][b] = 1;
        edges[b][a] = 1;
    }

    (isConnected(edges, n)) ? cout << "true" << endl : cout << "false" << endl;

    for (int i = 0; i < n; i++) {
        delete [] edges[i];
    }
    delete [] edges;

    return 0;
}


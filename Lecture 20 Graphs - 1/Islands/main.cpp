#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

void DFS (int ** edges, int n, int sv, bool * visited) {
    visited[sv] = true;
    for (int i = 0; i < n; i++) {
        if (i == sv) continue;
        if (edges[sv][i] == 1 && visited[i] == false) {
            DFS(edges, n, i, visited);
        }
    }
}

int islands (int ** edges, int n) {
    bool * visited = new bool[n];
    fill_n(visited, n, false);
    int islandCount = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            islandCount++;
            DFS(edges, n, i, visited);
        }
    }
    delete [] visited;
    return islandCount;
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
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    int islandCount = islands(edges, n);
    cout << islandCount << endl;

    for (int i = 0; i < n; i++) {
        delete [] edges[i];
    }
    delete [] edges;
  
    return 0;
}

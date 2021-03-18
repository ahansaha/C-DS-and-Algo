#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

//Get the path b/w tow given vertices using DFS and store it in a vector.
vector<int> getPathDFS (int ** edges, int n, int v1, int v2, bool * visited, vector<int> path) {
    if (v1 == v2) {
        path.push_back(v1);
        return path;
    }

    visited[v1] = true;
    for (int i = 0; i < n; i++) {
        if (edges[v1][i] == 1 && visited[i] == false) {
            path = getPathDFS(edges, n, i, v2, visited, path);
            if (!path.empty()) {
                path.push_back(v1);
                return path;
            }
        }
    }
    return path;
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

    bool * visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    
    int v1, v2;
    cin >> v1 >> v2;

    vector<int> path;
    path = getPathDFS(edges, n, v1, v2, visited, path);

    for (int i = 0; i < path.size(); i++) {
        cout << path.at(i) << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        delete [] edges[i];
    }
    delete [] edges;
    delete [] visited; 
    
    return 0;
}


#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <climits>
#include <queue>
using namespace std;

//Get the path b/w two given vertices v1 and v2 using BFS traversal.
vector<int> * getPathBFS (int ** mat, int v, int v1, int v2, bool * visited) {
    unordered_map<int, int> vertex_map;
    queue<int> q;
    q.push(v1);
    bool done = false;
    while (!q.empty() && done == false) {
        int firstElement = q.front();
        q.pop();
        visited[firstElement] = true;

        for (int i = 0; i < v; i++) {
            if (i == firstElement) continue;
            if (mat[firstElement][i] == 1 && visited[i] == false) {
                q.push(i);
                visited[i] = true;
                vertex_map[i] = firstElement;
                if (i == v2) {
                    done = true;
                    break;
                }
            }
        }
    }
    
    vector<int> * path = new vector<int>;
    if (done == false) {
        return path;
    } 
    else {
        path -> push_back(v2);
        while (v2 != v1) {
            v2 = vertex_map.at(v2);
            path -> push_back(v2);
        }
        return path;
    }
}

int main(){
    int v, e;
    cin >> v >> e;
    int ** mat = new int * [v];
    for (int i = 0; i < v; i++) {
        mat[i] = new int[v];
        fill_n(mat[i], v, 0);
    }

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        mat[a][b] = 1;
        mat[b][a] = 1;
    }

    bool * visited = new bool[v];
    fill_n(visited, v, false);

    int v1, v2;
    cin >> v1 >> v2;

    vector<int> * path = getPathBFS(mat, v, v1, v2, visited);
    
    for (int i = 0; i < path -> size(); i++) {
        cout << path -> at(i) << " ";
    }
    cout << endl;

    for (int i = 0; i < v;i ++) {
        delete [] mat[i];
    }
    delete [] mat;
    delete [] visited;
    delete path;

    return 0;
}


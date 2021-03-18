#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <queue>
using namespace std;

//Check if two vertices have a path b/w them (BFS traversal used). Return true if path exits else false.
bool HasPathBFS (int ** mat, int v, int sv, int end, bool * visited) {
    bool pathExists = false;

    queue<int> q;
    q.push(sv);
    while(!q.empty()) {
        int firstElement = q.front();
        
        if (firstElement == end) {
            pathExists = true;
            return pathExists;
        }

        q.pop();
        visited[firstElement] = true;

        for (int i = 0; i < v; i++) {
            if (i == firstElement) continue;
            if (mat[firstElement][i] == 1 && visited[i] == false) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return pathExists;
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

    int start, end;
    cin >> start >> end;

    bool * visited = new bool[v];
    fill_n(visited, v, false);

    HasPathBFS(mat, v, start, end, visited) ? cout << "true" << endl : cout << "false" << endl;

    for (int i = 0; i < v;i ++) {
        delete [] mat[i];
    }
    delete [] mat;
    delete [] visited;

    return 0;
}


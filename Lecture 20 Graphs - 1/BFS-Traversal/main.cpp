#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <queue>
using namespace std;

//BFS traversal using queue, for connected graphs.
void printBFS (int ** mat, int v, int sv, bool * visited) {
    queue<int> q;
    q.push(sv);

    while(!q.empty()) {
        int firstElement = q.front();
        q.pop();
        cout << firstElement << " ";
        visited[firstElement] = true;

        for (int i = 0; i < v; i++) {
            if (i == firstElement) continue;
            if (mat[firstElement][i] == 1 && visited[i] == false) {
                q.push(i);
                visited[i] = true;
            }
        }
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

    printBFS(mat, v, 0, visited);

    for (int i = 0; i < v;i ++) {
        delete [] mat[i];
    }
    delete [] mat;
    delete [] visited;

    return 0;
}


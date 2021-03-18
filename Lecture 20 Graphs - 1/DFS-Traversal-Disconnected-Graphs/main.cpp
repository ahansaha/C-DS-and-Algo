#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

//DFS Traversal for connected graphs.
void printDFS (int ** edges, int n, int sv, bool * visited) {
    //sv represents starting vertex.
    cout << sv << " ";
    visited[sv] = true;

    for (int i = 0; i < n; i++) {
        if (i == sv) continue;
        if (edges[sv][i] == 1 && visited[i] == false) {
            printDFS(edges, n, i, visited);
        }
    }
}

void printDFS (int ** edges, int n) {
    bool * visited = new bool[n];
    fill_n(visited, n, false);
    //Assume that the 0th index is the starting vertex sv.
    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            printDFS(edges, n, i, visited);
        }
    }
    delete [] visited;
}

int main(){
    //n = number vertices from 0 to n - 1.
    //e = number of edges
    int n, e;
    cin >> n >> e;

    //Declare an adjacency matrix.
    int ** edges = new int * [n];
    for (int i = 0; i < n; i++) {
        edges[i] = new int[n];
        fill_n(edges[i], n, 0);
    }
    
    //Fill the adjacency matrix using user input.
    for (int i = 0; i < e; i++) {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    //Print the vertices in DFS order.
    //Assume that 0 is the starting vertex.
    printDFS(edges, n);

    for (int i = 0; i < n; i++) {
        delete [] edges[i];
    }
    delete [] edges;
  
    return 0;
}

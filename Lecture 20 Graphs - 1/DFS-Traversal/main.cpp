#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

//DFS Traversal
void print (int ** edges, int n, int sv, bool * visited) {
    //sv represents starting vertex.
    cout << sv << " ";
    visited[sv] = true;

    for (int i = 0; i < n; i++) {
        if (i == sv) continue;
        if (edges[sv][i] == 1 && visited[i] == false) {
            print(edges, n, i, visited);
        }
    }
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

    //Make a visited array to keep track of vertices already printed.
    bool * visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    //Print the vertices in DFS order.
    print(edges, n, 0, visited);

    for (int i = 0; i < n; i++) {
        delete [] edges[i];
    }
    delete [] edges;
    delete [] visited; 
    
    return 0;
}


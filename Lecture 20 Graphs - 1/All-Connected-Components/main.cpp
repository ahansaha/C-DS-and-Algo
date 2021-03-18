#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

//Print each connected component of the graph in a new line.


//This DFS function will make the vector of the current component and return it.
vector<int> * DFS (bool ** edges, int n, int sv, bool * visited, vector<int> * currentComponent) {
    currentComponent -> push_back(sv);
    visited[sv] = true;

    for (int i = 0; i < n; i++) {
        if (i == sv) continue;
        if (edges[sv][i] == true && visited[i] == false) {
            currentComponent = DFS(edges, n, i, visited, currentComponent);
        }
    }
    return currentComponent;
}


//This function will get one single component from th DFS function and push it in the outer vector.
vector<vector<int> *> * allConnectedComponents (bool ** edges, int n) {
    bool * visited = new bool[n];
    fill_n(visited, n, false);

    vector<vector<int> *> * components = new vector<vector<int> *>();
    
    //Traverse the visited array and call DFS wherever is visited is false. Push the output if each DFS in the outermost vector.
    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            vector<int> * currentComponent = new vector<int>();
            currentComponent = DFS(edges, n, i, visited, currentComponent);
            sort(currentComponent -> begin(), currentComponent -> end());
            components -> push_back(currentComponent);
        }
    }
    delete [] visited;
    return components;
}

int main(){
    int n, e;
    cin >> n >> e;

    bool ** edges = new bool * [n];
    for (int i = 0; i < n; i++) {
        edges[i] = new bool[n];
        fill_n(edges[i], n, false);
    }

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        edges[a][b] = true;
        edges[b][a] = true;
    }

    vector<vector<int> *> * components = allConnectedComponents(edges, n);

    for (int i = 0; i < components -> size(); i++) {
        for (int j = 0; j < components -> at(i) -> size(); j++) {
            cout << components -> at(i) -> at(j) << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        delete [] edges[i];
    }
    delete [] edges;
   
    for (int i = 0; i < components -> size(); i++) {
        delete components -> at(i);
    }
    delete components;
    
    return 0;
}


#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

class Triplet {
    public:
        int parent, weight;
        bool visited;

        Triplet() {
            parent = 0;
            weight = INT_MAX;
            visited = false;
        }
};

//This function calculates the next vertex to pe picked which has the minimum wieight among all the unvisited vertices.
int getMinVertexWeight (int v, Triplet * vertexArray) {
    int minVertex = -1, minVertexWeight = INT_MAX;
    for (int i = 0; i < v; i++) {
        if (vertexArray[i].visited) {
            continue;
        }
        if (vertexArray[i].weight < minVertexWeight) {
            minVertex = i;
            minVertexWeight = vertexArray[i].weight;
        }
    }
    return minVertex;
}

//Prim's algo
//T(N) = O(V ^ 2)
void Prims (int v, int e, int ** adjmat, Triplet * vertexArray) {
    //Mark the sources vertices parent as -1 and weight as 0 to se the initial conditions.
    vertexArray[0].parent = -1;
    vertexArray[0].weight = 0;
    
    for (int i = 0; i < v; i++) {
        int minVertex = getMinVertexWeight(v, vertexArray);
        vertexArray[minVertex].visited = true;
        for (int j = 0; j < v; j++) {
            if (adjmat[minVertex][j] > 0 && vertexArray[j].visited == false) {
                if (vertexArray[j].weight > adjmat[minVertex][j]) {
                    vertexArray[j].weight = adjmat[minVertex][j];
                    vertexArray[j].parent = minVertex;
                }
            }
        }
    }
}
    
int main (){
    int v, e;
    cin >> v >> e;

    int ** adjmat = new int * [v];
    for (int i = 0; i < v; i++) {
        adjmat[i] = new int[v];
        fill_n(adjmat[i], v, 0);
    }

    for (int i = 0; i < e; i++) {
        int v1, v2, edge;
        cin >> v1 >> v2 >> edge;
        adjmat[v1][v2] = edge;
        adjmat[v2][v1] = edge;
    }

    //Array that stores a vertice's parent, weight and if it's visited or not.
    Triplet * vertexArray = new Triplet[v];

    Prims(v, e, adjmat, vertexArray);

    for (int i = 1; i < v; i++) {
        //Print the smaller of the two vertices first.
        if (vertexArray[i].parent < i) {
            cout << vertexArray[i].parent << " " <<  i << " " << adjmat[vertexArray[i].parent][i] << endl;
        } else {
            cout << i << " " <<  vertexArray[i].parent << " " << adjmat[vertexArray[i].parent][i] << endl;
        }
    }

    for (int i = 0; i < v; i++) {
        delete [] adjmat[i];
    }
    delete [] adjmat;
    delete [] vertexArray;

    return 0;
}

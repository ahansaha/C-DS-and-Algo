#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

class Pair {
    public:
        int distance;
        bool visited;

        Pair () {
            distance = INT_MAX;
            visited = false;
        }
};

int getMinVertexDistance (int v, Pair * vertexArray) {
    int minVertex = -1, minVertexDistance = INT_MAX;
    for (int i = 0; i < v; i++) {
        if (vertexArray[i].visited) {
            continue;
        }
        if ((vertexArray[i].distance < minVertexDistance)) {
            minVertex = i;
            minVertexDistance = vertexArray[i].distance;
        }
    }
    return minVertex;
}

//Dijkstras-algo
//T(N) =(N ^ 2)
void Prims (int v, int e, int ** adjmat, Pair * vertexArray) {
    vertexArray[0].distance = 0;
    
    for (int i = 0; i < v; i++) {
        int minVertex = getMinVertexDistance(v, vertexArray);
        vertexArray[minVertex].visited = true;
        for (int j = 0; j < v; j++) {
            if (adjmat[minVertex][j] > 0 && vertexArray[j].visited == false) {
                if (vertexArray[j].distance > (vertexArray[minVertex].distance + adjmat[minVertex][j])) {
                    vertexArray[j].distance = vertexArray[minVertex].distance + adjmat[minVertex][j];
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

    Pair * vertexArray = new Pair[v];

    Prims(v, e, adjmat, vertexArray);

    for (int i = 0; i < v; i++) {
        cout << i << " " << vertexArray[i].distance << endl;
    }
  

    for (int i = 0; i < v; i++) {
        delete [] adjmat[i];
    }
    delete [] adjmat;
    delete [] vertexArray;

    return 0;
}

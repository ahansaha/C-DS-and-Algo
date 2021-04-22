#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

class Triplet {
    public:
        int src, dest, edge;
};

//Comparator function, to sort the input array according to the edge weights in ascending order. This function will be passed as a paramter to the in built sort function.
bool comparator (Triplet a, Triplet b) {
    return a.edge < b.edge;
}

//T(N) = O(e log e + ev), where 'e' represents the edges and 'v' the vertices.
//Kruskal's algo.
void Kruskal (int v, int e, Triplet * input, Triplet * output) {
    sort(input, input + e, comparator);
    
    //Maintain the counter to go till max 'v - 1' edges, and a parent array for the union find algo.
    int counter = 0;
    int * parent = new int[v];

    //Initialize the parent array with every vertex being its own parent, in the beginning.
    for (int i = 0; i < v; i++) {
        parent[i] = i;
    }

    //Pick up edges in ascending order from the input array to be filled in the output array.
    for (int i = 0; i < e; i++) {
        if (counter < v) {    // Fill the output array only till 'v - 1' edges.

            //Union find to find the top most parent of the source vertex. 
            int srcTemp = input[i].src;
            int srcParent = -1;
            while (srcTemp != parent[srcTemp]) {
                srcTemp = parent[srcTemp];
            }
            srcParent = srcTemp;

            //Union find to find the top most parent of the destination vertex.
            int destTemp = input[i].dest;
            int destParent = -1;
            while (destTemp != parent[destTemp]) {
                destTemp = parent[destTemp];
            }
            destParent = destTemp;

            //Add the edge to the output MST array only if the parents do not match.
            if (srcParent != destParent) {
                output[counter].src = input[i].src;
                output[counter].dest = input[i].dest;
                output[counter].edge = input[i].edge;
                counter++;
                //Make P1 parent of P2 or P2 parent of P1.
                parent[srcParent] = destParent;
            }
        }
    }
    delete [] parent;
}

int main (){
    // v = number of vertices, e = number of edges.
    int v, e;
    cin >> v >> e;
    
    // Make the input array for inputting the graph of size 'e' and the ouput array that represents the MST of size 'v-1'
    Triplet * input = new Triplet[e];
    Triplet * output = new Triplet[v - 1];

    //Take the input of each indices source, destination, and edge in the input array. Each index represents an edge of the graph in the input array.
    for (int i = 0; i < e; i++) {
        int src, dest, edge;
        cin >> src >> dest >> edge;
        
        input[i].src = src;
        input[i].dest = dest;
        input[i].edge = edge;
    }

    //Kruskal's algo to fill the output MST array.
    Kruskal(v, e, input, output);

    //Print the output MST array, but print the smaller of the source and destination vertices first.
    for (int i = 0; i < v - 1; i++) {
        if (output[i].src < output[i].dest) {
           cout << output[i].src << " " << output[i].dest << " " << output[i].edge << endl; 
        }
        else {
           cout << output[i].dest << " " << output[i].src << " " << output[i].edge << endl;
        }
    }
        
    delete [] input;
    delete [] output;
    return 0;
}

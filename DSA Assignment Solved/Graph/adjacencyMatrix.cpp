#include <bits/stdc++.h>
using namespace std;

int main(){
    int vertex, edge;
    cout << "Enter the number of Vertex: ";
    cin >> vertex;
    cout << "Enter the number of Edges: ";
    cin >> edge;

    int adjMatrix[vertex][vertex];

    //Initialize each 0
    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            adjMatrix[i][j] = 0;
        }
    }

    cout << "Enter edges:";
    for(int i = 0; i < edge; i++){
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    cout << "Adjacency matrix : \n";
    for(int i = 0; i < vertex; i++) {
      for(int j = 0; j < vertex; j++)
        cout << adjMatrix[i][j] << " ";
      cout << endl;
    }
    return 0;
}
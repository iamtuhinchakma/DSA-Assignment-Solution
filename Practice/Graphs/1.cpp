//Adjacency list representation of graph

#include <bits/stdc++.h>
using namespace std;
int main(){
    int vertex, edge;
    cout << "Enter the number of Vertext: ";
    cin >> vertex;
    cout << "\nEnter number of edges: ";
    cin >> edge;



    //Initialize matrix at first
    int matrix[vertex][vertex];
    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            matrix[i][j] = 0;
        }
    }

    //Read the edges
    cout << "Enter edges: \n";
    for(int i = 0; i < edge; i++){
        int u, v;
        cin >> u >> v; // edge, 0 1, 0 2, 1 2, 2, 3 
        if(u > vertex || v > vertex){
            cout << "Invalid edge\n";
            i--;
        } else {
            matrix[u][v] = 1;
            //matrix[v][u] = 1; // for undirected graph
        }
    }

    //Print the adjacent matrix
    cout << "The adjacent matrix is: \n";
    for(int i = 0; i < vertex; i++)
    {
        for(int j = 0; j < vertex; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
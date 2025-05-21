#include <iostream>
using namespace std;
const int MAX_SIZE = 100;

void warshalAlgorithm(int m[MAX_SIZE][MAX_SIZE], int n){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                m[i][j] = m[i][j] || (m[i][k] && m[k][j]);
            }
        }
    }

    cout << "\nPath matrix is: \n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << m[i][j] << ' ';
        }
        cout << endl;
    }
}

int main(){
    int nodes;
    cout << "Enter the number of nodes: ";
    cin >> nodes;
    int adjMatrix[MAX_SIZE][MAX_SIZE];

    cout << "Enter the matrix: \n";
    for(int i = 0; i < nodes; i++){
        for(int j = 0; j < nodes; j++){
            cin >> adjMatrix[i][j];
        }
    }

    cout << "Original adjacency matrix is: \n";
    for(int i = 0; i < nodes; i++){
        for(int j = 0; j < nodes; j++){
            cout << adjMatrix[i][j] << ' ';
        }
        cout << endl;
    }

    warshalAlgorithm(adjMatrix, nodes);

    return 0;
}

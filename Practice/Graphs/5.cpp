#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
int main(){
    int vertex;
    cout << "Enter the number of Vertex: ";
    cin >> vertex;

    int matrix[vertex][vertex], shortestPathMatrix[vertex][vertex];

    cout << "Enter the matrix: \n";
    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == 0) shortestPathMatrix[i][j] = INF;
            else shortestPathMatrix[i][j] = matrix[i][j];
        }
    }

    cout << "\nOrginal Matrix : \n";

    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\nRedefine Matrix : \n";

    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            cout << shortestPathMatrix[i][j] << " ";
        }
        cout << endl;
    }


    for(int k = 0; k < vertex; k++){
        for(int i = 0; i < vertex; i++){
            for(int j = 0; j < vertex; j++){
                shortestPathMatrix[i][j] = min(shortestPathMatrix[i][j], shortestPathMatrix[i][k] + shortestPathMatrix[k][j]);
            }
        }
    }

    cout << "\n Shortest Path Matrix : \n";

    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            cout << shortestPathMatrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
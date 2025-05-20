#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

int main(){
    int vertex;
    cout << "Enter the number of vertices: ";
    cin >> vertex;
    int matrix[vertex][vertex], shortestPMatrix[vertex][vertex];
    cout << "Enter Matrix: \n";
    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == 0) shortestPMatrix[i][j] = INF;
            else shortestPMatrix[i][j] = matrix[i][j];
        }
    }

    for(int k = 0; k < vertex; k++){
        cout << endl;
        for(int i = 0; i < vertex; i++){
            for(int j = 0; j < vertex; j++){
                cout << shortestPMatrix[i][j] << " ";
            }
            cout << endl;
        }  
              
        for(int i = 0; i < vertex; i++){
            for(int j = 0; j < vertex; j++){
                shortestPMatrix[i][j] = min(shortestPMatrix[i][j], shortestPMatrix[i][k] + shortestPMatrix[k][j]);
            }
        }
    }
    // for(int k = 0; k < vertex; k++){
    //     for(int i = 0; i < vertex; i++){
    //         for(int j = 0; j < vertex; j++){
    //             shortestPMatrix[i][j] = min(shortestPMatrix[i][j], shortestPMatrix[i][k] + shortestPMatrix[k][j]);
    //         }
    //     }
    // }


    cout << "\nShortest Path matrix : \n";
    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            cout << shortestPMatrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
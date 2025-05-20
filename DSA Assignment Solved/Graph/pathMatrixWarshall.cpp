#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
int main(){
    int nodes, A[MAX][MAX];
    cout << "Enter the number of nodes: ";
    cin >> nodes;

    cout << "Enter Matrix: \n";
    for(int i = 0; i < nodes; i++){
        for(int j = 0; j < nodes; j++){
            cin >> A[i][j];
        }
    }

    //Calculation
    for(int k = 0; k < nodes; k++){
        for(int i = 0; i < nodes; i++){
            for(int j = 0; j < nodes; j++){
                A[i][j] = A[i][j] or (A[i][k] and A[k][j]);
            }
        }
    }


    cout << "\nPath Matrix: \n";
    for(int i = 0; i < nodes; i++){
        for(int j = 0; j < nodes; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
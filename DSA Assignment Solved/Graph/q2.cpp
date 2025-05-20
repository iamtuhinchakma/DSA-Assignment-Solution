#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
void multiply(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int m){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            result[i][j] = 0;
            for(int k = 0; k < m; k++){
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main(){
    int m, A[MAX][MAX],temp[MAX][MAX], power[MAX][MAX], Br[MAX][MAX] = {0}, path[MAX][MAX];

    cin >> m;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            cin >> A[i][j];
            power[i][j] = A[i][j];
        }
    }

    for(int i = 1; i <= m; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < m; k++){
                Br[j][k] += power[j][k];
            }
        }
        multiply(power, A, temp, m);

    }


    return 0;
}
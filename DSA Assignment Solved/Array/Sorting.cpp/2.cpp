/* Bubble sort on String*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif



    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << "Original Data: \n";
    for(int i = 0; i < n; i++) cout << arr[i] << ' ';
    cout << endl;

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Data after sorted: \n";
    for(int i = 0; i < n; i++) cout << arr[i] << ' ';
    cout << endl;

    return 0;
}
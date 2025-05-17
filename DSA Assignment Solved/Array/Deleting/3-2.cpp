/* Deleting karim from the sorted array*/
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

    cout << "Original sorted array: \n";
    for(int i = 0; i < n; i++) cout << arr[i] << ' ';
    cout << endl;

    int value;
    cin >> value;

    int pos = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] == value){
            pos = i;
            break;
        }
    }
    // cout << pos << endl;

    if(pos == -1){
        cout << value << " is not found\n";
    } else{
        for(int i = pos; i < n; i++){
            arr[i] = arr[i + 1];
        }
        n--;

        cout << "Array after deletion: \n";
        for(int i = 0; i < n; i++) cout << arr[i] << ' ';
        cout << endl;
    }
    return 0;
}
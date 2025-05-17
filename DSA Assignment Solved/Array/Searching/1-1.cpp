/* Linear Search*/
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
    bool found = false;
    for(int i = 0; i < n; i++){
        if(arr[i] == value){
            found = true;
        }
    }
    if(!found) cout << "There is no such value\n";
    else cout << "Found\n";
    return 0;
}
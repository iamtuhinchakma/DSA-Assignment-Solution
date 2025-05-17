/* This program insert into a sorted array*/
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
    for(int i = 0; i < n; i++) cout << arr[i] << ' ';
    cout << endl;

    int pos = 0, val;
    cin >> val;
    for(int i = 0; i < n; i++){
        if(arr[i] > val){
            pos = i;
            break;
        }
    }
    cout << pos << endl;

    n++;
    for(int i = n - 1; i >= pos; i--){
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;

    for(int i = 0; i < n; i++) cout << arr[i] << ' ';
    cout << endl;
    return 0;
}
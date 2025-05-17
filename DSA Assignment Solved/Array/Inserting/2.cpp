/* This program insert at specific position*/
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

    //inserting at specific position
    n++;
    int pos, val;
    cin >> pos >> val;

    for(int i = n - 1; i >= pos - 1; i--){
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = val;

    for(int i = 0; i < n; i++) cout << arr[i] << ' ';
    cout << endl;


    return 0;
}
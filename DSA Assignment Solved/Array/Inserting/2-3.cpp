/* This program insert string into a string array*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    const int MAX_SIZE = 100;
    // string arr[MAX_SIZE];
    // int n, pos;
    // string value;

    int n;
    cin >> n;
    string arr[MAX_SIZE];
    for(int i = 0; i < n; i++)  cin >> arr[i];

    // cout << "Array elements are: ";
    for(int i = 0; i < n; i++) cout << arr[i] << ' ';
    cout << endl;

    string value;
    cin >> value;

    //Find correct position to insert
    int pos = 0;
    while(pos < n && arr[pos] < value)  pos++;

    for(int i = n; i > pos; i--){
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    n++;

    // cout << "Array elements after insertion: ";
    for(int i = 0; i < n; i++) cout << arr[i] << ' ';
    cout << endl;
    return 0;
}
/* Deleting karim from the sorted array*/
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

    cout << "Orginial Sorted arry: \n";
    for(int i = 0; i < n; i++) cout << arr[i] << ' ';
    cout << endl;

    string toDelete = "Karim";

    //Find correct position to insert
    int pos = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] == toDelete){
            pos = i;
            break;
        }
    }

    if(pos == -1){
        cout << "\"" << toDelete << "\" not found in the array.\n";
    } else {
        for(int i = pos; i < n - 1; i++){
            arr[i] = arr[i + 1];
        }
        n--;

        // cout << "Array elements after deletion: ";
        for(int i = 0; i < n; i++) cout << arr[i] << ' ';
        cout << endl;
    }
    return 0;
}
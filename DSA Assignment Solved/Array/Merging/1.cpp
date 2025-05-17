/* Bubble sort on String*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    const int MAX_SIZE = 100;
    string arr[MAX_SIZE];

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << "Original Data: \n";
    for(int i = 0; i < n; i++) cout << arr[i] << ' ';
    cout << endl;

    
    cout << "Data after sorted: \n";
    for(int i = 0; i < n; i++) cout << arr[i] << ' ';
    cout << endl;

    return 0;
}
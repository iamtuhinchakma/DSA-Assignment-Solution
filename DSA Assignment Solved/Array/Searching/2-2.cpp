/* Linear Search on string*/
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

    string to_find;
    cin >> to_find;

    bool found = false;
    for(int i = 0; i < n; i++){
        if(arr[i] == to_find){
            found = true;
            break;
        }
    }
    if(!found) cout << "Not Found\n";
    else cout << "Found\n";
    return 0;
}
/* Binary Search on string*/
#include <bits/stdc++.h>
using namespace std;
int binary_search(string arr[], int low, int high, string value){
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == value) return mid;
        if(arr[mid] < value) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
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
    int index = binary_search(arr, 0, n -1, to_find);
    if(index == -1){
        cout << "Not found\n";
    } else {
        cout << to_find << " Found at " << index << endl;
    }
    return 0;
}
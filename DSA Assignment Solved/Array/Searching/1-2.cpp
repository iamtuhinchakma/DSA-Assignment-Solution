/* Binary Search on integer array*/
#include <bits/stdc++.h>
using namespace std;
int binary_search(int arr[], int value, int low, int high){
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(value == arr[mid]) return mid;
        if(value > arr[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
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
    //Calling binary search
    int result = binary_search(arr, value, 0, n - 1);
    if(result == -1){
        cout << "Not found\n";
    } else {
        cout << "Element is found at index " << result << endl;
    }
    return 0;
}
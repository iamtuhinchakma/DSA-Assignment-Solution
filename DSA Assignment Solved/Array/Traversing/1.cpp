//Array Traversing
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

    int max = INT_MIN;
    int min = INT_MAX;
    int avergae = 0, sum = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > max){
            max =arr[i];
        }
        if(arr[i] < min){
            min = arr[i];
        }
        sum += arr[i];
    }
    cout << "Maximum Value: " << max << endl;
    cout << "Minimum Value: " << min << endl;
    avergae = sum / n;
    cout << "Average Value is: " << avergae << endl;
    cout << "Sine Value is: " << sin(sum) << endl;

    return 0;
}
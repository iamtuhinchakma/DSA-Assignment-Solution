    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n - 1; j++){
            if(arr[i] > arr[j]){
                string temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout << "Data after sorted: \n";
    for(int i = 0; i < n; i++) cout << arr[i] << ' ';
    cout << endl;
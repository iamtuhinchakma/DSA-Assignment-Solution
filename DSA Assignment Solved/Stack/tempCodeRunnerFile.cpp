void pop(){
    if(top == -1){
        cout << "Stack Underflow\n";
    } else {
        cout << "Popped: " << stck[top] << endl;
        top--;
    }
}
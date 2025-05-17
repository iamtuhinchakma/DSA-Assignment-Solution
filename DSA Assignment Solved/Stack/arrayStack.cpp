// Stack impelementation using Linear Array
#include <bits/stdc++.h>
using namespace std;
const int STACK_SIZE = 5; // #define N 5
int stck[STACK_SIZE];
int top = -1;

//push operation();

void push(int val){
    if(top == STACK_SIZE - 1){
        cout << "Stack Overflow\n";
    } else {
        top++;
        stck[top] = val;
        cout << val << " has been pushed to stack\n";
    }
}

int peek(){
    if(top == -1){
        cout << "Underflow\n";
        return -1;
    } else {
        return stck[top];
    }
}

void pop(){
    if(top == -1){
        cout << "Stack Underflow\n";
    } else {
        cout << "Popped: " << stck[top] << endl;
        top--;
    }
}

void display(){
    for(int i = top; i >= 0; i--){
        cout << stck[top] << ' ';
    }
    cout << endl;
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    peek();
    pop();
    push(10);
    push(20);
    push(30);
    display();

    cout << "Top element is: " << peek() << endl;

    pop();
    display();

    pop();
    pop();
    pop();  // This should trigger underflow
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
int stck[MAX];

int top =-1;

void push(int val){
    if(top == MAX - 1){
        cout << "Stack overlfow\n";
        return;
    }
    top++;
    stck[top] = val;
    cout << val << " has been pushed\n";
}

void pop(){
    if(top == -1){
        cout << "Stack underflow\n";
        return;
    }
    cout << stck[top] << " has popped\n";
    top--;
}
int peek(){
    if(top == -1) return -1;
    else return stck[top];
}
void display(){
    for(int i = top; i >= 0; i--) cout << stck[i] << ' ';
}
int main(){

    push(10);
    push(20);
    push(20);
    push(40);
    display();
    cout << "Top value is: " << peek() << endl;
    pop();
    display();
    return 0;
}
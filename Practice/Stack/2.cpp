#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
int stck[MAX];

int top =-1;
//5, 6, 2, +, *, 12, 4, /, -
void push(int val){
    if(top == MAX - 1){
        cout << "Stack overlfow\n";
        return;
    }
    top++;
    stck[top] = val;
    //cout << val << " has been pushed\n";
}

int pop(){
    if(top == -1){
        cout << "Stack underflow\n";
        return -1;
    }
    //cout << stck[top] << " has popped\n";
    return stck[top--];
}
int isEmpty(){
    if(top == -1) return 1;
    else return 0;
}
int peek(){
    if(top == -1) return -1;
    else return stck[top];
}
void display(){
    for(int i = top; i >= 0; i--) cout << stck[i] << ' ';
}

int postfixEval(char* symbol){
    int i = 0;
    while(symbol[i]){
        if(symbol[i] == ' ' || symbol[i] == ',' || symbol[i] == '\t'){
            i++;
            continue;
        }
        if(isdigit(symbol[i])){
            int num = 0;
            while(isdigit(symbol[i])){
                num = num * 10 + (symbol[i] - '0');
                i++;
            }
            push(num);
            continue;
        }
        int op1 = pop(); //first
        int op2 = pop(); // second

        switch (symbol[i])
        {
            case '+':
                push(op2 + op1);
                break;
            case '-':
                push(op2 - op1);
                break;
            case '*':
                push(op2 * op1);
                break;
            case '/':
                push(op2 / op1);
                break;
            case '^':
                push(pow(op2, op1));
                break;
        }
        i++;
    }
    return pop();
}

int main(){

    char postfix[MAX];
    cin.getline(postfix, MAX);
    cout << postfixEval(postfix);
    return 0;
}
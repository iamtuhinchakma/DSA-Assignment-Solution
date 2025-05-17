#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int stck[MAX];
int top = -1;


void push(int val){
    if(top == MAX - 1){
        cout << "Stack overflow\n";
        return;
    }
    top++;
    stck[top] = val;
}

int pop(){
    if(top == -1){
        cout << "Stack underflow\n";
        return -1;
    }
    return stck[top--];
}

int isEmpty(){
    if(top == -1) return 1;
    else return 0;
}

int evaluatePostfix(char* symbol){
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

        int op2 = pop();
        int op1 = pop();
        switch ((symbol[i]))
        {
            case '+':
                push((op1 + op2));
                break;
            case '-':
                push((op1 - op2));
                break;
            case '*':
                push((op1 * op2));
                break;
            case '/':
                push((op1 / op2));
                break;
        }
        i++;
    }
    return pop();
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    char postfix[MAX];
    cout << "Enter the postfix expression: " << endl;
    cin.getline(postfix, MAX);
    cout << "Result: " << evaluatePostfix(postfix) << endl;
    return 0;
}
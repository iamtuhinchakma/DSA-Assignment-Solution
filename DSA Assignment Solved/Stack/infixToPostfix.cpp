#include <bits/stdc++.h>
using namespace std;
#define MAX 100
char stck[MAX];
int top = -1;
char infix[MAX], postfix[MAX];

void push(char c){
    if(top == MAX - 1){
        cout << "Stack overflow\n";
        return;
    }
    top++;
    stck[top] = c;
}
char pop(){
    if(top == -1){
        cout << "Stack underflow\n";
        return -1;
    }
    char poppedElements = stck[top];
    top--;
    return poppedElements;
}
int isEmpty(){
    if(top == -1) return 1;
    else return 0;
}
int space(char symbol){
    if(symbol == ' ' || symbol == '\t') return 1;
    else return 0;
}
int precedence(char symbol){
    switch (symbol)
    {
    case '^':
        return 3;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '+':
    case '-':
        return 1;
        break;
    default:
        return 0;
        break;
    }
}

void print(){
    int i = 0;
    while(postfix[i] != '\0'){
        cout << postfix[i++];
    }
    cout << endl;
}

void infixToPostfix(){
    char symbol;
    char next;
    int j = 0;
    for(int i = 0; i < strlen(infix); i++){
        symbol = infix[i];
        if(!space(symbol)){
            switch (symbol)
            {
            case '(':
                push(symbol);
                break;
            case ')':
                while((next = pop()) != '('){
                    postfix[j++] = next;
                }
                break;
            case '^':
            case '/':
            case '*':
            case '+':
            case '-':
                if(!isEmpty() && precedence(stck[top]) >= precedence(symbol)){
                    postfix[j++] = pop();
                }
                push(symbol);
                break;
            default:
                postfix[j++] = symbol;
                break;
            }
        }
    }
    while(!isEmpty()){
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    gets(infix);
    infixToPostfix();
    print();
    return 0;
}
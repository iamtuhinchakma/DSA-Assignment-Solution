#include <bits/stdc++.h>
using namespace std;

#define MAX 100
char stck[MAX];
int top = -1;

char infix[MAX], postfix[MAX];

void push(char c){
    if(top == MAX - 1){
        cout << "Overflow\n";
        return;
    }
    top++;
    stck[top] = c;
}
char pop(){
    if(top == -1){
        cout << "Underflow\n";
        return -1;
    }
    char popElement = stck[top];
    top--;
    return popElement;
}
int isEmpty(){
    if(top == -1) return 1;
    else return 0;
}

int space(char c){
    if(c == ' ' || c == '\t') return 1;
    else return 0;
}

int precedence(char c){
    switch(c){
        case '^': 
            return 3; 
            break;
        case '/':
        case '*':
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
        cout << postfix[i] << ' ';
        i++;
    }
    cout << endl;
}
void conversion(){
    char c, next;
    int j = 0;
    for(int i = 0; i < strlen(infix); i++){
        c = infix[i];
        if(!space(c)){
            switch(c){
                case '(':
                    push(c);
                    break;
                case ')':
                    while((next = pop()) != '('){
                        postfix[j++] = next;
                    }
                    break;
                case '^':
                case '+':
                case '-':
                case '*':
                case '/':
                    if(!isEmpty() && precedence(stck[top] >= precedence(c))){
                        postfix[j++] = pop();
                    }
                    push(c);
                    break;
                default:
                    postfix[j++] = c;
                    break;
            }
        }
    }
    while(!isEmpty()){
        postfix[j++] = pop();
    }
    postfix[j++] = '\0';
}

int main(){
    cout << "Enter the expression: ";
    gets(infix);
    conversion();
    print();
    return 0;
}
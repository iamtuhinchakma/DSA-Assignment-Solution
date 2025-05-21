// #include <iostream>
// #include <cmath>
// #include <cctype>
#include <bits/stdc++.h>
using namespace std;

#define MAX 100

int stck[MAX];
int top = -1;
int values[26]; // For variables a to z

// Stack operations
void push(int val) {
    if (top == MAX - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    stck[++top] = val;
}

int pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
        return -1;
    }
    return stck[top--];
}

// Get or prompt for variable value
int getVariableValue(char ch) {
    int index = ch - 'a';
    if (values[index] == -1) {
        int val;
        cout << "Enter value for " << ch << ": ";
        cin >> val;
        values[index] = val;
    }
    return values[index];
}

int evaluatePostfix(char* expr) {
    int i = 0;
    while (expr[i]) {
        char ch = expr[i];
        
        if (isspace(ch) || ch == ',') {
            i++;
            continue;
        }

        if (isdigit(ch)) {
            push(ch - '0');
        } else if (isalpha(ch)) {
            int val = getVariableValue(ch);
            push(val);
        } else {
            int op1 = pop();
            int op2 = pop();
            switch (ch) {
                case '+': push(op2 + op1); break;
                case '-': push(op2 - op1); break;
                case '*': push(op2 * op1); break;
                case '/': push(op2 / op1); break;
                case '^': push((int)pow(op2, op1)); break;
                default:
                    cout << "Invalid operator: " << ch << endl;
                    return -1;
            }
        }
        i++;
    }
    return pop();
}

int main() {
    char postfix[MAX];
    for (int i = 0; i < 26; i++) {
        values[i] = -1;
    }// Initialize all variables to -1

    cout << "Enter postfix expression: ";
    cin.getline(postfix, MAX);

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;
    return 0;
}

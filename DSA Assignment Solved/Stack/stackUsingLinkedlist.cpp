// Stack impelementation using Linkedlist
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};

Node* createNode(int info){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = info;
    newNode->next = NULL;
    return newNode;
}
void printList(Node* start){
    Node* ptr = start;
    while(ptr != NULL){
        cout << ptr->data << ' ';
        ptr = ptr->next;
    }
    cout << endl;
}
struct stck{
    Node* top = NULL;

    //Push operation;
    void push(int val){
        Node* newNode = createNode(val);
        newNode->next = top;
        top = newNode;
        cout << val << " has pushed into stack\n";
    }

    //Pop opeartion
    void pop(){
        if(isEmpty()){
            cout << "Stack Underflow\n";
            return;
        }
        Node* toDelete = top;
        cout << "Popped: " << toDelete->data << endl;
        top = top->next;
        delete toDelete;
    }

    //peek opeartion;
    int peek(){
        if(isEmpty()){
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }
    bool isEmpty(){
        return top == NULL;
    }

    void display(){
        Node* ptr = top;
        cout << "Stack from the top: \n";
        while( ptr != NULL){
            cout << ptr->data << ' ';
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    stck s;
    s.push(10);
    s.push(20);
    cout << s.peek() << endl;
    s.pop();

    cout << s.peek() << endl;

    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    s.display();
}
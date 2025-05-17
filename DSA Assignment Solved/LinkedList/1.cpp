#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};
//Node creation
Node* createNode(int info){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = info;
    newNode->next = NULL;
    return newNode;
}
//Node printing
void printList(Node* start){
    Node* ptr = start;
    while(ptr != NULL){
        cout << ptr->data << ' ';
        ptr = ptr->next;
    }
    cout << endl;
}
//Node print in reverse
void printInReverse(Node* start){
    if(start == NULL) return;
    printInReverse(start->next);
    cout << start->data << ' ';
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    Node* head = NULL;
    int n;
    // cout << "Number of Inputs: ";
    cin >> n;
    Node* temp;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        if(i == 0){
            head = createNode(val);
            temp = head;
        } else {
            temp->next = createNode(val);
            temp = temp->next;
        }
    }
    printList(head);

    cout << "Reverse Print: \n";
    printInReverse(head);
}
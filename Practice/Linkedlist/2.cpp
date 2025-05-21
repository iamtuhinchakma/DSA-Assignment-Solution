#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* createNode(int data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
}

void print(Node* head){
    Node* ptr = head;
    while(ptr != NULL){
        cout << ptr->data << ' ';
        ptr = ptr->next;
    }
    cout << endl;
}
void reversePrint(Node* head){
    if(head == NULL) return;
    reversePrint(head->next);
    cout << head->data << ' ';
}

bool search(Node* head, int item){
    Node* ptr = head;
    while(ptr != NULL){
        if(ptr->data == item) return true;
        else ptr = ptr->next;
    }
    return false;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif


    Node* head = NULL;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        Node* temp;
        if(i == 0){
            head = createNode(val);
            temp = head;
        } else {
            temp->next = createNode(val);
            temp = temp->next;
        }
    }

    print(head);
    reversePrint(head);

    cout << endl;
    if(search(head, 10)) cout << "item has found\n";
    else cout << "Item not found\n";
    return 0;
}
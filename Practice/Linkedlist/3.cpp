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

Node* insertAtHead(Node* &head, int data){
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return newNode;
}

Node* insertAtTail(Node* &head, int data){
    Node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return newNode;
    }
    Node* ptr = head;
    while(ptr->next!= NULL){
        ptr = ptr->next;
    }
    ptr->next = newNode;
    return newNode;
}

Node* insertAtPos(Node* &head, int data, int pos){
    Node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return newNode;
    }
    if(pos < 1) return head;
    if(pos == 1){
        newNode->next = head;
        head = newNode;
        return newNode;
    }

    Node* ptr = head;
    for(int i = 1; i < pos; i++){
        ptr = ptr->next;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
    return newNode;
}

Node* insertIntoSortedList(Node* &head, int item){
    Node* newNode = createNode(item);
    if(head == NULL){
        head = newNode;
        return newNode;
    }
    Node* ptr = head;
    while(ptr != NULL && ptr->next->data < item){
        ptr = ptr->next;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
    return newNode;
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
    reversePrint(head); cout << endl;

    // insertAtHead(head, 50);
    // print(head);

    // insertAtTail(head, 100);
    // print(head);

    // insertAtPos(head, 99, 3);
    // print(head);

    insertIntoSortedList(head, 0);
    print(head);
    return 0;
}
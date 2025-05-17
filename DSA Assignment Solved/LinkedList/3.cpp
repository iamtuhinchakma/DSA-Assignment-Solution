// LinkedList operation: inserting
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

//Insert at HEAD
Node* insertAtHead(Node* &head, int value){
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
    return newNode;
}

//Insert at tail
Node* insertAtTail(Node* &head, int value){
    Node* newNode = createNode(value);
    if(head == NULL){
        head = newNode;
        return newNode;
    }
    Node* ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = newNode;
    return newNode;
}

//Insert At any Position;
Node* insertAtGivenPos(Node* &head, int pos, int val){
    Node* newNode = createNode(val);
    if(pos < 1){
        return head;
    }
    if(pos == 1){
        newNode->next = head;
        head = newNode;
        return newNode;
    }
    Node* ptr = head;
    for(int i = 0; i < pos - 1; i++)
        ptr = ptr->next;
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

    printList(head);

    //Insert At head;
    int val;
    cin >> val;
    insertAtHead(head, val);

    cout << "After insertion at head: \n";
    printList(head);

    int val1;
    cin >> val1;
    insertAtTail(head, val1);
    cout << "After insertion at tail: \n";
    printList(head);


    int val2, pos = 2;
    cin >> val2;
    insertAtGivenPos(head, pos, val2);
    cout << "After insertion at " << pos << "\n";
    printList(head);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int info) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = info;
    newNode->next = NULL;
    return newNode;
}
//Traversing the linked list
void printLinkedLlist(Node* start){
    Node* ptr = start;
    while(ptr != NULL){
        cout << ptr->data << ' ';
        ptr = ptr->next;
    }
    cout << endl;
}
//Insertion at Head
Node* insertAtHead(Node* &head, int item){
    Node* newNode = createNode(item);
    newNode->next = head;
    head = newNode;
    // cout << "Successfully Inserted!\n";
    return newNode;
}
//Inserting at Tail
Node* insertAtTail(Node* &head, int item){
    Node* newNode = createNode(item);
    if(head == NULL){
        head = newNode;
        return head;
    }
    Node* ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = newNode;
    return newNode;
}
//Delete Node following a given node
Node* deleteAtAnyPos(Node* &head, int index) {
    if (head == NULL) return nullptr;
    if (index == 0) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return head;
    }
    Node* temp = head;
    for (int i = 0; i < index - 1; i++) {
        if (temp == NULL || temp->next == NULL) return nullptr;
        temp = temp->next;
    }
    if (temp->next == NULL) return nullptr;
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
    return head;
}
int main() {
    int Q;
    cin >> Q;

    Node* head = NULL;

    // Process each query
    for (int i = 0; i < Q; i++) {
        int X, V;
        cin >> X >> V;

        if (X == 0) {
            // Insert at head
            insertAtHead(head, V);
        } else if (X == 1) {
            // Insert at tail
            insertAtTail(head, V);
        } else if (X == 2) {
            // Delete at index V
            deleteAtAnyPos(head, V);
        }
        printLinkedLlist(head);
    }
    return 0;
}

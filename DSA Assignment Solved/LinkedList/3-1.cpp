// LinkedList operation: inserting at sorted list
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

//InsertintoSortedList
Node* insertInSortedList(Node* &head, int val){
    Node* newNode = createNode(val);
    Node* ptr = head;
    while(ptr != NULL && ptr->next->data < val){
        ptr = ptr->next;
    }

    newNode->next = ptr->next;
    ptr->next = newNode;
    return newNode;
}

//Reverse print
void reversePrint(Node* head){
    if(head == NULL) return;
    reversePrint(head->next);
    cout << head->data << ' ';
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

    int item;
    cin >> item;
    insertInSortedList(head, item);
    cout << "After insertion: \n";
    printList(head);

    reversePrint(head);
    return 0;
}
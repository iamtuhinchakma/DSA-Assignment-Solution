// LinkedList operation: Deletion in linked list
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

//Head Deletion
Node* deleteHead(Node* &head){
    if(head == NULL){
        return nullptr;
    }
    Node* toDelete = head;
    head = head->next;
    delete toDelete;
    return head;
}

//Tail deletion;
Node* deleteTail(Node* &head){
    Node* ptr = head;
    if(head == NULL) return nullptr;

    Node* toDelete;
    if(head->next == NULL){
        toDelete = head;
        delete toDelete;
        return nullptr;
    }
    while(ptr->next->next != NULL){
        ptr = ptr->next;
    }
    toDelete = ptr->next;
    ptr->next = NULL;
    delete toDelete;
    return head;
}

//Delete any index;
Node* deleteAnyIndex(Node* &head, int index){
    if(head == NULL) return nullptr;

    Node* ptr = head;
    //Considering start at 0 index
    for(int i = 0; i < index - 1; i++){
        ptr = ptr->next;
    }
    Node* toDelete = ptr->next;
    ptr->next = ptr->next->next;
    delete toDelete;
    return head;
}

//Delete any pos
Node* deleteAnyPos(Node* &head, int pos){
    Node* ptr = head;
    if(head == NULL) return nullptr;
    Node* toDelete;

    // Special case: delete position 1 (head)
    if (pos == 1) {
        toDelete = head;
        head = head->next;
        delete toDelete;
        return head;
    }
    for(int i = 1; i < pos - 1; i++){
        ptr = ptr->next;
    }
    toDelete = ptr->next;
    ptr->next = ptr->next->next;
    delete toDelete;
    return head;
}

//Delete Specific data node
Node* deleteSpecificData(Node* &head, int item){
    if(head == NULL) return nullptr;
    Node* toDelete;
    if(head->data == item){
        toDelete = head;
        head = head->next;
        delete toDelete;
        return head;
    }

    //Traverse to find the node just before the one to delete
    Node* ptr = head;
    while(ptr->next != NULL && ptr->next->data != item){
        ptr = ptr->next;
    }

    if(ptr->next == NULL){
        cout << "Item not found in the list\n";
        return head;
    }
    toDelete = ptr->next;
    ptr->next = ptr->next->next;
    delete toDelete;
    return head;
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

    //Delete head;
    deleteHead(head);
    cout << "After deleted Head: \n";
    printList(head);

    //Delete Tail;
    // deleteTail(head);
    // cout << "After deleted head: \n";
    // printList(head);

    //Delete Any index Node;
    deleteAnyIndex(head, 2);
    cout << "After Deletion: \n";
    printList(head);


    //Delete any positon node;
    deleteAnyPos(head, 1);
    cout << "After deleting specific position node: \n";
    printList(head);

    //Delete specific node
    int val;
    cin >> val;
    deleteSpecificData(head, val);
    cout << "After deleting " << val << endl;
    printList(head);
    return 0;
}
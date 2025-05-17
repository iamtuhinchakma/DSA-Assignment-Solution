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

//Merging two list;
void mergeList(Node* head, Node* head1){
    if(head == NULL){
        head = head1;
        return;
    }
    Node* ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = head1;
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
    cout << "First Original List: \n";
    printList(head);

    Node* head1 = NULL;
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int val;
        cin >> val;
        Node* temp;
        if(i == 0){
            head1 = createNode(val);
            temp = head1;
        } else {
            temp->next = createNode(val);
            temp = temp->next;
        }
    }

    cout << "Second Original List: \n";
    printList(head1);

    mergeList(head, head1);
    cout << "After merging: \n";
    printList(head);

}
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
bool findDuplicate(Node* head){

    for(Node* i = head; i->next != NULL; i = i->next){
        for(Node* j = i->next; j != NULL; j = j->next){
            if(i->data == j->data){
                return true;
            }
        }
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
    cout << "First Original List: \n";
    printList(head);

    //Look for duplicate elements;
    if(findDuplicate(head)) cout << "There is duplicate elemente exist\n";
    else cout << "No duplicate elements\n";
}
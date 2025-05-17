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

//Sort the list
void sortList(Node* head){
    Node* ptr = head;
    for(Node* i = ptr; i->next != NULL; i = i->next){
        for(Node* j = i->next; j != NULL; j = j->next){
            if(i->data > j->data){
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

//reverse print
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
    cout << "Original List: \n";
    printList(head);

    sortList(head);
    cout << "List after sorted: \n";
    printList(head);

    cout << "Reverse: \n";
    reversePrint(head);
}
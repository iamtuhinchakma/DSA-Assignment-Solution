//Printing middle elemement
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
//Finding middle element
void findMiddle(Node* head){
    int n = 0;
    Node* ptr = head;
    while(ptr != NULL){
        n++;
        ptr = ptr->next;
    }
    cout << "List size: " << n << endl;

    //go to middle element
    ptr = head;
    for(int i = 0; i < n / 2 - (n % 2 == 0 ? 1 : 0); i++){
        ptr = ptr->next;
    }

    if(n % 2 == 0){
        cout << "Middle elements are: " << ptr->data << " and " << ptr->next->data << endl;
    } else {
        cout << "Middle element is: " << ptr->data << endl;
    }
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

    findMiddle(head);
}
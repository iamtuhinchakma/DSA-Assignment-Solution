/* Opeartion: Searching and traversing*/
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
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
//Traversing through the list
void traversing(Node* start){
    Node* ptr = start;
    int sum = 0;
    int max = INT_MIN;
    int min = INT_MAX;
    while(ptr != NULL){
        sum += ptr->data;
        if(ptr->data > max) max = ptr->data;
        if(ptr->data < min) min = ptr->data;
        ptr = ptr->next;
    }
    cout << "Total Sum is: " << sum << endl;
    cout << "Maximum Value is: " << max << endl;
    cout << "Minimum Value is: " << min << endl;
    cout << "The sine value is: " << sin(sum) << endl;
}

//Search through the unsorted List;
bool searchingInList(Node* start, int value){
    Node* ptr = start;
    while(ptr != NULL){
        if(ptr->data == value){
            return true;
        } else {
            ptr = ptr->next;
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
    printList(head);
    traversing(head);
    
    //For search opeartion;
    int to_find;
    cin >> to_find;
    if(!searchingInList(head, to_find)) cout << "Item has not found\n";
    else cout << "Item has been found\n";
}
/* Split nodes of a linked list into the front and 
back halves. If the total number of elements in 
the list is odd, the extra element should go in the 
front list. For example, list {2, 3, 5, 7, 11} 
should yield the two lists with {2, 3, 5} and {7.11)
*/

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
void solve(Node* head){
    Node* head1 = NULL;
    Node* head2 = NULL;

    Node* ptr = head;
    int size = 0;
    while(ptr != NULL){
        size++;
        ptr = ptr->next;
    }
    cout << "Size of the list: " << size << endl;

    //if size even go through till size/2 - 1 and if odd go through size/2
    if(size % 2 == 0){
        ptr = head;
        head1 = ptr;
        for(int i = 0; i < size / 2 - 1; i++){
            ptr = ptr->next;
        }
        head2 = ptr->next;
        ptr->next = NULL;

        Node* temp = head1;
        cout << "First halves: \n";
        while(temp != NULL){
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << endl;

        temp = head2;
        cout << "Second halves: \n";
        while(temp != NULL){
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << endl;
    } else {
        ptr = head;
        head1 = ptr;
        for(int i = 0; i < size / 2; i++){
            ptr = ptr->next;
        }
        head2 = ptr->next;
        ptr->next = NULL;

        Node* temp = head1;
        cout << "First halves: \n";
        while(temp != NULL){
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << endl;

        temp = head2;
        cout << "Second halves: \n";
        while(temp != NULL){
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << endl;

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

    solve(head);
}
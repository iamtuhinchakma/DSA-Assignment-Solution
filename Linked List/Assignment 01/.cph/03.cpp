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
int areListsEqual(Node* head1, Node* head2) {
    while (head1 != NULL && head2 != NULL) {
        if (head1->data != head2->data) {
            return 0;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return (head1 == NULL && head2 == NULL);
}

int main() {
    Node *head1 = NULL, *tail1 = NULL;
    Node *head2 = NULL, *tail2 = NULL;
    int val;
    while (true) {
        cin >> val;
        if (val == -1) break;
        
        Node* newNode = createNode(val);
        if (head1 == NULL) {
            head1 = tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }
    while (true) {
        cin >> val;
        if (val == -1) break;
        
        Node* newNode = createNode(val);
        if (head2 == NULL) {
            head2 = tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }
    if (areListsEqual(head1, head2)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}

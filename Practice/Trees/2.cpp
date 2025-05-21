#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* leftChild;
    Node* rightChild;
};
Node* createNode(int data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

Node* insert(Node* root, int item){
    Node* current = root;
    Node* newNode = createNode(item);

    while(current != NULL){
        if(current->data > newNode->data){
            if(current->leftChild != NULL){
                current = current->leftChild;
            } else{
                current->leftChild = newNode;
                break; 
            }
        } else if(current->data < newNode->data){
            if(current->rightChild != NULL){
                current = current->rightChild;
            } else {
                current->rightChild = newNode;
                break;
            }
        }  else {
            return root;
        }
    }
    if (root != NULL) return root;
    else return newNode;
}



void print(Node* root){
    if(root == NULL) return;
    cout << root->data << " ";
    print(root->leftChild);
    print(root->rightChild);
}

void preOrder(Node* root){
    if(root == NULL) return;
    cout << root->data << " ";
    preOrder(root->leftChild);
    preOrder(root->rightChild);
}


void print2D(Node* root, int space){
    if(root == NULL) return;

    space += 3;

    print2D(root->rightChild, space);
    cout << endl;
    for(int i = 7; i < space; i++){
        cout << ' ';
    }
    cout << root->data << endl;
    print2D(root->leftChild, space);
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    Node* root = NULL;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int val;
        cin >> val;
        root = insert(root, val);
    }

    print(root);
    cout << endl;
    cout << endl;
    cout << "Inorder Traversal: \n";
    print2D(root, 5);

    cout << endl;
    cout << endl;

    preOrder(root);
    return 0;
}
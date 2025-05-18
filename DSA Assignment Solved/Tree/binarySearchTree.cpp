#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* leftChild;
    Node* rightChild;
};
Node* createNode(int item){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = item;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

Node* insert(Node* root, int item){
    Node* current = root;
    Node* newNode = createNode(item);

    int loc = 1;
    while(current != NULL){
        if(current->data > newNode->data){
            if(current->leftChild != NULL){
                current = current->leftChild;
                loc = 2 * loc;
            } else {
                current->leftChild = newNode;
                break;
            }

        } else if(current->data < newNode->data){
            if(current->rightChild != NULL){
                current = current->rightChild;
                loc = 2*loc + 1;
            } else {
                current->rightChild = newNode;
                break;
            }
        }
    }
    return root ? root : newNode;
}

void print(Node* root){
    if(root == NULL) return;
    print(root->leftChild);
    cout << root->data << ' ';
    print(root->rightChild);
}

void printIn2D(Node* root, int space){
    if(root == NULL) return;
    space += 5;
    printIn2D(root->rightChild, space);
    cout << endl;
    for(int i = 5; i < space; i++)
        cout << ' ';
    cout << root->data << endl;
    printIn2D(root->leftChild, space);
}

void preorderTraversal(Node* root){
    if(root == NULL) return;
    cout << root->data << ' ';
    preorderTraversal(root->leftChild);
    preorderTraversal(root->rightChild);
}

void inorderTraversal(Node* root){
    if(root == NULL) return;
    inorderTraversal(root->leftChild);
    cout << root->data << " ";
    inorderTraversal(root->rightChild);
}

void postorderTraversal(Node* root){
    if(root == NULL) return;
    postorderTraversal(root->leftChild);
    postorderTraversal(root->rightChild);
    cout << root->data << " ";
}

Node* searchAndInsert(Node* root, int item){
    Node* current = root;
    while(current != NULL){
        if(current->data == item){
            cout << "Value " << item << " has been found\n";
            return root;
        }
        else if(current->data > item){
            if(current->leftChild != NULL){
                current = current->leftChild;
            } else {
                current->leftChild = createNode(item);
                cout << "Inserted\n";
                return root;
            }
        } else {
            if(current->rightChild != NULL){
                current = current->rightChild;
            } else {
                current->rightChild = createNode(item);
                cout << "Successfully inserted item\n";
                return root;
            }
        }
    }
    cout << "Tree was empty and successfuly inserted the item\n";
    return createNode(item);
} 
int main() {
    Node* root = NULL;
    int n;
    cout << "Input the number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    cout << "\nIn-order traversal: ";
    print(root);

    cout << "\n\nTree in 2D view:\n";
    printIn2D(root, 5);

    cout<<endl<<"inorder: "<<endl;
    inorderTraversal(root);

    cout << endl;
    cout << endl;
    int searchVal;
    cout << "\nEnter a value to search (and insert if not found): ";
    cin >> searchVal;
    root = searchAndInsert(root, searchVal);

    cout << endl;
    cout << endl;
    print(root);

    cout << endl;
    cout << endl;

    printIn2D(root, 5);
    return 0;
}


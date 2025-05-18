#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6;
int tree[MAX];


// Initialize array to 0 (0 means empty)
void initialize(){
    for(int i = 0; i < MAX; i++){
        tree[i] == 0;
    }
}
void insert(int data){
    for(int i = 1; i < MAX; i++){
        if(tree[i] == 0){
            tree[i] = data;
            return;
        }
    }
}
void preorder(int index) {
    if (index >= MAX || tree[index] == 0) return;

    cout << tree[index] << " ";        // Visit root
    preorder(2 * index);              // Left subtree
    preorder(2 * index + 1);          // Right subtree
}

void inorder(int index) {
    if (index >= MAX || tree[index] == 0) return;
    inorder(2 * index);               // Left subtree
    cout << tree[index] << " ";        // Visit root
    inorder(2 * index + 1);           // Right subtree
}

void postorder(int index) {
    if (index >= MAX || tree[index] == 0) return;
    postorder(2 * index);             // Left subtree
    postorder(2 * index + 1);         // Right subtree
    cout << tree[index] << " ";        // Visit root
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // insert(1); // root
    // insert(2); // left child of root
    // insert(3); // right child of root
    // insert(4); // left child of node 2
    // insert(5); // right child of node 2
    // insert(6); // left child of node 3
    // insert(7); // right child of node 3
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int val;
        cin >> val;
        insert(val);
    }
    
    for (int i = 1; i <= n; i++) {
        cout << tree[i] << " ";
    }
    cout << endl;

    cout << "Preorder: ";
    preorder(1);
    cout << endl;

    cout << "Inorder: ";
    inorder(1);
    cout << endl;

    cout << "Postorder: ";
    postorder(1);
    cout << endl;
    return 0;
}

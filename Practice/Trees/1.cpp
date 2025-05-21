#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6;
int tree[MAX];

void initialize(){
    for(int i = 0; i < MAX; i++){
        tree[i] = 0;
    }
}

void insert(int item){
    for(int i = 1; i < MAX; i++){
        if(tree[i] == 0){
            tree[i] = item;
            return;
        }
    }
}

void preOrder(int root){
    if(root >= MAX || tree[root] == 0) return;
    cout << tree[root] << ' ';
    preOrder(2 * root);
    preOrder(2 * root + 1);
}
void inOrder(int root){
    if(root >= MAX || tree[root] == 0) return;
    inOrder(2 * root);
    cout << tree[root] << ' ';
    inOrder(2 * root + 1);
}

void postOrder(int root){
    if(root >= MAX || tree[root] == 0) return;
    postOrder(2*root);
    postOrder(2*root + 1);
    cout << tree[root] << ' ';
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    initialize();

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int val;
        cin >> val;
        insert(val);
    }
    for(int i = 1; i <= n; i++){
        cout << tree[i] << ' ';
    }
    cout << endl;

    cout << "Inorder: ";
    inOrder(1);
    cout << endl;

    
    cout << "Post Order: ";
    postOrder(1);
    cout << endl;

    cout << "Pre Order: ";
    preOrder(1);
    cout << endl;


    return 0;
}
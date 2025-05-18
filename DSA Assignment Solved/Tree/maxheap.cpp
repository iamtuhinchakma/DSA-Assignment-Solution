/* This program insert and delete an element from heap*/
#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
int heap[MAX];
int n = 0;

void initialize(){
    for(int i = 0; i < MAX; i++){
        heap[i] = -1;
    }
}
void insert(int item){
    n++;
    int index = n;
    heap[index] = item;
    while(index > 1){
        int parent = index / 2;
        if(heap[parent] < heap[index]){
            swap(heap[parent], heap[index]);
            index = parent;
        } else {
            return;
        }
    }
}

void printHeap(){
    for(int i = 1; i <= n; i++) cout << heap[i] << ' ';
    cout << endl;
}
void print_2D_heap(int index, int space) {
    if (index > n) return;

    space += 5;

    // Print right child first
    print_2D_heap(2 * index + 1, space);

    // Print current node
    cout << endl;
    for (int i = 5; i < space; i++) cout << " ";
    cout << heap[index] << endl;

    // Print left child
    print_2D_heap(2 * index, space);
}

int main() {
    initialize(); // initialize heap with size = 0

    // insert(125);
    // insert(120);
    // insert(40);
    // insert(60);
    // insert(100);
    // insert(75);
    // insert(58);
    // insert(31);

    
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert(x);
    }

    cout << "\nHeap as array:\n";
    printHeap();

    cout << "\nHeap as 2D tree view:\n";
    print_2D_heap(1, 0); // visual tree

    return 0;
}
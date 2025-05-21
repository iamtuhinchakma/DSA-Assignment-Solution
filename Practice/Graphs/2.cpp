#include <bits/stdc++.h>
using namespace std;
const int MAX_VERTICES = 100;
struct Node{
    int vertex;
    Node* next;
};
Node* adjList[MAX_VERTICES] = {NULL};


void addEdge(int src, int dest){
    Node* newNode = new Node; 
    newNode->vertex = dest; //Creates a new node with vertex = dest.
    newNode->next = adjList[src]; //Sets its next pointer to the current head of src's list.
    adjList[src] = newNode; //Updates the head of src's list to point to the new node.

    newNode = new Node;
    newNode->vertex = src;
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

void printAdjacencyList(int numVertices) {
    for (int i = 0; i < numVertices; ++i) {
        cout << "Adjacency list for vertex " << i << ": ";
        Node* current = adjList[i];
        while (current) {
            cout << current->vertex << " ";
            current = current->next;
        }
        cout << endl;
    }
}

int main() {
    int numVertices = 5;

    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(3, 4);

    printAdjacencyList(numVertices);

    return 0;
}

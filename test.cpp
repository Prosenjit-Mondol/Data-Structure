#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_NODES = 100;
vector<int> adj[MAX_NODES];

void insertNode(int node) {
    if (node >= MAX_NODES) return;
    // No action needed here since we can directly add edges
}

void insertEdge(int u, int v) {
    adj[u].push_back(v);
}

void deleteNode(int node) {
    for (int i = 0; i < MAX_NODES; i++) {
        adj[i].erase(remove(adj[i].begin(), adj[i].end(), node), adj[i].end());
    }
    adj[node].clear();
}

void deleteEdge(int u, int v) {
    adj[u].erase(remove(adj[u].begin(), adj[u].end(), v), adj[u].end());
}

void printGraph() {
    for (int i = 0; i < MAX_NODES; i++) {
        if (!adj[i].empty()) {
            cout << i << " -> ";
            for (int j : adj[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    insertNode(1);
    insertNode(2);
    insertNode(3);

    insertEdge(1, 2);
    insertEdge(2, 3);
    insertEdge(1, 3);

    cout << "Graph connections:\n";
    printGraph();

    deleteEdge(1, 3);
    cout << "\nAfter deleting edge (1, 3):\n";
    printGraph();

    deleteNode(2);
    cout << "\nAfter deleting node 2:\n";
    printGraph();

    return 0;
}

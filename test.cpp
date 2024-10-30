#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to add an edge to the graph
void addEdge(vector<vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u); // For undirected graph
}

// Function to delete a node from the graph
void deleteNode(vector<vector<int>>& adjList, int node) {
    if (node >= adjList.size()) return; // Node out of bounds

    // Remove all edges connected to the node
    for (int neighbor : adjList[node]) {
        adjList[neighbor].erase(remove(adjList[neighbor].begin(), adjList[neighbor].end(), node), adjList[neighbor].end());
    }

    // Clear the list of the node itself
    adjList[node].clear();
}

int main() {
    int nodes = 5; // Initial graph with 5 nodes (0 to 4)
    vector<vector<int>> adjList(nodes);

    // Adding some edges
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 2, 4);

    cout << "Graph before deleting a node:" << endl;
    for (int i = 0; i < adjList.size(); ++i) {
        cout << "Node " << i << ": ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    // Delete a node
    int nodeToDelete = 1;
    deleteNode(adjList, nodeToDelete);

    cout << "\nGraph after deleting node " << nodeToDelete << ":" << endl;
    for (int i = 0; i < adjList.size(); ++i) {
        cout << "Node " << i << ": ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    return 0;
}

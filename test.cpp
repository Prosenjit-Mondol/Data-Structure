#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to add an edge to the graph
void addEdge(vector<vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u); // Undirected graph
}

// Function to perform BFS and find a target node
bool findNode(const vector<vector<int>>& adjList, int start, int target) {
    vector<bool> visited(adjList.size(), false); // Track visited nodes
    queue<int> q;

    visited[start] = true; // Mark the start node as visited
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == target) {
            return true; // Target node found
        }

        // Explore neighbors
        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return false; // Target node not found
}

int main() {
    int nodes = 5; // Example number of nodes
    vector<vector<int>> adjList(nodes); // Adjacency list

    // Add edges
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 2, 4);

    int start = 0;
    int target = 3;

    if (findNode(adjList, start, target)) {
        cout << "Node " << target << " is reachable from node " << start << endl;
    } 
    else {
        cout << "Node " << target << " is NOT reachable from node " << start << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout << "Enter the number of vertices: ";
    int n; // Number of vertices
    cin >> n;
    cout << "Enter the number of edges: ";
    int x; // Number of edges
    cin >> x;

    vector<vector<int>> adj(n); // Adjacency list for n vertices

    cout << "Enter the edges (pair of vertices for each edge):" << endl;
    for (int i = 0; i < x; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Print adjacency list
    for (int i = 0; i < n; i++)
    {
        cout << "Node " << i << ": ";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& adj, int st)
{
    queue<int> q;
    q.push(st);
    vector<bool> visit(adj.size(), false);
    visit[st] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for (int i : adj[st])
        {
            if (!visit[i])
            {
                visit[i] = true;
                q.push(i);
            }
        }
    }
}

int main()
{
    cout << "Enter the number of vertices: ";
    int n;
    cin>>n;
    cout << "Enter the number of edges: ";
    int x;
    cin >> x;
    vector<vector<int>> adj(n);
    cout << "Enter the edges (pair of vertices for each edge):" << endl;
    for (int i = 0; i < x; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    cout << "BFS Starting node 0\n";
    bfs(adj, 0);
    return 0;
}
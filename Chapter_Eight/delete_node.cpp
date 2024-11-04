#include<bits/stdc++.h>
using namespace std;

void deletenode(vector<vector<int>>& adj,int node){
    if (node>=adj.size())
    {
        return;
    }
    for (int neighbor : adj[node])
    {
        adj[neighbor].erase(remove(adj[neighbor].begin(), adj[neighbor].end(), node), adj[neighbor].end());
    }
    adj[node].clear();
}

int main()
{
    cout<<"Enter the num of vertex: ";
    int n;
    cin>>n;
    vector<vector<int>>adj(n);
    cout<<"Enter the num of edges: ";
    int x;
    cin>>x;
    cout << "Enter the edges (pair of vertices for each edge):" << endl;
    for (int i = 0; i < x; i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << "Graph before deleting a new node:" << endl;
    for (int i = 0; i <n; i++)
    {
        cout << "Node " << i << ": ";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<"Enter the delete node number: ";
    int u;
    cin>>u;
    deletenode(adj,u);

    cout << "\nGraph after deleting node " << u << ":" << endl;
    for (int i = 0; i <adj.size(); i++)
    {
        cout << "Node " << i << ": ";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<'\n';
    }

    return 0;
}
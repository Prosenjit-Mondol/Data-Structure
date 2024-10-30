#include<bits/stdc++.h>
using namespace std;

void insertnode(vector<vector<int>>& adj){
    adj.push_back(vector<int>());
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
    cout << "Graph before adding a new node:" << endl;
    for (int i = 0; i <n; i++)
    {
        cout << "Node " << i << ": ";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<'\n';
    }
    
    insertnode(adj);
    int newnode=adj.size()-1;
    
    adj[newnode].push_back(1);
    adj[1].push_back(newnode);

    cout << "Graph after adding a new node:" << endl;
    for (int i = 0; i <adj.size(); i++)
    {
        cout << "Node " << i << ": ";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<'\n';
    }
}
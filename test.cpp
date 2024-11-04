#include<bits/stdc++.h>
using namespace std;
bool fin(vector<vector<int>>& adj,int u,int v){
    for(int x:adj[u])
    {
        if(x==v) return true;
    }
    return false;
}
void insertnode(vector<vector<int>>& adj){
    adj.push_back(vector<int>());
}
void deletenode(vector<vector<int>>& adj,int node){
    if(node>=adj.size()) return;

    for (auto x:adj[node])
    {
        adj[x].erase(remove(adj[x].begin(),adj[x].end(),node),adj[x].end());
    }
    adj[node].clear();
}
int main()
{
    cout<<"Enter the num of node: ";
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    cout<<"Enter the edges: ";
    int x;
    cin>>x;
    for (int i = 0; i <x; i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);

    }
    cout<<"Graph before adding a new node: "<<'\n';
    for (int i = 0; i < n; i++)
    {
        cout<<"Node "<<i<<": ";
        for (int j = 0; j <adj[i].size(); j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<'\n';
    }
    insertnode(adj);
    int ne=adj.size()-1;

    adj[ne].push_back(1);
    adj[1].push_back(ne);

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

    cout<<"Enter the finding edge: ";
    int u,v;
    cin>>u>>v;

    if(fin(adj,u,v))
    cout<<1;
    else
    cout<<0;



    cout<<"Enter the delete node number: ";
    
    cin>>u;
    deletenode(adj,u);
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
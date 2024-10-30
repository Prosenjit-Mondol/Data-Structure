#include<bits/stdc++.h>
using namespace std;

bool find_edge(vector<vector<int>>& adj,int u,int v){
    for(int x:adj[u]){
        if (v==x)
        {
            return true;
        }
        
    }
    return false;
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
    cout<<"Enter the finding edge: ";
    int u,v;
    cin>>u>>v;
    if(find_edge(adj,u,v))
    cout<<"This edge is exited in this graph\n";
    else
    cout<<"This edge does not exited in this graph\n";

    return 0;
}
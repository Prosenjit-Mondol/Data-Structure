#include <bits/stdc++.h>
using namespace std;

void dfsre(vector<vector<int>>& adj ,vector<bool>& visit,int s){
    visit[s]=true;
    cout<<s<<" ";

    for (int  i : adj[s])
    {
        if(!visit[i]){
            dfsre(adj,visit,i);
        }
    }
    
}
void dfs(vector<vector<int>>& adj,int s)
{
    vector<bool>visit(adj.size(),false);
    dfsre(adj,visit,s);
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

    for (int i = 0; i <x; i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout<<"DFS starting node: ";
    dfs(adj,0);
    return 0;
}
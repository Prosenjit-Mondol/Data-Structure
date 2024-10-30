#include<bits/stdc++.h>
using namespace std;

bool find_node(vector<vector<int>>& adj, int s,int t)
{
    vector<bool>visit(adj.size(),false);
    queue<int>q;
    visit[s]=true;
    q.push(s);

    while (!q.empty())
    {
        int cur=q.front();
        q.pop();
        if(cur==t){
            return true;
        }
        for (int  i : adj[cur])
        {
            if (!visit[i])
            {
                q.push(i);
                visit[i]=true;
            }
            
        }
        
    }
    return false;
}


int main()
{
    cout << "Enter the number of vertices: ";
    int n;
    cin>>n;
    cout << "Enter the number of edges: ";
    int x;
    cin >> x;
    vector<vector<int>> adj(n+1);
    cout << "Enter the edges (pair of vertices for each edge):" << endl;
    for (int i = 0; i < x; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int t;
    cout<<"Enter the target node: ";
    cin>>t;
    if (find_node(adj,0,t))
    {
        cout<<t<<" node is find in this graph."<<'\n';
    }
    else
    cout<<t<<" node is not reachable"<<'\n';

    return 0;

}
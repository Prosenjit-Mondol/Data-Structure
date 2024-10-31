#include<bits/stdc++.h>
using namespace std;

void inorder(vector<int>& tree,int s,int n)
{
    if (s>=n || tree[s]==-1)
    {
        return;
    }
    
    inorder(tree,2*s+1,n);
    cout<<tree[s]<<" ";
    inorder(tree,2*s+2,n);
}

int main()
{
    cout<<"Enter the number of node: ";
    int n;
    cin>>n;
    vector<int>tree;
    for(int i=0;i<n;i++)
    {
        int o;
        cin>>o;
        tree.push_back(o);
    }
    int size=tree.size();

    cout<<" In-Order traversal: ";
    inorder(tree,0,size);

    return 0;

}
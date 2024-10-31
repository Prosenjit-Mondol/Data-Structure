#include<bits/stdc++.h>
using namespace std;
int delet(vector<int>& v,int n,int k)
{
    for (int i = k; i <n-1; i++)
    {
        v[i]=v[i+1];
    }
    return n-1;
}
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int o;
        cin>>o;
        v.push_back(o);
    }
    cout<<"Position of deleting element: ";
    int k;
    cin>>k;
    int l=delet(v,n,k-1);
    for(int i=0;i<l;i++)
    {
    cout<<v[i]<<" ";
    }
}
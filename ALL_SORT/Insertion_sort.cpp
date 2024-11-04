#include<bits/stdc++.h>
using namespace std;

void insertion(vector<int>& v,int n)
{
    if (n==1)
    {
        return;
    }


    for (int i = 1; i < n; i++)
    {
        int j=i-1;
        int k=v[i];
        while (j>=0 && v[j]>k)
        {
            v[j+1]=v[j];
            j--;
            v[j+1]=k;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }

    insertion(v,n);

    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }
    
    return 0;
}
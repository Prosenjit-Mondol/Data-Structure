#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int v[n];
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    
    for (int i = 0; i < n-1; i++)
    {
        for (int j= 0; j <n-i; j++)
        {
            if (v[j]>v[j+1])
            {
                 swap(v[j],v[j+1]);
            }
            
        }
        
    }
    for(auto element : v)
    {
    cout<<element<<" ";
    }
    return 0;
}
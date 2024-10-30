#include<bits/stdc++.h>
using namespace std;

void bubsort(vector<int>& a){
    int n=a.size();
    bool s;

    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
                s=true;
            }
            
        }
        if (!s)
        {
            break;
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
        int o;
        cin>>o;
        v.push_back(o);
    }
    bubsort(v);
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }

    return 0;
}
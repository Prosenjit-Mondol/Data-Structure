#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&v,int p,int q,int r)
{
    int n1=q-p+1;
    int n2=r-q;

    int l[n1],m[n2];

    for (int i = 0; i <n1; i++)
    {
        l[i]=v[i+p];
    }
    for (int i = 0; i < n2; i++)
    {
        m[i]=v[i+q+1];
    }
    int i=0,j=0,k=p;

    while (i<n1&&j<n2)
    {
        if (l[i]<=m[j])
        {
            v[k]=l[i];
            i++;
        }
        else
        {
            v[k]=m[j];
            j++;
        }
        k++;
    }

    while (i<n1)
    {
        v[k]=l[i];
            i++;
            k++;
    }
    while (j<n2)
    {
        v[k]=m[j];
            j++;
            k++;
    }
    
    
}
void mergesort(vector<int>& v,int p,int r)
{
    if (p>=r)
    {
        return;
    }
    int q=(p+r)/2;
    mergesort(v,p,q);
    mergesort(v,q+1,r);

    merge(v,p,q,r);
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

    mergesort(v,0,n-1);

    for(auto element : v)
    {
    cout<<element<<" ";
    }

    return 0;
}
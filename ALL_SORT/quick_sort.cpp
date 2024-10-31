#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& v,int s,int e)
{
    int privot=v[s];

    int c=0;

    for (int i = s+1; i <=e; i++)
    {
        if (v[i]<=privot)
        {
            c++;
        }
        
    }
    int pi=s+c;
    swap(v[s],v[pi]);
    int i=s,j=e;
    while (i<pi && j>pi)
    {
        while (v[i]<=privot)
        {
            i++;
        }
        while (v[j]>privot)
        {
            j--;
        }
        if (i<pi && j>pi)
        {
            swap(v[i++],v[j--]);
        }
        
    }
    return pi;
}
void quicksort(vector<int>& v,int s,int e)
{
    if (s>=e)
    {
        return;
    }
    int p=partition(v,s,e);

    quicksort(v,s,p-1);
    quicksort(v,p+1,e);

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

    quicksort(v,0,n-1);

    for(auto element : v)
    {
    cout<<element<<" ";
    }
    return 0;
}
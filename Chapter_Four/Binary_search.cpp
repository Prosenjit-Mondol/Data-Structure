#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int o;
        cin>>o;
        v.push_back(o);
    }

    //Bubble Sort

    sort(v.begin(),v.end());

    cout<<"Search Item : ";
    int item;
    cin>>item;

    int beg=0,end=n,mid=(beg+end)/2;
    while (beg<end && v[mid]!=item)
    {
        if (item<v[mid])
        {
            end=mid-1;
        }
        else
        beg=mid+1;

        mid=(beg+end)/2;
    }
    if (v[mid]==item)
    {
        cout<<mid+1<<'\n';
    }
    else
    cout<<0<<'\n';

    return 0;
}
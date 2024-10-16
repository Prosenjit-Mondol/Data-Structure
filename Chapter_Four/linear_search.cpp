#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
cin>>n;
int a[n];
for (int i = 0; i < n; i++)
{
    cin>>a[i];
}

// Linear search
int item=2001;
a[n]=item;
int loc=0;
while(a[loc]!=item)
{
    loc++;
}
if (loc==n)
{
    cout<<0<<'\n';
}
else
cout<<loc+1<<'\n';
return 0;
}
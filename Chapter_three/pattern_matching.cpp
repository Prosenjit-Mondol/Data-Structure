//Author  :  PROSENJIT MONDOL


#include<bits/stdc++.h>
using namespace std;

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

string a,b;
cin>>a>>b;
int in=0,k=0,max=a.size()-b.size()+1;
while (k<max)
{
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i]!=a[i+k])
        {
            break;
        }
        if (i+1==b.size())
        {
            in=k+1;
            cout<<in<<'\n';
            return 0;
        }
    }
    k++;
}
cout<<in<<'\n';
return 0;
}
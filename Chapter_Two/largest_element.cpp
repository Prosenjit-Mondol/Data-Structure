//Author  :  PROSENJIT MONDOL


#include<bits/stdc++.h>
using namespace std;

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n;
cin>>n;
int a[n];
for (int i = 0; i < n; i++)
{
    cin>>a[i];
}

int k=0,loc=0,max=a[0];
while (1)
{
    k++;
    if (k>=n)
    {
        cout<<loc+1<<" "<<max<<'\n';
        break;
    }
    if (max<a[k])
    {
        loc=k;
        max=a[k];
    }
    
}


return 0;
}
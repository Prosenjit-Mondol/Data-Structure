//Author  :  PROSENJIT MONDOL


#include<bits/stdc++.h>
using namespace std;

//------------------------------------------------------------------------------

void insertion(int a[],int n)
{
    if(n==1)
    return;
    for (int i = 1; i <n; i++)
    {
        int j=i-1;
        int k=a[i];
        while (j>=0 && a[j]>k)
        {
            a[j+1]=a[j];
            j=j-1;
            a[j+1]=k;
        }
        
    }
}


//------------------------------------------------------------------------------
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
int a[n];
for (int i = 0; i <n; i++)
{
    cin>>a[i];
}
insertion(a,n);
for (int i = 0; i <n; i++)
{
    cout<<a[i]<<" ";
}

return 0;
}
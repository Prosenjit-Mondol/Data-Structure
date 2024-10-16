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

//Bubble Sort

for (int i = 0; i < n-1; i++)
{
    int ptr=0;
    while (ptr<n-i)
    {
        if (a[ptr]>a[ptr+1])
        {
            swap(a[ptr],a[ptr+1]);
        }
        ptr++;
    }
    
    
}
for(auto element : a)
{
cout<<element<<" ";
}
return 0;
}
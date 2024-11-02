#include<bits/stdc++.h>
using namespace std;

void inserte(int arr[],int& n ,int ele,int pos)
{
    if (pos<0 || pos>n)
    {
        cout<<"Invalid position! "<<'\n';
        return;
    }
    
    for (int i = n; i >pos; i--)
    {
        arr[i]=arr[i-1];
    }
    arr[pos]=ele;
    n++;
}

 int main()
 {
    cout<<"Enter the number of elements: ";

    int n;
    cin>>n;
    int a[10];
    cout<<"Enter the array element: ";
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<"Before inserting: ";
    for(int i=0;i<n;i++)
    {
    cout<<a[i]<<" ";
    }
    cout<<'\n';

    cout<<"Enter the inserting element and position :";
    int x,b;
    cin>>x>>b;

    inserte(a,n,x,b);
    cout << "Array after insertion: ";
    for(int i=0;i<n;i++)
    {
    cout<<a[i]<<" ";
    }
    cout<<'\n';

    return 0;
 }
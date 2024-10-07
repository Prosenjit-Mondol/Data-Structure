// Author  :  PROSENJIT MONDOL

#include <bits/stdc++.h>
using namespace std;
//------------------------------------------------------------------------------
void merge(int a[],int p,int q,int r){
    int nl=q-p+1;
    int nr=r-q;
    int al[nl-1];
    int ar[nr-1];

    for (int i = 0; i < nl; i++)
    {
        al[i]=a[p+i];
    }
    for (int j = 0; j <nr-1; j++)
    {
        ar[j]=a[q+j+1];
    }
    int i=0,j=0,k=p;

    while (i<nl && j<nr)
    {
        if (al[i]<=ar[j])
        {
            a[k]=al[i];
            i++;
        }
        else if (a[k]==ar[j])
        {
            j++;
            k++;
        }
    }
    while (i<nl)
    {
        a[k]=al[i];
        i++;
        k++;
    }
    while (j<nr)
    {
        a[k]=ar[j];
        j++;
        k++;
    }
    
}
void mergesort(int a[],int p, int r)
{
    if (p>=r)
    return;

    int q=(p+r)/2;
    mergesort(a,p,q);
    mergesort(a,q+1,r);

    merge(a,p,q,r);
}

//------------------------------------------------------------------------------
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mergesort(a,0,n-1);
    return 0;
}
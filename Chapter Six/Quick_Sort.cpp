// Author  :  PROSENJIT MONDOL

#include <bits/stdc++.h>
using namespace std;


int partition(int v[], int s, int e)
{
    int pivot = v[s];
    int c = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (v[i] <= pivot)
        {
            c++;
        }
    }

    int pivotI = s + c;

    swap(v[s], v[pivotI]);

    int i = s, j = e;
    
    while (i < pivotI && j > pivotI)
    {
        while (v[i] <= pivot)
        {
            i++;
        }

        while (v[j] > pivot)
        {
            j--;
        }

        if (i < pivotI && j > pivotI)
        {
            swap(v[i++], v[j--]);
        }
    }

    return pivotI;
}


void quickSort(int arr[], int low ,int high)
{
    stack<pair<int,int>> s;
    s.push({low,high});

    while (!s.empty())
    {
        int l=s.top().first;
        int h=s.top().second;

        s.pop();
        int p=partition(arr,low ,high);
         if (p-1>l)
         {
            s.push({l,p-1});
         }
         if (p+1<h)
         {
            s.push({p+1,high});
         }
         
    }
    

}

int main()
{
    int n;
    cin >> n;
    int v[n];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    quickSort(v, 0, n-1);

    for (auto element : v)
    {
        cout << element << " ";
    }

    return 0;
}
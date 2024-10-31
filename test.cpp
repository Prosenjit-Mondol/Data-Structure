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

void quickSort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int p = partition(arr, s, e);

    quickSort(arr, s, p - 1);

    quickSort(arr, p + 1, e);

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
    quickSort(v, 0, n - 1);

    for (auto element : v)
    {
        cout << element << " ";
    }

    return 0;
}
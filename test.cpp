#include <bits/stdc++.h>
using namespace std;

void matrix_multiplication(int matrix_a[][3],int matrix_b[][3],int m,int p,int n)
{
    int c[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j= 0; j<n; j++)
        {
            c[i][j]=0;
            for (int k = 0; k < p; k++)
            {
                c[i][j]+=matrix_a[i][k]*matrix_b[k][j];
            }
            
        }
        
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<'\n';
    }
    
}
int main()
{
    int matrix_a[][3]={{1,-2,3},{0,4,5}};
    int matrix_b[][3]={{3,0,-6},{2,-3,1},{2,5,3}};
    matrix_multiplication(matrix_a,matrix_b,2,3,3);
    return 0;
}
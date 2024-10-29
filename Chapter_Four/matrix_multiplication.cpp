//Author  :  PROSENJIT MONDOL


#include<bits/stdc++.h>
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower);
#define upper(s) transform(s.begin(), s.end(), s.begin(), ::toupper);
using namespace std;
const int inf = 3e5;
using ll=long long ;
ll mod = 1e9 + 7;

//------------------------------------------------------------------------------

void matrixMultiplication(int matrix_a[][3], int matrix_b[][3], int M, int P, int N) {
    int matrix_c[M][N];
    for (int i=0; i < M; i++) {
        for (int j=0; j < N; j++) {
            matrix_c[i][j] = 0;
            for (int k=0; k < P; k++) {
                matrix_c[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }
    for (int i=0; i < M; i++) {
        for (int j=0; j < N; j++) {
            cout << matrix_c[i][j] << " ";
        }
        cout << endl;
    }
}

void solve(void)
{
     int matrix_a[][3] = {{1, -2, 3}, {0, 4, 5}}; // M x P
    int matrix_b[][3] = {{3, 0, -6}, {2, -3, 1}, {2, 5, 3}}; // P x N

    matrixMultiplication(matrix_a, matrix_b, 2, 3, 3);

}


//------------------------------------------------------------------------------
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

  ll t=1;
  //cin>>t;
    while(t--)
     {
       solve();
     }
return 0;
}
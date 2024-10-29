//Author  :  PROSENJIT MONDOL


#include<bits/stdc++.h>
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower);
#define upper(s) transform(s.begin(), s.end(), s.begin(), ::toupper);
using namespace std;
const int inf = 3e5;
using ll=long long ;
ll mod = 1e9 + 7;

//------------------------------------------------------------------------------

void LargestElementInArray(int DATA[], int N)
{
    int K = 0, LOC = 0, MAX = DATA[0];
increment_counter:
    K = K + 1;
    if (K == N)
    {
        cout << "LOC = " << LOC << ", MAX = " << MAX << "\n";
        return;
    }
    if (MAX < DATA[K])
    {
        LOC = K;
        MAX = DATA[K];
    }
    goto increment_counter;
}

void solve(void)
{
    int DATA[] = {3, 5, 9, 2};
    int N = sizeof(DATA) / sizeof(int);
    LargestElementInArray(DATA, N);
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
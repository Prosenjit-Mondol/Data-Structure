//Author  :  PROSENJIT MONDOL


#include<bits/stdc++.h>
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower);
#define upper(s) transform(s.begin(), s.end(), s.begin(), ::toupper);
using namespace std;
const int inf = 3e5;
using ll=long long ;
ll mod = 1e9 + 7;

//------------------------------------------------------------------------------

void traverse_1(int arr[], int lower_bound, int upper_bound) {
    int temp = lower_bound;
    while (temp <= upper_bound) {
        cout << arr[temp] << " ";
        temp++;
    }
    cout << endl;
}

void traverse_2(int arr[], int lower_bound, int upper_bound) {
    for (int i = lower_bound; i <= upper_bound; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void solve(void)
{
    int arr[5] = {1, 2, 3, 4, 5};
    traverse_1(arr, 0, 4);
    traverse_2(arr, 0, 4);
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
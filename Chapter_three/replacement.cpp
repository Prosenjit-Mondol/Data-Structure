//Author  :  PROSENJIT MONDOL


#include<bits/stdc++.h>
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower);
#define upper(s) transform(s.begin(), s.end(), s.begin(), ::toupper);
using namespace std;
const int inf = 3e5;
using ll=long long ;
ll mod = 1e9 + 7;

//------------------------------------------------------------------------------

void solve(void)
{
    string str = "To be or not 2B, that is the ? that is 2B decided for future!";
    string pattern = "2B";
    string placeholder = "to be";

    int index = str.find(pattern);
    while (index != -1)
    {
        str.replace(index, pattern.length(), placeholder);
        index = str.find(pattern);
    }

    cout << str << endl; 
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
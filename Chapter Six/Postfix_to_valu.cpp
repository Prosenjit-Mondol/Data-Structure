#include<bits/stdc++.h>
using namespace std;

void posttovalue(string s)
{
    stack<int> sp;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]==' ')
        {
            continue;
        }
        else if (s[i] >= 48 && s[i] <= 57)
        {
            string a;
            a.push_back(s[i]);
            while (s[i + 1] >= 48 && s[i + 1] <= 57)
            {
                a.push_back(s[i + 1]);
                i++;
            }
            int x=stoi(a);
            sp.push(x);
        }
        
        else
        {
            int f=sp.top();
            sp.pop();
            int l=sp.top();
            sp.pop();
            int r;
            if (s[i]=='+')
            {
                r=l+f;
            }
            if (s[i]=='-')
            {
                r=l-f;
            }
            if (s[i]=='*')
            {
                r=l*f;
            }
            if (s[i]=='/')
            {
                r=l/f;
            }
            sp.push(r);
        }
        //cout<<sp.top()<<" ";
    }
    cout<<sp.top()<<'\n';
}

int main(){
    string s;
    getline(cin, s);
    posttovalue(s);
}
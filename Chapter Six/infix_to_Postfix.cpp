// Author  :  PROSENJIT MONDOL

#include <bits/stdc++.h>
using namespace std;

//------------------------------------------------------------------------------

string postfix(string s)
{
    stack<char> st;
    string p;
    st.push('(');
    s.push_back(')');
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            p.push_back(' ');
        }
        else
        {
            if (s[i] >= 48 && s[i] <= 57)
            {
                p.push_back(s[i]);
                while (s[i + 1] >= 48 && s[i + 1] <= 57)
                {
                    p.push_back(s[i + 1]);
                    i++;
                }
            }
            else if (s[i] == '(')
            {
                st.push('(');
            }
            else if (s[i] == ')')
            {
                while (st.top() != '(')
                {
                    p.push_back(st.top());
                    p.push_back(' ');
                    st.pop();
                }
                st.pop();
            }
            else
            {
                if (st.top() == '(' || s[i] == '^')
                {
                    st.push(s[i]);
                }
                else if (s[i] == '+' || s[i] == '-')
                {
                    p.push_back(st.top());
                    st.pop();
                    st.push(s[i]);
                }
                else
                {
                    if (st.top() == '+' || st.top() == '-')
                    {
                        st.push(s[i]);
                    }
                    else if (st.top() == '^' || st.top() == '*' || st.top() == '/')
                    {
                        p.push_back(st.top());
                        st.pop();
                        st.push(s[i]);
                    }
                }
            }
        }
    }
    return p;
}

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
        
    }
    cout<<sp.top()<<'\n';
}
//------------------------------------------------------------------------------
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin, s);
    string p = postfix(s);
    cout << p << "\n";
    posttovalue(p);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;


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


int main()
{

    string s;

    getline(cin, s);

    string p = postfix(s);

    cout << p << "\n";

    return 0;
}
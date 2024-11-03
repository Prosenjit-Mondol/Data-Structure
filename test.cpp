#include <bits/stdc++.h>
using namespace std;

string infix(string s)
{
    string p;
    s.push_back(')');
    stack<char> st;
    st.push('(');

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
            continue;
        else if (s[i] == '(')
            st.push('(');
        else if (isdigit(s[i]))
        {
            p.push_back(s[i]);
            while (isdigit(s[i + 1]))
            {
                i++;
                p.push_back(s[i]);
            }
            p.push_back(' ');
        }
        else if (s[i] == ')')
        {
            while (st.top() != '(')
            {
                p.push_back(st.top());
                st.pop();
                p.push_back(' ');
            }
            st.pop();
        }
        else
        {
            if (st.top() == '(' || s[i] == '^')
                st.push(s[i]);
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
    return p;
}
void postfix(string s)
{
    stack<int> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
            continue;
        if (isdigit(s[i]))
        {
            string d;
            d.push_back(s[i]);
            while (isdigit(s[i + 1]))
            {
                i++;
                d.push_back(s[i]);
            }
            st.push(stoi(d));
        }
        else
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            int r = 0;
            if (s[i] == '+')
                r = a + b;
            if (s[i] == '-')
                r = a - b;
            if (s[i] == '*')
                r = a * b;
            if (s[i] == '/')
                r = a / b;
            st.push(r);
        }
    }
    cout << st.top() << '\n';
}
int main()
{
    cout << "Enter a infix expression: ";
    string s;
    getline(cin, s);
    string p = infix(s);
    cout<<p<<'\n';
    postfix(p);
}
#include <bits/stdc++.h>
using namespace std;

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}
bool hasHigherPrecedence(char top, char current)
{
    if (precedence(top) > precedence(current))
        return true;
    if (precedence(top) == precedence(current) && current != '^')
        return true; // left associative
    return false;
}
string intopost(string s)
{
    string p;
    stack<char> st;
    s.push_back(')');
    st.push('(');

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
            continue;
        if (isdigit(s[i]))
        {
            p.push_back(s[i]);
            while (isdigit(s[i + 1]))
            {
                i++;
                p.push_back(s[i]);
            }
            p.push_back(' ');
        }
        else if (s[i] == '(')
        {
            st.push('(');
        }
        else if (s[i] == ')')
        {
            while (st.top() == '(')
            {
                p.push_back(st.top());
                p.push_back(' ');
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (st.top() != '(' && hasHigherPrecedence(st.top(), s[i]))
            {
                p.push_back(st.top());
                p.push_back(' ');
                st.pop();
            }
            st.push(s[i]);
        }
    }
    return p;
}

void posttovalue(string s)
{
    stack<int> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
            continue;
        if (isdigit(s[i]))
        {
            string num;
            num.push_back(s[i]);
            while (isdigit(s[i + 1]))
            {
                i++;
                num.push_back(s[i]);
            }
            st.push(stoi(num));
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
            if (s[i] == '^')
                r = pow(a, b);

            st.push(r);
        }
    }
    cout << st.top() << '\n';
}
int main()
{
    cout << "Enter the expression: ";
    string s;
    getline(cin, s);

    string p = intopost(s);
    cout << "The postfix expression is : " << p << '\n';

    cout << "The value of this expression is : ";
    posttovalue(p);

    return 0;
}
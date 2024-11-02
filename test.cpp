#include <bits/stdc++.h>
using namespace std;

int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

bool hasHigherPrecedence(char top, char current) {
    if (precedence(top) > precedence(current))
        return true;
    if (precedence(top) == precedence(current) && current != '^')
        return true; // left associative
    return false;
}

string intopost(string s) {
    string p;
    stack<char> st;
    s.push_back(')');  // Adding closing parenthesis at the end
    st.push('(');  // Starting with an opening parenthesis

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ')
            continue;

        if (isdigit(s[i])) {
            p.push_back(s[i]);
            while (i + 1 < s.size() && isdigit(s[i + 1])) {
                i++;
                p.push_back(s[i]);
            }
            p.push_back(' ');
        }
        else if (s[i] == '(') {
            st.push('(');
        }
        else if (s[i] == ')') {
            while (st.top() != '(') {
                p.push_back(st.top());
                p.push_back(' ');
                st.pop();
            }
            st.pop();  // Remove the '(' from the stack
        }
        else {
            while (st.top() != '(' && hasHigherPrecedence(st.top(), s[i])) {
                p.push_back(st.top());
                p.push_back(' ');
                st.pop();
            }
            st.push(s[i]);
        }
    }

    return p;
}

void posttovalue(string s) {
    stack<int> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ')
            continue;

        if (isdigit(s[i])) {
            string num;
            while (i < s.size() && isdigit(s[i])) {
                num.push_back(s[i]);
                i++;
            }
            i--;  // Adjust i because of the last increment in the loop
            st.push(stoi(num));
        }
        else {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            int r = 0;
            if (s[i] == '+')
                r = a + b;
            else if (s[i] == '-')
                r = a - b;
            else if (s[i] == '*')
                r = a * b;
            else if (s[i] == '/')
                r = a / b;
            else if (s[i] == '^')
                r = pow(a, b);

            st.push(r);
        }
    }
    cout << st.top() << '\n';
}

int main() {
    cout << "Enter the expression: ";
    string s;
    getline(cin, s);

    string p = intopost(s);
    cout << "The postfix expression is : " << p << '\n';

    cout << "The value of this expression is : ";
    posttovalue(p);

    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// // Function to convert infix expression to postfix
// string postfix(string s) {
//     stack<char> st;
//     string p;
//     st.push('(');
//     s.push_back(')');
    
//     for (int i = 0; i < s.size(); i++) {
//         if (s[i] == ' ') continue;
        
//         if (isdigit(s[i])) {
//             p.push_back(s[i]);
//             while (i + 1 < s.size() && isdigit(s[i + 1])) {
//                 i++;
//                 p.push_back(s[i]);
//             }
//             p.push_back(' ');  // Space to separate numbers in postfix
//         }
//         else if (s[i] == '(') {
//             st.push('(');
//         }
//         else if (s[i] == ')') {
//             while (st.top() != '(') {
//                 p.push_back(st.top());
//                 p.push_back(' ');
//                 st.pop();
//             }
//             st.pop();
//         }
//         else {
//             // Operator precedence and associativity handling
//             while (st.top() != '(' && 
//                   ((s[i] == '+' || s[i] == '-') && (st.top() == '*' || st.top() == '/' || st.top() == '^')) ||
//                   ((s[i] == '*' || s[i] == '/') && (st.top() == '^' || st.top() == '*' || st.top() == '/')) ||
//                   ((s[i] == '^') && (st.top() == '^'))) {
//                 p.push_back(st.top());
//                 p.push_back(' ');
//                 st.pop();
//             }
//             st.push(s[i]);
//         }
//     }
//     return p;
// }

// // Function to evaluate postfix expression
// void posttovalue(string s) {
//     stack<int> sp;
    
//     for (int i = 0; i < s.size(); i++) {
//         if (s[i] == ' ') continue;
        
//         if (isdigit(s[i])) {
//             string num;
//             num.push_back(s[i]);
//             while (i + 1 < s.size() && isdigit(s[i + 1])) {
//                 i++;
//                 num.push_back(s[i]);
//             }
//             sp.push(stoi(num));
//         }
//         else {
//             int b = sp.top(); sp.pop();
//             int a = sp.top(); sp.pop();
//             int result = 0;
            
//             if (s[i] == '+') result = a + b;
//             if (s[i] == '-') result = a - b;
//             if (s[i] == '*') result = a * b;
//             if (s[i] == '/') result = a / b;
//             if (s[i] == '^') result = pow(a, b);  // Handle exponentiation

//             sp.push(result);
//         }
//     }
//     cout << "Result: " << sp.top() << '\n';
// }

// // Main function
// int main() {
//     cout << "Enter the expression: ";

//     string s;
    
//     getline(cin, s);

//     string p = postfix(s);
//     cout << "Postfix expression: " << p << "\n";
//     posttovalue(p);

//     return 0;
// }
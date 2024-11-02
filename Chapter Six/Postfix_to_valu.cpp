#include<bits/stdc++.h>
using namespace std;

void posttovalue(string s) {
    stack<int> sp;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') continue;
        
        if (isdigit(s[i])) {
            string num;
            num.push_back(s[i]);
            while (isdigit(s[i + 1])) {
                i++;
                num.push_back(s[i]);
            }
            sp.push(stoi(num));
        }
        else {
            int b = sp.top(); sp.pop();
            int a = sp.top(); sp.pop();
            int result = 0;
            
            if (s[i] == '+') result = a + b;
            if (s[i] == '-') result = a - b;
            if (s[i] == '*') result = a * b;
            if (s[i] == '/') result = a / b;
            if (s[i] == '^') result = pow(a, b);  // Handle exponentiation

            sp.push(result);
        }
    }
    cout << "Result: " << sp.top() << '\n';
}

int main(){

    cout<<"Enter the expression: ";

    string s;

    getline(cin, s);

    posttovalue(s);

    return 0;
}
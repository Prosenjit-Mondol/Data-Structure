#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    for (int i = 0; i < 5; i++)
    {
        int a;
        cin>>a;
        q.push(a);
    }
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data ;
    node* next;
    node(int val) : data(val), next(nullptr){}
};
node* head=nullptr;

void insertstart(int val)
{
    node* newnode=new node(val);
    newnode->next =head;
    head=newnode;
}
void display()
{
    for (node* i = head; i; i=i->next)
    {
        cout<<i->data<<(i->next ? "-> " : "\n");
    }
    
}
int main()
{
    cout<<"Enter the number of data : ";
    int n;
    cin>>n;
    cout<<"Enter the data:\n";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        insertstart(x);
    }
    
    display();

    return 0;
}
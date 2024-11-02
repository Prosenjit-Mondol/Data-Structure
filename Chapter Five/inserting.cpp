#include<bits/stdc++.h>
using namespace std;

struct node
{
    string data;
    node* next;
    node(string val) : data(val),next(nullptr) {}
};
node* head=nullptr;

void display(){
    for (node* i = head; i: i=i->next)
    {
        cout<<i->data<<(i->next ? " -> ": "\n");
    }
    
}
void insertstart(string val)
{
    node* newnode=new node(val);
    newnode->next= head;
    head=newnode;
}
void insertend(string val)
{
    node* newnode=new node(val);
    
}
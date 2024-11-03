#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* next;
    node(int val) : data(val),next(nullptr){}
};
node* head=nullptr;
void insertend(int val)
{
    node* newnode=new node(val);
    if (!head)
    {
        head=newnode;
        return;
    }
    node* temp=head;
    while (temp->next)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}
void insertfirst(int val)
{
    node* newnode=new node(val);
    newnode->next=head;
    head=newnode;
}
void insertnth(int val,int pos)
{
    node* newnode=new node(val);
    node* temp=head;
    for (int i = 1; i < pos && temp; i++)
    {
        temp=temp->next;
    }
    if (temp)
    {
        newnode->next=temp->next->next;
        temp->next=newnode;
    }
    
}
void display()
{
    for (node* i = head; i; i=i->next)
    {
        cout<<i->data<<(i->next ? "->" : "\n");
    }
    cout<<'\n';
}
void finding_n(int val)
{
    for (node* i = head; i ; i=i->next)
    {
        if (i->data==val)
        {
            cout<<"The node is finding "<<'\n';
            return;
        }
        
    }
    cout<<"The node is not found."<<'\n';
}
void deletfirst()
{
    node* temp=head;
    head=temp->next;
    delete temp;
}
void deletlast(){
    node* temp=head;
    while (temp->next->next)
    {
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
}
void deletnth(int p)
{
    if (p==1)
    {
        deletfirst();
        return;
    }
    node* temp=head;
    for (int i = 1; i < p-1 && temp; i++)
    {
        node* todel=temp->next;
        temp->next=temp->next->next;
        delete todel;
    }
    
}
int main()
{
    cout<<"Enter the number of node: ";
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        insertend(a);
    }
    display();
    cout<<"Enter the data for inserting in the first: ";
    int x;
    cin>>x;
    insertfirst(x);
    display();
    cout<<"Enter the data for inserting in the nth: ";
    cin>>x;
    cout<<"Enter the position: ";
    int pos;
    cin>>pos;
    insertnth(x,pos-1);
    display();
    cout<<"Enter node for finding: ";
    int f;
    cin>>f;
    finding_n(f);
    cout<<"After deletinf the first node: ";
    deletfirst();
    display();
    cout<<"Deleting the last node: ";
    deletlast();
    display();
    cout<<"Enter the position for deleting node: ";
    cin>>f;
    deletnth(f);
    display();

}
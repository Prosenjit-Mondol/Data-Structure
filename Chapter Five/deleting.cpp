#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* next;
    node(int val) : data(val), next(nullptr){}
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

void display()
{
    for (node* i = head; i;i=i->next)
    {
        cout<<i->data<<(i->next ? " -> " : "\n");
    }
    
}
void deletestart()
{
    if (head)
    {
        node* temp=head;
        head=head->next;
        delete temp;
    }
}
void deleteend()
{
    if (!head)return;
    if (!head->next)
    {
        delete head;
        head=nullptr;
        return;
    }
    node* tem=head;
    while (tem->next)
    {
        tem=tem->next;
    }
    delete tem->next;
    tem->next=nullptr;
    
}
int main()

{
    cout<<"Enter the number of data: ";
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        insertend(a);
    }
    display();
    cout<<"Delete after First node: ";
    deletestart();
    display();
    cout<<"Delete after Last node: ";
    deleteend();
    display();

    return 0;
}
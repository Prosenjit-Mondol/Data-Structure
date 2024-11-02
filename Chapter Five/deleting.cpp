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
    node* temp=head;
    while (temp->next->next)
    {
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    
}
void deletenth(int pos){
    if (pos==1)
    {
        deletestart();
        return;
    }
    node* temp=head;
    for (int  i = 0; i <pos && temp ; i++)
    {
        temp=temp->next;
    }
    if (temp && temp->next)
    {
        node* todelete=temp->next;
        temp->next=temp->next->next;
        delete todelete;
    }
    
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
    cout<<"Enter the position of the deleting node: ";
    int x;
    cin>>x;
    deletenth(x);
    display();


    return 0;
}
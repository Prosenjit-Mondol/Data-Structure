#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* next;
    node(int val): data(val),next(nullptr){}
};
node* head=nullptr;
void display()
{
    for (node* i = head; i; i=i->next)
    {
        cout<<i->data<<(i->next ? " -> " : '\n');
    }    
}
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
int main()
{
    cout<<"Enter the number of data: ";
    int n;
    cin>>n;
    for (int i = 0; i <n; i++)
    {
        int a;
        cin>>a;
        insertend(a);
    }
    display();

    cout<<"Enter a data for adding last: ";
    int x;
    cin>>x;
    insertend(x);
    display();

    coutt<<"Enter the data for adding first: ";
    cin>>x;
    insertfirst(x);
    display();

    cout<<"Enter the data for adding Nth position :";
    cin>>x;
    cout<<"Enter the position: ";
    int p;
    cin>>p;
    insertnth(x,p);
    display();

}
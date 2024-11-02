#include<bits/stdc++.h>
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
node* find(int val)
{
    node* temp=head;
    while (temp)
    {
        if (temp->data==val)
        {
            return temp;
        }
        temp=temp->next;
    }
    return nullptr;
}
void display()
{
    node* temp=head;
    while (temp)
    {
        cout<<temp->data<<(temp->next ? " -> " : "\n");
        temp=temp->next;
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
    cout<<"Enter the finding node : ";
    int x;
    cin>>x;
    node* p=find(x);
    if (p)
    {
        cout << "Node with value " << x << " found in the list.\n";
    }
    else
    {
        cout << "Node with value " << p << " not found in the list.\n";
    }
    


    return 0;
}
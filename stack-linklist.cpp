#include<iostream>
using namespace std;
class node
{
    public:
        int data;
        node *previous;
        node(int val)
        {
            data=val;
            previous=NULL;
        }
};
class stack
{
    private:
        node *top;
    public:
    stack()
    {
        top=NULL;
    }
    void push(int val);
    void pop();
};
void stack::push(int val)
{
    if(top==NULL)
    {
        node *temp=new node(val);
        top=temp;
        temp=NULL;
    }
    else
    {
        node *temp=new node(val);
        temp->previous=top;
        top=temp;
        temp=NULL;
    }
    
}
void stack::pop()
{
    if(top==NULL)
    {
        cout<<"Underflow";
    }
    else
    {
        cout<<top->data<<endl;
        node *temp;
        temp=top;
        top=top->previous;
        temp->previous=NULL;
        delete temp;
    }
    
}
int main(void)
{
    stack l1;
    l1.push(1);
    l1.push(2);
    l1.push(3);
    l1.push(9);
    l1.push(10);
    l1.push(11);
    l1.pop();
    l1.pop();
    l1.pop();
    l1.pop();
    l1.pop();
    return 0;
}

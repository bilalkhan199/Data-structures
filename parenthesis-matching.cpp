#include<iostream>
using namespace std;
class Node
{
    public:
        int v;
        Node *prev;
        Node(int value)
        {
            v=value;
            prev=NULL;
        }
};
class Stack
{
      public:
        Node *in;
    Stack()
    {
        in=NULL;
    }
    void push(int value);
    void match_bracket(string x);
    char pop();
};
void Stack::push(int value)
{
    if(in==NULL)
    {
        Node *temp=new Node(value);
        in=temp;
        temp=NULL;
    }
    else
    {
        Node *temp=new Node(value);
        temp->prev=in;
        in=temp;
        temp=NULL;
    }
}
char Stack::pop()
{
    int x;
    if(in==NULL)
    {
        return 0;
    }
        Node *temp;
        temp=in;
        x=in->v;
        in=in->prev;
        temp->prev=NULL;
        delete temp;
        return x;
}
void Stack::match_bracket(string x)
{
    int y=x.length();
    int i=0,k;
    for(i;i<y;i++)
    {
        if(in==NULL and x[i]==')')
        {
            k=i;
            cout<<"No left bracket"<<endl;
        }
        else if(x[i]=='(')
        {
            push(i);
        }
        else if(x[i]==')')
        {
            int x;
            x=pop();
            cout<<"left bracket at position "<<i<<endl;
        }
    }
    if(in==NULL and x[k]!=')')
    {
        cout<<"Done"<<endl;
    }
    if(i==y and in!=NULL)
{

        if(in!=NULL or i==y)
        {
            int k=0;
            while(in!=NULL)
            {
                k=pop();
            if(x[k]=='(')
            {
                cout<<"No right bracket"<<endl;   
            }
            else
            {
                cout<<"No left brackets";
            }
            }       
        }
}
    
}
int main(void)
{
    Stack s;
    s.match_bracket("(q1)");
}

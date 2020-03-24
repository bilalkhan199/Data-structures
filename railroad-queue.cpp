#include<iostream>
using namespace std;
int len=0;
const int size=9;
int in[size]={5,8,1,7,4,2,9,6,3};
int out[size]={0,0,0,0,0,0,0,0,0};
class node
{
    public:
        int data;
        node *next;
        node(int val)
        {
            data=val;
            next=NULL;
        }
};
class Queue
{
    private:
        int length;
        node *front;
        node *rear;
    public:
    Queue()
    {
        length=0;
        front=NULL;
        rear=NULL;
    }
    void in_que(int val);
    int de_que();
    int peak();
    int ft();
    bool is_empty();
    bool is_full();
};
bool Queue::is_full()
{
    if(length==3)
    {
        return true;
    }
    return false;
}
int Queue::ft()
{
    if(front==NULL)
    {
        return 0;
    }
    return front->data;
}
bool Queue::is_empty()
{
    if(front==NULL)
    {
        return true;
    }
    return false;
}
int Queue::peak()
{
    int x;
    x=rear->data;
    return x;
}
void Queue::in_que(int val)
{
    node *temp;
    if(front==NULL)
    {
        node *n=new node(val);
        front=n;
        rear=n;
        length++;
    }
    else
    {
    node *n=new node(val);
    temp=rear;
    temp->next=n;
    rear=n;
    length++;
    }
}
int Queue::de_que()
{
    node *temp;
    int x;
    temp=front;
    front=front->next;
    temp->next=NULL;
    x=temp->data;
    delete temp;
    return x;
}
Queue H1,H2,H3;
void arrange();
void output();
int main(void)
{
    arrange();
    return 0;
}
void output()
{
    for(int i=0;i<9;i++)
    {
        cout<<out[i]<<" ";
    }
}
void arrange()
{
    int turn=1;
    int i=8;
    int p=0;
    len=0;
    while(len!=9)
    {
        if(H3.is_empty()==0)
        {
            cout<<"This can not be handle by this technique .";
            break;
        }
        else if(turn==in[i])
        {
            out[p]=in[i];
            p++;
            i--;
            len++;
            turn++;
        }
        else if(turn==H1.ft())
        {
            out[p]=H1.de_que();
            p++;
            len++;
            turn++;
        }
        else if(turn==H2.ft())
        {
            out[p]=H2.de_que();
            p++;
            len++;
            
            turn++;
        }
        else if(H1.is_empty()==1)
        {
            H1.in_que(in[i]);
            i--;
        }
        else if(H1.is_empty()==0 and H1.is_full()==0)
        {
            if(H1.peak()<in[i])
            {
                H1.in_que(in[i]);
                i--;
            }
            else
            {
                H2.in_que(in[i]);
                i--;
            }
            
        }
         else if(H1.is_full()==1 and H2.is_empty()==1)  
        {
            H2.in_que(in[i]);
            i--;
        }
        else if(H2.is_empty()==0)
        {
            if(H2.peak()<in[i])
            {
                H2.in_que(in[i]);
                i--;
            }
            else
            {
                H3.in_que(in[i]);
                i--;
            }
            
        }
    }
    if(out[0]==1 and out[size-1]==9)
    {
        output();
    }
    
    
}

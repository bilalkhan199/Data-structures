#include<iostream>
using namespace std;
int length=0;
const int size=9;
const int z=3;
int a[size]={5,8,1,2,4,7,9,6,3};
int b[size]={0,0,0,0,0,0,0,0,0};
class Stack{
public:
        int s[z];
        int start;
        Stack()
        {
            start=-1;
        }
        void push(int x);
        int pop();
        int peak();
        bool is_full();
        bool is_empty();
};
int Stack::peak()
{
    return s[start];
}
bool Stack::is_empty()
{
    if(start==-1)
    {
        return true;
    }
    return false;
}
bool Stack::is_full()
{
    if(start==z)
    {
        return true;
    }
    return false;
}
void Stack::push(int x)
{
    if(!is_full())
    {
        start++;
        s[start]=x;
    }
}
int Stack::pop()
{
    if(is_empty()==0)
    {
        return s[start--];
    }
    else
    {
        return -1;
    }
    
}
void print()
{
    for(int i=0;i<size;i++)
    {
        cout<<b[i]<<" ";
    }
}
Stack H1,H2,H3;
void shuffle()
{
    int turn=1;
    int i=8;
    int p=0;
    length=0;
    while(length!=9)
    {
        if( i>=0 and turn==a[i])
        {
            b[p]=a[i];
            p++;
            length++;
            turn++;
            i--;
        }
        else if(turn==H1.peak())
        {
            int g=H1.pop();
            b[p]=g;
            p++;
            length++;
            turn++;
        }
        else if(turn==H2.peak())
        {
            int g=H2.pop();
            b[p]=g;
            p++;
            length++;
            turn++;
        }
        else if(turn==H3.peak())
        {
        int g=H3.pop();
            b[p]=g;
            p++;
            length++;
            turn++;
        }
        else if(H1.is_empty()==1)
        {
            H1.push(a[i]);
            i--;
        }
        else if(H2.is_empty()==1)
        {
            H2.push(a[i]);
            i--;
        }
        else if(H3.is_empty()==1)
        {
            H3.push(a[i]);
            i--;
        }
        else if(H1.is_empty()==0 and H2.is_empty()==0 and H3.is_empty()==0)
        {
            int x=H1.peak()-a[i];
            int y=H2.peak()-a[i];
            int z=H3.peak()-a[i];
            if(x>0 and x<y  and x<z)
            {
                H1.push(a[i]);
                i--;
            }
            else if(y>0 and y<z)
            {
                H2.push(a[i]);
                i--;
            }
            else if(z>0)
            {
                H3.push(a[i]);
                i--;
            }
            else
            {
                cout<<"Unable to solve this hierachy,change the values";
                break;
            }
        }
    }
    if (b[0]==1 and b[size-1]==9)
    {
         print();
    }
}

int main()
{
    shuffle();
}

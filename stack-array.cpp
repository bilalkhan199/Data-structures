#include<iostream>
using namespace std;
const int size=5;
class Stack
{
    private:
        int *arr;
        int *top;
        int len;
    public:
        Stack()
        {
            arr=new int[size];
            top=NULL;
            len=0;
        }
    bool is_full();
    bool is_empty();
    void push(int val);
    int pop();
        
};
bool Stack::is_empty()
{
    if(top==NULL)
    {
        return true;
    }
    return false;

}
bool Stack::is_full()
{
    if(top==arr+(size-1))
    {
        return true;
    }
    return false;
}
void Stack::push(int val)
{
    if(is_full()==0)
    {
        if(top==NULL)
        {
        top=arr;
        *top=val;
        len++;
        }
        else
        {
            top++;
            *top=val;
            len++;
        }
        
    }
    else
    {
        cout<<"Overflow ";
    }
    
}
int Stack::pop()
{
    int *temp;
    temp=top;
    if(is_empty()==0)
    {
        top--;
        return *temp;
    }
    else
    {
        cout<<"Underflow";
        return 0;
    }
    
}
int main(void)
{
    Stack l1;
    l1.push(1);
    l1.push(2);
    l1.push(3);
    l1.push(4);
    l1.push(5);
    l1.push(5);
    //l1.push(6);
    cout<<l1.pop();
    cout<<l1.pop();
    cout<<l1.pop();
    cout<<l1.pop();
    cout<<l1.pop();
    return 0;
}

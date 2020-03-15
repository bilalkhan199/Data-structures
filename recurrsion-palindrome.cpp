#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

bool palindrome(string q,char *ptr1,char *ptr2,int y)
{
    if(*ptr1==*ptr2)
    {
        if(y==0)
        {
        	cout<<"palindrome"<<endl;
            return true;
        }
        y--;
        ptr1++;
        ptr2--;
        return palindrome(q,ptr1,ptr2,y);
    }
    else if(*ptr1!=*ptr2)
    {
    	cout<<"Sorry,not palindrome"<<endl;
        return false;
    }
}
int main(void)
{
    char *ptr1,*ptr2;
    string q="anna";
    int y=q.length()/2;
    ptr1=&q[0];
    ptr2=ptr1+q.length()-1;
    cout<<palindrome(q,ptr1,ptr2,y)<<endl;
    return 0;
}

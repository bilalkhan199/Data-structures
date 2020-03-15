// replace a[0] by a[1]*a[2] , a[1] by a[2]*a[0] , a[2] by a[0][1]

#include<iostream>
using namespace std;
int x=1;
int array[3]={1,2,3};   //answer= [3*2 , 6*3 , 6*18] 

int replace_fun(int *ptr1,int *ptr2,int q);
int replace_fun(int *ptr1,int *ptr2,int y,int x);

int main()
{
    int *ptr,*ptr1;
    ptr=array;
    ptr1=(array+3)-1;
    replace_fun(ptr,ptr1,3);
    for(int i=0;i<3;i++)
    {
        cout<<array[i]<<endl;
    }
}

int replace_fun(int *ptr1,int *ptr2,int y,int x)
{
    int q=0;
     if(ptr1==ptr2 and ptr2==(array+2))
        {
            ptr2--;
        }
    if(y==0)
    {
        return true;
    }
    else
    {
        *ptr1=*ptr2*x;
        q=*ptr1;
        ptr2--;
        y--;
        if(ptr2==array-1)
        {
            //cout<<"here";
            return true;
        }
        else if(ptr1==ptr2 and ptr1==array)
        {
            //cout<<"true"<<endl;
            return true;
        }
        else if(ptr1==ptr2 and ptr1!=array)
        {
            //cout<<ptr2--;
            ptr2--;
            return replace_fun(ptr1,ptr2,y,q);
        }
        return replace_fun(ptr1,ptr2,y,q);
    }
}

int replace_fun(int *ptr1,int *ptr2,int q)
{
    if(q==0)
    {
        return true;
    }
    replace_fun(ptr1,ptr2,3,x);
    ptr1++;
    ptr2=(array+3)-1;
    q--;
    return replace_fun(ptr1,ptr2,q);
}

#include<iostream>
using namespace std;

class Heap{
    public:
    int h[9];
    int n,maxsize;
    Heap()
    {
        n=0;
        maxsize=8;
        h[0]=-1;
    }

    void insert(int x)
    {
        if (n==maxsize)
        {
        //    cout<<"heap is full";
            return;
        }
            n++;
        //cout<<"n: "<<n<<endl;
        int k;
        for (k=n;k>1;k=k/2)
        {
            if (x>h[k/2])
            {
               // cout<<"No shifting required";
                break;
            }
            h[k]=h[k/2];
        }

        h[k]=x;

    }

    void deleteheap()
    {
        if (n==0)
        {
            cout<<"heap is empty";
            return;
        }
        int last=h[n];
        int x=h[1];
        n--;

        cout<<"last-"<<last<<" "<<n<<endl;

        int i,j;  //j smallest child , i =parent
        for (i=1,j=2 ; j<=n ; i=j,j*=2){
            
           //cout<<"j-"<<j<<" "<<n<<endl;
            if (j<n){
                cout<<"here: "<<h[j]<<h[j+1]<<endl;
                if (h[j]>h[j+1])
                {
                     j++;
                     cout<<"changed-"<<h[j]<<" "<<h[j+1]<<endl;
                }
            }

            if (last<=h[j])
            {
                break;
            }
            h[i]=h[j];
        }
        h[i]= last;
        h[j+1]=-1;

    }

   

    void print()
    {
        for (int i=0;i<8;i++)
        {
            cout<<h[i]<<" ";
        }
    }
};


int main()
{
    Heap h;
    h.insert(10);
    h.insert(20);
    h.insert(12);
    h.insert(40);
    h.insert(100);
    h.insert(50);
    h.insert(30);
    h.print();
    cout<<endl<<endl;
    h.deleteheap();
    h.print();


}

#include<iostream>
using namespace std;

int factorial(int a)
{
	if (a==1)
	{
		return 1; 
	}

	return (a*factorial(a-1));
}
int main()
{
	cout<<"factorial: "<<factorial(4)<<" "<<endl;
}

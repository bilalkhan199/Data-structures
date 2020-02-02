#include<iostream>
using namespace std;

struct node{
	int value;
	node *nextnode;
};

node *create_node(node *current,int new_value)
{
	node *n;
	n=new node;
	n->value=new_value;
	n->nextnode=NULL;
	
	current->nextnode=n;
	return n;
}
void outputlist(node *current)
{
	cout<<"[";
	while(current!=NULL)
	{cout<<current->value<<" ";
	current=current->nextnode;}
	cout<<"]";
	
}

void search(node *current)
{
	int no,flag=0;
	cout<<"Enter the no:";
	cin>>no;

	while (current->nextnode!=NULL)
	{
		current=current->nextnode;
		if (current->value==no){
		cout<<"found";
		flag=1;}

	}
	if (flag==0)
		cout<<"not found";



}
int main()
{
	node *head;
	head=new node;
	head->value=10;
	head->nextnode=NULL;

	node *current=head;
	current=create_node(current,11);
	current=create_node(current,12);
	current=create_node(current,13);
	current=create_node(current,14);
	
	current=head;
	outputlist(current);

	current=head;
	search(current);
	

}

#include<iostream>
using namespace std;

class node{
public:
	int val;      //"info"
	node *next;
	node *previous;
};

class List{
	public:
	node *head=NULL;
	node *current=NULL;
	node *temp=NULL;

	void insert()
	{
		if (head == NULL)
		{
			cout<<"list was empty"<<endl;
			head=new node;
			cout<<"Enter the value: ";
			cin>>head->val;
			head->next=NULL;
			head->previous=NULL;
			current=head;
			return;
		}
		while (current->next!=NULL)
		{
			current=current->next;
		}
			temp=new node;
			cout<<"enter new value";
			cin>>temp->val;
			temp->next=NULL;

			current->next=temp;
			temp->previous=current;
			return;

	}
	void print()
	{
		temp=head;
		while(temp!=NULL)
		{
			cout<<temp->val<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}

};


int main()
{
	List l;
	l.insert();
	l.insert();	
	l.insert();	
	//l.insert();	
	//l.insert();	
	l.print();
}

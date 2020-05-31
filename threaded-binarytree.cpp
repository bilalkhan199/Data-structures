#include<iostream>
using namespace std;

struct node{
	int info;
	node *left;
	node *right;
	int left_thread;
	int right_thread;
};

class thread{
	private:
		node *temp , *ptr ,*temp1, *dummy , *current , *temp2;
	public:
		node *root;
		int key , number , swap;
		thread()
		{
			temp1 = temp = ptr = root = current = temp2= NULL;
			key = 0;
			number = 0;
			swap = 0;
			dummy = new node;
			dummy->right = dummy;
			dummy->left = dummy;
			temp = root;
		}
		~thread(){
			delete root;
			delete temp;
		}
		
	void insert(node *temp){
		temp = root;
	while(temp != NULL){
		if(temp->info == number)
		{
			cout << "Number is there in tree plz enter a unique number"<<endl;
			break;
		}
		if(temp->info < number)
		{
			if(temp->right_thread == 0)         // thread = 1 means temprary value is there
				temp = temp->right;
			else
				break;
		}
		else
		{
			if(temp->left_thread == 0)
				temp = temp->left;
			else
				break;
		}

	}
ptr = new node;
ptr -> info = number;
ptr->left_thread = 1;
ptr->right_thread = 1;

	if(temp == NULL){
		ptr->right = ptr->left = dummy;
		root = ptr;
		dummy->left = root;
		if(ptr->left == dummy){
			cout <<"current set"<<endl;
			current = ptr;
		}
		return;          
	}
	if (temp->info < number){
		ptr->right = temp->right;
		temp->right = ptr;
		temp->right_thread = 0;
		ptr->left = temp;
		return;
	}
	if (temp->info > number){
		ptr->left = temp->left;
		temp->left = ptr;
		temp->left_thread = 0;
		ptr->right = temp;
		if(ptr->left == dummy){
			cout <<"current set"<<endl;
			current = ptr;
		}
		return;
	}
}

node* nextInorder(node *temp)
{ 
  if(temp->right_thread == 1)
  	 return temp -> right; 
  else { 
    temp = temp->right; 
    while (temp->left_thread == 0) 
      temp = temp->left; 
    return temp; 
  } 
} 
	void fastInorder() 
	{
		if (root == NULL)
		{
			cout <<"Tree is empty right now"<<endl;
			return;
		}
		temp = current;
		cout <<temp->info <<" ";
	while(  (temp = nextInorder(temp) ) != dummy ) 	
		cout << temp->info <<" ";
	} 

	 void delet(node *temp){
	 	temp = root;
	 	while(temp != dummy){
	 		cout << "temp: " << temp->info << endl;
	 		if (temp->info == key){
	 			// Case #1
	 			if(temp->left_thread == 1 && temp->right_thread == 1)   // when temp have no child
	 			{
	 				if (temp == root)
	 				{
	 					delete root;
	 					root = NULL;
	 					dummy->left = dummy;
	 					return;
	 				}
	 				ptr = temp->right;
	 				if(temp->left == dummy || ptr->info > temp->info)    // if value is in left
	 				{
	 					ptr->left = temp->left;
	 					if(temp == current)
						 	current = ptr;
	 					
						 // ptr ->right_thread = 1;
						delete temp;
	 					temp = NULL;
	 					ptr ->left_thread = 1;
	 					return;
	 				}
	 				ptr = temp->left;
	 				if (temp->right == dummy || ptr->info < temp->info)  //if value is in right
	 				{
	 					ptr->right = temp->right;
	 					// ptr ->left_thread = 1;
	 					delete temp;
	 					temp = NULL;
	 					ptr ->right_thread = 1;
	 					temp = ptr;
	 					return;
	 				}
	 			}
	 			//case#2
	 			if(temp->left_thread == 1 && temp->right_thread == 0)
	 			{
	 				cout << "ok right"<<endl;
	 				ptr = (nextInorder(temp));
	 				ptr->left = temp->left;
	 				if(temp = current)
	 					current = ptr;
	 				if (temp == root){
						root = temp->right;
						current = root;
						ptr->left->left = ptr->right;
	 				}
	 				// ptr = temp->right->left;
	 				ptr->left->right = temp->right; 
	 				delete temp;
	 				temp = NULL;
	 				return;
				}
				if( temp->left_thread == 0 && temp->right_thread == 1)
				{
					if(temp == root)
	 					root = temp->left;

					ptr->right = temp->right;
					ptr->right->left = temp->left;
					delete temp;
					temp = NULL;
					return;
				}
//				// Case#3
				if(temp->left_thread == 0 && temp->right_thread == 0){
						ptr = temp->left;
						while(ptr->right_thread != 1){
							ptr = ptr->right;
						}
						swap = temp->info;
						temp->info = ptr->info;
						ptr->info = swap;
						if(ptr->left_thread == 0){
							temp1 = ptr;
							while(temp1->left_thread != 1){
								temp1 = temp1->left;
							}
							ptr->left->right = ptr->right; 
							temp1->left->right = ptr->left;  
							delete ptr;
							ptr = NULL;
							return;
						}
						if(ptr == current){
							current = ptr->right;
						}
						ptr->left->right_thread = 1;
						ptr->left->right = ptr->right;
						delete ptr;
						ptr = NULL;
						return;
					}
	 		}
	 		temp = nextInorder(temp);
	 	}
	 		cout << "Key is not in tree" <<endl;
	 		return;
	}
};

int main(){
	thread t;
	for(int i = 0 ; i < 8 ; i++){
	cout <<"Enter number to insert in new node" <<endl;
	cin >> t.number;
	t.insert(t.root);
	}
	t.fastInorder();
	cout << endl;
	cout << "Enter key to delete from thread binery tree" <<endl;
	cin >> t.key;
	t.delet(t.root);
	t.fastInorder();
}
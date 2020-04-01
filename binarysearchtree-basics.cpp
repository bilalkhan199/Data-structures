#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node{
    int info;
    Node *left;
    Node *right;
};
class BST{
    private:
        Node *temp,*temp1;
    public:
        Node *root;
        int number;
        int key;
        BST(){
            root=temp=temp1=NULL;
            number=0;
        }   
        void in_order(Node *);  // For traversal
        void Insert(Node *);    // For Insertion
        void Delete(Node *);    // For deletion
        Node* ImidiateSuccessor(Node *);    // Fro Imediate successor
        void Search(Node *);
        void Destructor(Node *);
        ~BST(){
            Destructor(root);
            root=NULL;
            cout<<"done the program"<<endl;
        }
};

void BST::in_order(Node *temp){
    if(temp==NULL){
        cout<<"Tree is empty!"<<endl;
        return;
    }
    if(temp->left!=NULL){
        in_order(temp->left);
    }
    cout<<temp->info<<" - ";
    if(temp->right!=NULL){
        in_order(temp->right);
    }
    return ;
}
//   Insertion

void BST::Insert(Node *temp){
    if(root==NULL){
        temp=new Node;
        temp->info=number;
        temp->left=NULL;
        temp->right=NULL;
        root=temp;
        return;
    }
    if(temp->info==number){
        cout<<"Already in bst"<<endl;
        return;
    }
    if(temp->info < number){
        if(temp->right!=NULL){
            Insert(temp->right);
            return;
        }
        else{
            temp->right=new Node;
            temp->right->info=number;
            temp->right->left=NULL;
            temp->right->right=NULL;
            return;
        }
    }
    if(temp->info > number){
        if(temp->left!=NULL){
            Insert(temp->left);
            return;
        }
        else{
            temp->left=new Node;
            temp->left->info=number;
            temp->left->left=NULL;
            temp->left->right=NULL;
            return;
        }
    }
}

//      Deletion of a node 
void BST::Delete(Node *temp){
    if(temp==NULL){
        cout<<"Tree is Empty!";
        return;
    }
    if(temp->info==key){         //  Root of tree
        if(temp->right!=NULL){
            if(temp->right->right==NULL && temp->right->left==NULL){   //  Case-I for root
                temp1=temp->right;
                swap(temp->info,temp1->info);
                delete temp1;
                temp->right=NULL;
                return;
            }
            else if(temp->right->left==NULL && temp->right->right!=NULL){     //  Case-II for root
                temp1=temp->right;
                swap(temp->info,temp1->info);
                temp->right=temp1->right;
                delete temp1;
                return;
            }
            else{           //  Case-III for root
                if(temp->right->left==NULL && temp->right->right==NULL){  // root has only one right node
                    swap(temp->info,temp->right->info);
                    delete temp->right;
                    temp->right=NULL;
                }
                if(temp->right->left==NULL && temp->right->right != NULL){  // right child has only right NULL
                    swap(temp->info,temp->right->info);
                    temp1=temp->right;
                    temp->right=temp1->right;
                    delete temp1;
                }
                else if(temp->right->left!=NULL){
                    temp1=ImidiateSuccessor(temp->right);
                    swap(temp->info,temp1->left->info);
                    key=temp1->left->info;
                    Delete(temp1);
                    return;
                }
            }
        }        //  Root of tree
    }
    else if(temp->info<key){     //   Right subtree
        if(temp->right!=NULL){
            if(temp->right->info==key){
                if(temp->right->left==NULL && temp->right->right==NULL){    //   CASE-I
                    delete temp->right;
                    temp->right=NULL;
                }
                else if(temp->right->left!=NULL && temp->right->right==NULL){   //   CASE-II (Right empty)
                    temp1=temp->right;
                    temp->right=temp->right->left;
                    delete temp1;
                }
                else if(temp->right->left==NULL && temp->right->right!=NULL){   //  CASE-II (Left empty)
                    temp1=temp->right;
                    temp->right=temp->right->right;
                    delete temp1;
                }
                else{   //   Case-III  (Right Side)
                    if(temp->right->right->right==NULL && temp->right->right->left==NULL){
                        swap(temp->right->info,temp->right->right->info);
                        delete temp->right->right;
                        temp->right->right=NULL;
                        return;
                    }
                    if(temp->right->right->right != NULL && temp->right->right->left == NULL){
                        swap(temp->right->info,temp->right->right->info);
                        temp1=temp->right->right;
                        temp->right->right=temp1->right;
                        delete temp1;
                        return;
                    }
                    if(temp->right->right->left != NULL){
                        temp1=ImidiateSuccessor(temp->right->right);
                        swap(temp->right->info,temp1->left->info);
                        key=temp1->left->info;
                        Delete(temp1);
                        return;
                    }
                }
            }
            else{
                Delete(temp->right);
                return;
            }   
        }
        else{
            cout<<"Value not exist";
        }       
    }
    else if(temp->info > key){           //   Left subtree
        if(temp->left!=NULL){
            if(temp->left->info==key){
                if(temp->left->left==NULL && temp->left->right==NULL){
                    delete temp->left;
                    temp->left=NULL;
                }
                else if(temp->left->left!=NULL && temp->left->right==NULL){    //  CASE-II (Right empty)
                    temp1=temp->left;
                    temp->left=temp->left->left;
                    delete temp1;
                }
                else if(temp->left->left==NULL && temp->left->right!=NULL){    //   CASE-II (left empty)
                    temp1=temp->left;
                    temp->left=temp->left->right;
                    delete temp1;
                }
                else{   //   Case-III   Left subtree
                    if(temp->left->right->right ==NULL && temp->left->right->left ==NULL){
                        swap(temp->left->info,temp->left->right->info);
                        delete temp->left->right;
                        temp->left->right=NULL;
                        return;
                    }
                    else if(temp->left->right->right != NULL && temp->left->right->left == NULL){
                        swap(temp->left->info,temp->left->right->info);
                        temp1=temp->left->right;
                        temp->left->right=temp1->right;
                        delete temp1;
                        return;
                    }
                    else{
                        temp1=ImidiateSuccessor(temp->left->right);
                        swap(temp->left->info,temp1->left->info);
                        key=temp1->left->info;
                        Delete(temp1);
                        return;
                    }
                }
            }
            else{
                Delete(temp->left);
                return;
            }
        }
        else{
            cout<<"Value not exist";
        }
    }
}
Node* BST::ImidiateSuccessor(Node *temp){
        while(temp->left->left!=NULL){
            temp=temp->left;
        }    
        return temp;    
}
//
//      searching of a node
//
void BST::Search(Node *temp){
    if(temp==NULL){
        cout<<"Tree is empty!";
        return;
    }
    if(temp->info==key){
        cout<<key<<" is Found!"<<endl;
        return;
    }
    if(temp->info < key){
        if(temp->right != NULL){
            if(temp->right->info==key){
                cout<<key<<" is Found!"<<endl;
                return;
            }
            else{
                Search(temp->right);
                return;
            }
        }
        else{
            cout<<key<<" is not Found!"<<endl;
            return;
        }
    }
    if(temp->info > key){
        if(temp->left !=NULL){
            if(temp->left->info==key){
                cout<<key<<" is Found!"<<endl;
                return;
            }
            else{
                Search(temp->left);
                return;
            }
        }
        else{
            cout<<key<<" is not Found!"<<endl;
            return;
        }
    }
}
//      Destructor  in Postorder
void BST::Destructor(Node *temp){
    if(temp==NULL){
        cout<<"Tree is empty"<<endl;
        return;
    }
    if(temp->left!=NULL){
        Destructor(temp->left);
    }
    if(temp->right != NULL){
        Destructor(temp->right);
    }
    delete temp;
    temp=NULL;
}

int main()
{
    BST b;
    char n;
    b.number=10;
    b.Insert(b.root);

    b.number=16;
    b.Insert(b.root);

    b.number=15;
    b.Insert(b.root);

    b.number=13;
    b.Insert(b.root);

    b.number=5;
    b.Insert(b.root);

    b.number=12;
    b.Insert(b.root);

    b.number=11;
    b.Insert(b.root);
    
    b.in_order(b.root); 
    cout<<endl;

    b.key=12;
    b.Delete(b.root);
    b.key=10;
    b.Search(b.root);
    
    b.in_order(b.root);  cout<<endl;
     return 0;
}
#include<iostream>
using namespace std;
struct Node{
    int info;
    Node *left;
    Node *right;
};
class binarytree{
    public:
    Node *temp,*temp1,*tworight,*twoleft,*helloworld;
    Node *root;
    int number,key,alpha,count=0;

    binarytree()
    {
        root=temp=NULL;
        number=0;
    }
    void insert(Node *temp)
    {
        if(root==NULL){
        temp=new Node;
        temp->info=number;
        temp->left=NULL;
        temp->right=NULL;
        root=temp;
        return;
    }
    if(temp->info==number){
        cout<<"Given number is alredy present in BST"<<endl;
        return;
    }
    if(temp->info < number){
        if(temp->right!=NULL){
            temp=temp->right;
            insert(temp);
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
            temp=temp->left;
            insert(temp);
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


    void preorder(Node *temp,int alpha)
    {
        if (temp==NULL)
        {
            cout<<"Empty BST detected";
            return;
        }
        cout<<temp->info<<"-";
        if (temp->info==alpha)
        {
            count++;   
        }
        if (temp->left!=NULL)
            preorder(temp->left,alpha);
        
        if (temp->right!=NULL)
            preorder(temp->right,alpha);

    }
    void postorder(Node *temp)
    {
        if (temp==NULL)
        {
            cout<<"Empty BST detected";
        }
        if (temp->left!=NULL)
        {
            postorder(temp->left);
        }
        if (temp->right!=NULL)
        {
            postorder(temp->right);
        }
        cout<<temp->info<<" ";
    }

    Node* ImidiateSuccessor(Node *temp){
        while(temp->left->left!=NULL){
            temp=temp->left;
        }    
        return temp;    
    }

    void Delete(Node *temp){
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
    

};


int main()
{
    binarytree b;
    b.number=50;
    b.insert(b.root);

    b.number=30;
    b.insert(b.root);

    b.number=70;
    b.insert(b.root);

    b.number=20;  
    b.insert(b.root);

    b.number=40;
    b.insert(b.root);


    b.number=60;
    b.insert(b.root);

    b.number=80;
    b.insert(b.root);

    //Traversal inorder,postorder,preorder
    int alpha;
    cout<<"Enter number to count";
    cin>>alpha;
    b.preorder(b.root,alpha);
    cout<<endl<<"Count is "<<b.count<<endl;

    //delete function.
    b.key=80;
    b.Delete(b.root);
   // b.preorder(b.root);
    
}

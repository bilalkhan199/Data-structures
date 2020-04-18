#include<iostream>
using namespace std;
struct Node{
    int info;
    Node *left;
    Node *right;
};
class binarytree{
    public:
    Node *temp,*temp1;
    Node *root;
    int number;

    binarytree()
    {
        root=temp=temp1=NULL;
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
        cout<<"Given number is alredy present in TREE"<<endl;
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


    void preorder(Node *temp)
    {
        if (temp==NULL)
        {
            cout<<"Empty BST detected";
            return;
        }
        cout<<temp->info<<"-";
        if (temp->left!=NULL)
            preorder(temp->left);
        
        if (temp->right!=NULL)
            preorder(temp->right);

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
            preorder(temp->right);
        }
        cout<<temp->info<<" ";
    }

};


int main()
{
    binarytree b;
    b.number=10;
    b.insert(b.root);

    b.number=16;
    b.insert(b.root);

    b.number=15;
    b.insert(b.root);

    b.number=13;
    b.insert(b.root);

    b.number=5;
    b.insert(b.root);

    b.number=12;
    b.insert(b.root);


    //Traversal inorder,postorder,preorder

    b.preorder(b.root);
    cout<<endl;
    b.postorder(b.root);
    
}

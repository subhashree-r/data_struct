#include<iostream>
#include<stdio.h>
#include<stdlib.h>


using namespace std;
struct Node
{
int data;
struct Node *left, *right;
}*root;
class Tree
{
public:
//Tree();
struct Node* insert(struct Node*, int data);
void inorder(struct Node*);
struct Node* search(struct Node*);
int height(struct Node*);

};

struct Node* Tree::insert(struct Node* node, int new_data)
{
if(node==NULL)
{
node = new Node;
node->data=new_data;
node->left=NULL;
node->right=NULL;

root=node;
return node;
}
if(new_data < node->data)
{
          node->left=insert(node->left,new_data);

}
else if(new_data>node->data)
{

    node->right=insert(node->right,new_data);
}
return node;
}

void Tree::inorder(struct Node *root)
{
 if(root!=NULL)
 {

     inorder(root->left);
     cout<<root->data<<endl;
     inorder(root->right);
 }

}
struct Node* Tree::search(struct Node *root, int temp)
{
    if(root==NULL||root->data==temp)
    {
        return root;
    }
    if(temp < root->data)
    {
        return search(root->left,temp);
    }
    else if(temp>root->data)
    {
        return search(root->right);
    }
}
int Tree::height(struct Node* root)
{

    if(root==NULL)
    {
        return 0;
    }
    else
    {
        int left_height=height(root);
        int right_height=height(root);
        if(left_height>right_height)
        {

            return left_height+1;
        }
        else{
            return right_height+1;
        }
    }
}
int main()
{

    Tree t;
    //Node *root;
    Node *ptr;
    int ht;
    //ptr=root;
    int n;
    root= NULL;
    int value;
    while(1)
    {
    cout<<"Enter your operation"<<endl;
    cout<<"1.Insert"<<endl;
    cout<<"2.Inorder"<<endl;
    cout<<"3.Search"<<endl;
    cout<<"4.Find Height"<<endl;
    cout<<"5.Exit"<<endl;
    cin>>n;

    switch (n)
    {
    case 1:
    {
        cout<<"enter the value";
        cin>>value;
        t.insert(root,value);
        //break;
    }
    case 2:
    {
        t.inorder(root);
        break;
    }
    case 3:
    {
        ptr=t.search(root);
        if(ptr!=NULL)
        {
            cout<<"Found";
        }
    }
    case 4:
     {
         ht=t.height(root);
         break;
     }

    case 5:
    {
        exit(1);
    }




    }
}
 return 0;
}


// C/C++ program to find longest consecutive
// sequence in binary tree
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
//Binary tree
struct Node{
    int data;
    Node *left,*right;
};
Node*newNode(int data)
{
    Node *temp=new Node;
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}
void longestConsecutiveUtil(Node *root,int currLength,int expected, int &res )
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        if(root->data==expected)
        {
            currLength++;
        }
        else
        {
            currLength=1;
        }
    }
    res=max(currLength,res);
    longestConsecutiveUtil(root->left,currLength,root->data+1,res);
    longestConsecutiveUtil(root->right,currLength,root->data+1,res);

}
int longestConsecutive(Node *root)
{
    int res=0;
    longestConsecutiveUtil(root,0,root->data,res);
    return res;
}
// Driver code to test above methods
int main()
{
	Node* root = newNode(6);
	root->right = newNode(9);
	root->right->left = newNode(7);
	root->right->right = newNode(10);
	root->right->right->right = newNode(11);

	printf("%d\n", longestConsecutive(root));
	return 0;
}

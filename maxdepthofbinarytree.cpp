#include<stdio.h>
#include<iostream>
using namespace std;
struct node
{
	struct node* left=NULL;
	struct node* right=NULL;
	int data;
};
node* createnode(int data)
{
	struct node* p;
	p=new (struct node);
	p->data=data;
	p->left=NULL;
	p->right=NULL;
	return p;
}                                                                //height of binary tree.
int height(struct node* root)
{
	if(root==NULL)
	return 0;
	int x=height(root->left);
	int y=height(root->right);
	if(x>y)
	{
		return x+1;
	}
	else
	{                                                          //maxdepth of a binary tree.
		return y+1;
	}
}
int main()
{
 node *root = createnode(1);  
  
    root->left = createnode(2);  
    root->right = createnode(3);  
    root->left->left = createnode(4);  
    root->left->right = createnode(5); 
	int g=height(root);
	cout<<g;
	return 0;
	}


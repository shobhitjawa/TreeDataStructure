#include<stdio.h>
#include<iostream>
using namespace std;
struct node{
	int data;
	struct node* left=NULL;
	struct node* right=NULL;
};
node* createnode(int data)
{
	struct node*  p;
    p=new (struct node);
	p->data=data;
	p->left=NULL;
	p->right=NULL;                                         //delete a complete binary tree.
	return p;	
}
void  deletion(struct node* root)
{
	if(root==NULL)
	{
	return; 
	}
	deletion(root->left);
	deletion(root->right);
	delete (root);
	root=NULL;
}
void inorder(struct node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
int main()
{
	struct node* root=createnode(1);
	root->left=createnode(2);
	root->right=createnode(3);
	root->left->left=createnode(4);
	root->left->right=createnode(5);
	root->right->right=createnode(6);
		inorder(root);
	deletion(root);
return 0;
}

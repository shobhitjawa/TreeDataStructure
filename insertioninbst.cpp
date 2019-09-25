#include<stdio.h>
#include<iostream>
using namespace std;
struct node{
	int data;
	struct node* left;
	struct node* right;
};
node* createnode(int data)
{
	struct node* p;
	p=new (struct node);
	p->data=data;
	p->left=NULL;
	p->right=NULL;
	return p;
}                                   //insertion in a binary search tree.
void inorder(struct node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
node* insert(struct node* root,int key)
{
	if(root==NULL)
	return createnode(key);
	if(key<root->data)
	{
	  root->left=insert(root->left,key);
	}
	if(key>root->data)
	{
		root->right=insert(root->right,key);
	}
	return root;
}
int main()
{
	struct node* root=NULL;
	root=insert(root,10);
     root=insert(root,50);
	root=insert(root,30);
	root=insert(root,90);
	root=insert (root,110);
	inorder(root);
	return 0;
}






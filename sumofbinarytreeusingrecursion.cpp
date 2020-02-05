#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
struct node{
	struct node* left=NULL;
	struct node* right=NULL;
	int data;
};

node* createnode(int data)
{
	struct node* p;
	p=new (struct node);
	p->data=data;
	p->right=NULL;
	p->left=NULL;
	return p;
}
int sum(struct node* root)
{
if(root==NULL)
return 0;

int s=0,x=0;
s=s+root->data+sum(root->left);                       //sum of all nodes using recursion in binary tree.
x=x+s+sum(root->right);
return x;
}
int main()
{
	struct node* root=createnode(1);
	root->left=createnode(2);
	root->right=createnode(3);
	root->left->left=createnode(4);
	root->left->right=createnode(6);
	root->right->left=createnode(4);
	int x=sum(root);
	cout<<x;
		return 0;
}

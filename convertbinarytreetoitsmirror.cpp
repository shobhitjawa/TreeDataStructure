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
	p=new(struct node);
	p->data=data;
	p->left=NULL;
	p->right=NULL;
	return p;
}
void mirror(struct node* root)
{
if(root==NULL)
return;
struct node* temp;
mirror(root->left);
mirror(root->right);
temp=root->left;
root->left=root->right;
root->right=temp;
}
void inorder(struct node* root)
{
	if(root!=NULL)                            //convert binary tree to its mirror.
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
	root->left->left=createnode(3);
	root->left->right=createnode(4);
	root->right=createnode(5);
	root->right->right=createnode(6);
	mirror(root);
	inorder(root);
	return 0;
}

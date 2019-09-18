#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
struct node
{
int data;
struct node* left=NULL;
struct node* right=NULL;	
};
node* createnode(int data)
{
	struct node* p;
	p=new (struct node);
	p->data=data;
	p->left=NULL;
	p->right=NULL;
	return p;
}
void levelorder(struct node* root)
{
	if(root==NULL)
	return;
	queue<node*> q;
	q.push(root);
	while(q.empty()==false)
	{
		struct node* f=q.front();
		cout<<f->data<<" "; 
		q.pop();                                                     //printing tree level order wise.
		if(f->left!=NULL)
		{
		q.push(f->left);
		}
		if(f->right!=NULL)
		{
			q.push(f->right);
		}
	}
}
int main()
{
	struct node * root=createnode(1);
	root->left=createnode(2);
	root->right=createnode(3);
	root->left->left=createnode(4);
	root->left->right=createnode(5);
     levelorder(root);
	return 0;
}

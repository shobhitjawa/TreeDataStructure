#include<stdio.h>
#include<iostream>
#include<stack>
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
void postorderiterative(struct node* root)
{
	struct node*  curr=root;
	struct node* vr;
	stack<node*>s1;
	stack<node*>s2;
	if(root==NULL)
	return;
	s1.push(curr);
	while(s1.empty()==false)
	{
	vr=s1.top();	
    s1.pop();
    s2.push(vr);
	if(vr->left!=NULL)                                 // post order traversal iterative method.
	{
		s1.push(vr->left);
	}
	if(vr->right!=NULL)
	{
		s1.push(vr->right);
	}
    }
	while(s2.empty()==false)
	{
		struct node* ij;
		ij=s2.top();
		cout<<ij->data<<" ";
		s2.pop();
	}
}
int main()
{
	struct node * root=createnode(1);
	root->left=createnode(2);
	root->right=createnode(3);
	root->left->left=createnode(4);
	root->left->right=createnode(5);
	postorderiterative(root);
	return 0;
}

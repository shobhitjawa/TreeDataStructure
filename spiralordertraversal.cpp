#include<stdio.h>
#include<iostream>
#include<stack>
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
void spiralordertraversal(struct node* root)
{
	stack<node*>s1;
	stack<node*> s2;
	s1.push(root);
	while(s1.empty()==false||s2.empty()==false)
	{
		while(s1.empty()==false)
		{
			struct node* temp1=s1.top();
			cout<<temp1->data<<" ";
			s1.pop();
			
			if(temp1->right!=NULL)
			{
				s2.push(temp1->right);
			}                                                      //spiral order traversal of a binary tree.
			if(temp1->left!=NULL)
			{
				s2.push(temp1->left);
			}
		}
		while(s2.empty()==false)
		{
			struct node* temp2=s2.top();
		      cout<<temp2->data<<" ";
		      s2.pop();
		      if(temp2->left!=NULL)
		      {
		      	s1.push(temp2->left);
			  }
			  if(temp2->right!=NULL)
			  {
			  	s1.push(temp2->right);
			  }
		}
		
	}
}
int main()
{
	struct node* root = createnode(1); 
    root->left = createnode(2); 
    root->right = createnode(3); 
    root->left->left = createnode(7); 
    root->left->right = createnode(6); 
    root->right->left = createnode(5); 
    root->right->right = createnode(4);
    spiralordertraversal(root);
return 0;
}

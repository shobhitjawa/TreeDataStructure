#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
struct node{
	int data;
	struct node* left;
	struct node* right;
};
node* newNode(int data)
{
	struct node* p;
	p=new (struct node);
	p->data=data;
	p->left=NULL;
	p->right=NULL;
	return p;
}  
int sum(struct node* root)
{
	int s=0;
	struct node* temp;
	queue<node*> q1;
	q1.push(root);
	while(q1.empty()==false)
	{
		temp=q1.front();
		s=s+temp->data;
		  q1.pop();
		if(temp->left!=NULL)
		{
			q1.push(temp->left);
		}
		if(temp->right!=NULL)
		{
			q1.push(temp->right);
		}
	}
	return s;
}
int main()                                    //sum of all nodes of a biinary tree.
{
struct node *root  = newNode(26); 
    root->left         = newNode(10); 
    root->right        = newNode(3); 
    root->left->left   = newNode(4); 
    root->left->right  = newNode(6); 
    root->right->right = newNode(3);
   int c= sum(root);
   cout<<c;
	return 0;
}

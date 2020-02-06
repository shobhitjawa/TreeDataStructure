#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node* right=NULL;
	struct node* left=NULL;
};
void insucc(struct node* root,struct node* tofind, queue<node*>q2);
node* createnode(int data)
{
	struct node*p;
	p=new (struct node);                                       //inorder successor of node in binary tree 	
	p->data=data;
	p->right=NULL;
	p->left=NULL;
	return p;
}
void inordersucesser(struct node* root,struct node* tofind)
{
	struct node* temp=root;
		struct node* temp1=root;
	stack<node*>s1;
	queue<node*>q2;
	while(s1.empty()==false||temp!=NULL)
	{
		while(temp!=NULL)
		{
		s1.push(temp);
			temp=temp->left;
		}
		temp=s1.top();
		q2.push(temp);
	   s1.pop();
	   temp=temp->right;	
	}
   insucc(root,tofind,q2);
   return;
}
void insucc(struct node* root,struct node* tofind, queue<node*>q2)
{
	int flag=0;
	int x=tofind->data;
	 struct node* curr=NULL;
	 struct node* curr1;
	 while(q2.empty()==false)
	 {
	 	curr=q2.front();
	 	if(curr==tofind)
	 	{
	 	  q2.pop();
		   curr1=q2.front();
		   if(curr1!=NULL)
		   {
		   cout<<"inorder succ for "<<x<<" is : "<<curr1->data;
		   cout<<endl;
		   flag=1;
		   break;
	       }
	       else
	       {
	       	flag=0;
	       	break;
		   }
		 }
		 q2.pop();
	 }
	 if(flag==0)
	 {
	 
 	     	 	cout<<"no inorder sucessor exist";
		 	cout<<endl;
		}
	return;
}
int main()
{
	struct node* root;
	root=createnode(1);
	root->left=createnode(2);
	root->right=createnode(3);
	root->left->left=createnode(3);
	root->left->right=createnode(5);
	root->right->right=createnode(6);
	inordersucesser(root,root->right);
	inordersucesser(root,root->left->left);
	inordersucesser(root,root->right->right);
	return 0;
}

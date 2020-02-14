#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node* left=NULL;
	struct node* right=NULL;
};
int preordersucc(queue<node*>s1,struct node* tofind);
node* createnode(int data)
{
	struct node* temp;
	temp=new(struct node);
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
void preorder(struct node* root,struct node* tofind)
{
	stack<node*>q1;
	queue<node*>s1;
	struct node* curr=root;         //preorder sucessor using queue and stack.
	q1.push(root);
	while(q1.empty()==false)
	{
		curr=q1.top();
		s1.push(curr);
		q1.pop();
			if(curr->right!=NULL)
		{
			q1.push(curr->right);
		}
		if(curr->left!=NULL)
		{
			q1.push(curr->left);
		}
	}
 	int r=preordersucc(s1,tofind);
}
int preordersucc(queue<node*>s1,struct node* tofind)
{
	cout<<endl;
	struct node* y;
	struct node* p;
int flag=0;
   while(s1.empty()==false)
   {  
   	y=s1.front();
 if(y==tofind)
 {
 	s1.pop();
 	struct node* t=s1.front();
 	if(t!=NULL)
 	{
 	cout<<"preorder sucessor  is:"<<t->data;
 	flag=1;
 	break;
   }
   else{
   	flag=0;
   	break;
   }
 }
 s1.pop();
   } 
   if(flag==0)
   {
   	cout<<"no preorder sucessor exist";
   } 
}
int main()
{
	struct node* root=createnode(1);
	root->left=createnode(2);
	 root->right=createnode(3);
	root->left->left=createnode(4);
	root->left->right=createnode(5);
	root->right->left=createnode(6);
	root->right->right=createnode(7);
//	struct node* tofind=createnode(4);
	preorder(root,root->right->left);
	preorder(root,root->right->right);
	return 0;
}

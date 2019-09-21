#include<stdio.h>
#include<iostream>
#include<stack>
#include<queue>
using namespace std;                                             
struct node{
	int data;
	struct node* left=NULL;
	struct node* right=NULL;
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
void rightviewoftree(struct node* root1)
{
	if(root1==NULL)
	return;
     queue<node*> q1;
     q1.push(root1);
     while(q1.empty()==false)
     {
     	int n=q1.size();                                     //right view of a binary tree O(n).
     	for(int i=1;i<=n;i++)
     	{
     		struct node* temp1=q1.front();
     		q1.pop();
     		if(i==n)
     		{
     			cout<<temp1->data<<" ";
			 }
			 if(temp1->left!=NULL)
			 {
			 	q1.push(temp1->left);
			 }
			 if(temp1->right!=NULL)
			 {
			 	q1.push(temp1->right);
			 }
		 }
	 }
}
int main()
{
	struct node* root1=createnode(1);
	root1->left=createnode(2);
	root1->right=createnode(3);
	root1->left->left=createnode(4);
	root1->left->right=createnode(5);
	root1->right->left=createnode(6);
	root1->right->right=createnode(7);
	root1->left->left->left=createnode(4);
	rightviewoftree(root1);
	return 0;
}

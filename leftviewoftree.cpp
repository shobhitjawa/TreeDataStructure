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
void leftviewoftree(struct node* root1)
{
	if(root1==NULL)
	return;
    queue<node*>q1;
    q1.push(root1);
    q1.push(NULL);
    while(q1.empty()==false)
    {
    	struct node* temp1=q1.front();
    	if(temp1!=NULL)
    	{
    		cout<<temp1->data;
    		while(q1.front()!=NULL)                               //left view of binary tree iteratively.
    		{
    			if(temp1->left!=NULL)
    			q1.push(temp1->left);
    			if(temp1->right!=NULL)
    			q1.push(temp1->right);
    			q1.pop();
    			temp1=q1.front();
			}
			q1.push(NULL);                                      //(its a delimiter for the next line indication)
		}
		q1.pop();
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
	leftviewoftree(root1);
	return 0;
}

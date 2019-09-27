#include<stdio.h>
#include<queue>
#include<list>
#include<iostream>
using namespace std;
struct node
{
int data;
struct node* left;
struct node* right;	
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
int sumofleaf(struct node* root)
{
	int x,y,s,p;
	if(root==NULL)
	{
     return 0;
    }
    if(root->left==NULL&&root->right==NULL)
    {
       x=root->data;                         //sum of all leaf nodes of binary tree.
	}
    s=x+sumofleaf(root->left);
    p=s+sumofleaf(root->right); 
    return p;   
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
	cout<<(sumofleaf(root));
	return 0;
}

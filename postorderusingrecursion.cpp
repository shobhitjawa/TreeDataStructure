#include<stdio.h>
#include<iostream>
using namespace std;
struct node{
	struct node*  left=NULL;
	struct node* right=NULL;
    int data;
};
node* createnode(int data)
{
	struct node* p;
	p=new (struct node);
	p->data=data;
	p->left=NULL;
	p->right=NULL;
	return p;                                  //postorder tree traversal using recursion.
 } 
 void postorder(struct node* root)
 {
 	if(root!=NULL)
 	{
	   postorder(root->left);
	   postorder(root->right);
	   cout<<root->data<" ";	
	}
 }
 int main()
 {
 	struct node * root=createnode(34);
 	root->left=createnode(33);
 	root->right=createnode(55);
 	root->right->left=createnode(45);
 	postorder(root);
 	return 0;
 }

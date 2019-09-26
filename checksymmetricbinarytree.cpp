#include<stdio.h>
#include<iostream>
using namespace std;
struct node{
	int data;
	struct node* left;
	struct node* right;
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
int mirror(struct node* root1,struct node* root2)
{
if(root1==NULL&&root2==NULL)
return 1;
 int x,y;
 if(root1!=NULL&&root2!=NULL)
 {
 if(mirror(root1->left,root2->right)&&mirror(root1->right,root2->left))
 {
 	return 1;
 }
}
return 0;
}
int mirror1(struct node* root)                            //check normal symmetric tree .not the mirror image symmetric tree.
{
	if(root==NULL) 
	return 1;
   int x=mirror(root->left,root->right);
   if(x==1)
   cout<<"are symmetric";
   else
   cout<<"not symmetric";
}
int main()
{
	struct node* root=createnode(1);
	root->left=createnode(2);
	root->left->left=createnode(3);
	root->right=createnode(5);
	root->right->right=createnode(6);
	mirror1(root);
	return 0;
}

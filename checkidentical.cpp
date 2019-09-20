#include<stdio.h>
#include<iostream>
#include<stack>
#include<queue>
using namespace std;                                             
struct node{
	int data;
	struct node* left=NULL;
	struct node* right=NULL;
};                                                                    //to check weather a 2 trees are identical or not iteratively. 
node* createnode(int data)
{
	struct node* p;
	p=new(struct node);
	p->data=data;
	p->left=NULL;
	p->right=NULL;
	return p;
}
void checkidentical(struct node* root1,struct node* root2)
{
   queue<node*>q1;
   queue<node*>q2;
   queue<node*>q3;
   queue<node*>q4;
   struct node* temp1=root1;
   struct node* temp2=root2;
   q1.push(temp1);
   q2.push(temp2);	
   while(q1.empty()==false)
   {
   	struct node* temp1=q1.front();
   	q3.push(temp1);
   	q1.pop();
   	if(temp1->left!=NULL)
   	q1.push(temp1->left);
   	if(temp1->right!=NULL)
   	q1.push(temp1->right);
   }
    while(q2.empty()==false)
   {
   	struct node* temp2=q2.front();
   	q4.push(temp2);
   	q2.pop();
   	if(temp2->left!=NULL)
   	q2.push(temp2->left);
   	if(temp2->right!=NULL)
   	q2.push(temp2->right);
   }
   int len1=q3.size();
   int len2=q4.size();
   int count=0;
   while(q3.empty()==false||q4.empty()==false)
   {
   
   	struct node* r1=q3.front();
   	struct node* r2=q4.front();
   	if(len1!=len2)
   	 {
        break;
     }
     if(r1->data==r2->data)
     {
     	count+=1;
	 }
	 q3.pop();
	 q4.pop();
    }
   if(count==len1&&count==len2)
   cout<<"are identical in nature";
   else
   cout<<"not identical";
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
    struct node* root2=createnode(1);
	root2->left=createnode(2);
	root2->right=createnode(3);
	root2->left->left=createnode(4);
	root2->left->right=createnode(5);
	root2->right->left=createnode(6);
	root2->right->right=createnode(7);
		root2->left->left->left=createnode(4);
	checkidentical(root1,root2);
	return 0;
}

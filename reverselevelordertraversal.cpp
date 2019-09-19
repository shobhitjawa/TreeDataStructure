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
void reverselevelorder(struct node* root)
{
stack <node *> S1; 
    queue <node *> Q1;
	struct node* curr=root; 
    Q1.push(curr); 
    while (Q1.empty() == false) 
    { 
       curr = Q1.front();                            //print binary tree in reverse level order 
        Q1.pop(); 
        S1.push(curr); 
        if (curr->right) 
            Q1.push(curr->right); 
 
        if (curr->left) 
            Q1.push(curr->left); 
}
    while (S1.empty() == false) 
    { 
        curr = S1.top(); 
        cout <<curr->data << " "; 
        S1.pop(); 
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
	reverselevelorder(root);
	return 0;
}

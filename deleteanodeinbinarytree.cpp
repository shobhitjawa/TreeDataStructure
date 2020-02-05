#include<stdio.h>
#include <bits/stdc++.h> 
#include<iostream>
using namespace std;  
struct node { 
    int key; 
    struct node *left, *right; 
}; 
void deletedeepest(struct node* root,struct node* del_node);
  struct node* newNode(int key) 
{ 
    struct node* temp = new node; 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return temp; 
};  
void inorder(struct node* temp) 
{ 
    if (!temp) 
        return; 
    inorder(temp->left); 
    cout << temp->key << " "; 
    inorder(temp->right); 
} 
node* deletion(struct node* root,int key)
{
	if(root==NULL)
	return NULL;
	if(root->left==NULL&&root->right==NULL)
	{
		if(root->key==key)
		{
			return NULL;
		}
		else
		return root;
	}
	struct node* temp;
	struct node* node_del=NULL;
	queue<node*>q1;
	q1.push(root);
	while(q1.empty()==false)
	{
		temp=q1.front();
		q1.pop();
		if(temp->key==key)
		{
			node_del=temp;
		}
		if(temp->left)
		{
		q1.push(temp->left);	
		}
		if(temp->right)
		{
			q1.push(temp->right);
		}
	}
	if(node_del!=NULL)
	{
		int x=temp->key;
		cout<<endl;
		cout<<"value is:"<<x<<endl;
		deletedeepest(root,temp);
		node_del->key=x;	
   
	}

	return root;
}

void deletedeepest(struct node* root, struct node* del_node)
{
 queue<node*>q1;
 q1.push(root);
 struct node* temp;
 temp=q1.front();
 q1.pop();
 if(temp==del_node)
 {
 	temp=NULL;
 	delete(del_node);
 	return;
 }
 if(temp->right!=NULL)
{                                           //delete node in binary tree ..imp quest
	if(temp->right==del_node)
	{
		temp->right=NULL;
		delete(del_node);
		return;
	}
	else{
		q1.push(temp->right);
	}	
}
 if(temp->left!=NULL)
{
	if(temp->left==del_node)
	{
		temp->left=NULL;
		delete(del_node);
		return;
	}
	else{
		q1.push(temp->left);
	}	
}
	return;
}
int main() 
{ 
    struct node* root = newNode(10); 
    root->left = newNode(11); 
    root->left->left = newNode(7); 
    root->left->right = newNode(12); 
    root->right = newNode(9); 
    root->right->left = newNode(15); 
    root->right->right = newNode(8); 
  cout<<endl;
    cout << "Inorder traversal before deletion : "; 
    inorder(root); 
  
    int key = 11; 
    root = deletion(root, key); 
  
    cout << endl; 
    cout << "Inorder traversal after deletion : "; 
    inorder(root); 
        cout<<endl;  
    return 0; 
}

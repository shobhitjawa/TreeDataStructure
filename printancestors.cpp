#include<iostream> 
#include<stdio.h> 
#include<stdlib.h>  
using namespace std;  
struct node 
{ 
   int data; 
   struct node* left; 
   struct node* right; 
};  
bool printAncestors(struct node *root, int t) 
{  
   if(root==NULL)
   return false;
   if(root->data==t)
   {
   	return true;
   }
   if(printAncestors(root->left,t)||printAncestors(root->right,t))
{
	cout<<root->data<<"  ";
	return true;
}
return false;
}  
struct node* newnode(int data) 
{ 
  struct node* node = (struct node*) 
                       malloc(sizeof(struct node)); 
  node->data = data; 
  node->left = NULL; 
  node->right = NULL; 
  
  return(node); 
}  
int main()                                       //print ancestor of node in binary tree
{   
  struct node *root = newnode(1); 
  root->left = newnode(2); 
  root->right= newnode(3); 
  root->left->left  = newnode(4); 
  root->left->right = newnode(5); 
  root->left->left->left  = newnode(7); 
  
  printAncestors(root, 5);  
  return 0; 
} 

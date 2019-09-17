 #include <stdio.h> 
#include <iostream> 
#include <stack> 
using namespace std; 
struct node 
{ 
    int data; 
    struct node* left; 
    struct node* right; 
}; 
struct node* newNode(int data) 
{ 
    struct node* node = new struct node; 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
    return(node); 
} 
void iterativePreorder(node *root) 
{
    if (root == NULL) 
       return;                                               //iterative inorder traversal.
     stack <node* > s;
     node* curr=root;
     while(s.empty()==false||curr!=NULL)
     {
     	while(curr!=NULL)
     	{
     		s.push(curr);
     		curr=curr->left;
		 }
		 curr=s.top();
		 cout<<curr->data<<" ";
		 s.pop();
		 curr=curr->right;
	 }
}  
int main() 
{ 

  struct node *root = newNode(10); 
  root->left        = newNode(8); 
  root->right       = newNode(2); 
  root->left->left  = newNode(3); 
  root->left->right = newNode(5); 
  root->right->left = newNode(2); 
  iterativePreorder(root); 
  return 0; 
} 

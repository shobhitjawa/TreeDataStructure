#include <stdio.h> 
#include <stdlib.h> 
#include<iostream>
using namespace std;

struct node 
{ 
    int data; 
    struct node* left; 
    struct node* right; 
}; 
int sum(struct node *root) 
{ 
   if(root == NULL) 
     return 0;
	 int r,s,p;
	 r=root->data;
	 s=r+sum(root->left);
	 p=s+sum(root->right); 
   return p;
} 
int isSumTree(struct node* node) 
{ 
    int ls, rs;
    if(node == NULL || 
            (node->left == NULL && node->right == NULL)) 
        return 1;
   ls = sum(node->left); 
   rs = sum(node->right); 
    if((node->data == ls + rs))
         
            if(isSumTree(node->left) && 
            isSumTree(node->right)) 
        return 1; 
  
   return 0; 
} 
struct node* newNode(int data) 
{ 
    struct node* node = 
        new (struct node);
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
    return(node);                                     //check if given tree is a sumtree.
} 
  

int main() 
{ 
    struct node *root  = newNode(26); 
    root->left         = newNode(10); 
    root->right        = newNode(3); 
    root->left->left   = newNode(4); 
    root->left->right  = newNode(6); 
    root->right->right = newNode(3); 
    int x=isSumTree(root);
    if(x==0) 
        printf("The  tree is a SumTree "); 
    else
        printf("The tree is not a SumTree "); 
  
   // getchar(); 
    return 0; 
} 

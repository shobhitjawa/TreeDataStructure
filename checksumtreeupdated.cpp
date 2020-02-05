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
   return sum(root->left) + root->data + sum(root->right); 
}  
int isSumTree(struct node* node) 
{ 
    int ls, rs;  
    if(node == NULL || 
            (node->left == NULL && node->right == NULL)) 
        return 1;  
   ls = sum(node->left); 
   rs = sum(node->right);  
    if((node->data == ls + rs)&& 
            isSumTree(node->left) && 
            isSumTree(node->right)) 
        return 1; 
  
   return 0; 
}  
struct node* newNode(int data) 
{ 
    struct node* node = 
        (struct node*)malloc(sizeof(struct node)); 
    node->data = data; 
    node->left = NULL;                 //check sum tree updated.Time complexity-O(n^2).
    node->right = NULL; 
    return(node); 
}  
int main() 
{ 
    struct node *root  = newNode(26); 
    root->left         = newNode(10); 
    root->right        = newNode(3); 
    root->left->left   = newNode(4); 
    root->left->right  = newNode(6); 
    root->right->right = newNode(3); 
    if(isSumTree(root)==1)
    cout<<"yes its a sum tree";
    else
    cout<<"not a sum tree";
    return 0; 
} 


#include <bits/stdc++.h>  
#include<iostream>
using namespace std;  
struct Node 
{ 
    int data; 
    Node *left, *right; 
};  
Node* getNode(int data) 
{  
    Node *newNode =  
        (Node*)malloc(sizeof(Node));  
    newNode->data = data; 
    newNode->left = newNode->right = NULL; 
    return newNode;     
}   
void sumOfParentOfX(Node* root, int& sum, int x) 
{   
if(root==NULL)
return;

if((root->left!=NULL&&root->left->data==x)||(root->right!=NULL&&root->right->data==x))
{
	sum=sum+root->data; 
}
sumOfParentOfX(root->left,sum,x);
sumOfParentOfX(root->right,sum,x);
}  
 int star(struct Node* root,int x)
 {
 	int sum=0;
 	sumOfParentOfX(root,sum,x);
 	return sum;
 }
int main() 
{ 
   
    Node *root = getNode(4);           
    root->left = getNode(2);          
    root->right = getNode(5);         
    root->left->left = getNode(7);      
    root->left->right = getNode(2);    
    root->right->left = getNode(2); 
    root->right->right = getNode(3); 
      
    int x = 2; 
      
    cout<<star(root, x); 
           
    return 0;     
}  

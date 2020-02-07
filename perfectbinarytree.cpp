#include<bits/stdc++.h>  
struct Node 
{ 
    int key; 
    struct Node *left, *right; 
};  
int findADepth(Node *node) 
{ 
   int d = 0; 
   while (node != NULL) 
   { 
      d++; 
      node = node->left; 
   } 
   return d; 
} 
bool isPerfectRec(struct Node* root, int d, int level = 0) 
{  
    if (root == NULL) 
        return true;  
    if (root->left == NULL && root->right == NULL) 
        return (d == level+1);  
    if (root->left == NULL || root->right == NULL) 
        return false;  
    return isPerfectRec(root->left, d, level+1) && 
           isPerfectRec(root->right, d, level+1); 
}  
bool isPerfect(Node *root) 
{ 
   int d = findADepth(root); 
   return isPerfectRec(root, d); 
}  
struct Node *newNode(int k) 
{ 
    struct Node *node = new Node; 
    node->key = k;                                        //perfect binary tree .
    node->right = node->left = NULL; 
    return node; 
}  
int main() 
{ 
    struct Node* root = NULL; 
    root = newNode(10);                                
    root->left = newNode(20); 
    root->right = newNode(30); 
  
    root->left->left = newNode(40); 
    root->left->right = newNode(50); 
    root->right->left = newNode(60); 
    root->right->right = newNode(70); 
  
    if (isPerfect(root)) 
        printf("Yes\n"); 
    else
        printf("No\n"); 
  
    return(0); 
} 

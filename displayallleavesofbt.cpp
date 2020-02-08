#include <iostream> 
using namespace std;  
struct Node 
{ 
    int key; 
    struct Node* left, *right; 
};  
Node *newNode(char k) 
{ 
    Node *node = new Node; 
    node->key = k; 
    node->right = node->left = NULL; 
    return node; 
}  
                                         //display all leaves nodes of a binary tree.
void Leavesis(Node *root) 
{  
 if(root==NULL)
 return;
 if(root->left==NULL&&root->right==NULL)
 cout<<root->key<< "";
 
     Leavesis(root->left);
     Leavesis(root->right);
     return;
}  
int main()  
{

    struct Node *root         = newNode(1); 
    root->left                = newNode(2); 
    root->right               = newNode(3); 
    root->right->left         = newNode(4); 
    root->right->right        = newNode(5); 
    root->right->right->left  = newNode(6); 
    root->left->left          = newNode(7); 
    root->left->right         = newNode(8); 
    root->left->right->right  = newNode(9); 
       Leavesis(root); 
    return 0; 
}


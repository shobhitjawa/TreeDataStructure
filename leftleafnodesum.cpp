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
bool isLeaf(Node *node) 
{ 
   if (node == NULL) 
       return false; 
   if (node->left == NULL && node->right == NULL) 
       return true; 
   return false; 
}  
int leftLeavesSumis(Node *root) 
{  
    int res = 0;  
    if (root != NULL) 
    {  
       if (isLeaf(root->left)) 
            res += root->left->key; 
       else  
            res += leftLeavesSumis(root->left);  
       res += leftLeavesSumis(root->right);         //sum of left leaves nodes .
    }  
    return res; 
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
    cout << "Sum of left leaf is :"<< leftLeavesSumis(root); 
    return 0; 
}


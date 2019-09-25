#include <iostream> 
using namespace std; 
  
struct Node { 
    int key; 
    Node* left, *right; 
};
Node* newNode(int key) 
{ 
    Node* node = new Node; 
    node->key = key; 
    node->left = node->right = NULL; 
    return (node); 
}
int addBT(Node* root) 
{
	int r,s,p;
    struct Node* curr=root;
    if (root == NULL) 
        return 0; 
     	r=curr->key;                                     //sumofallnodesrecursive
     	s=r+addBT(curr->left);
     	p=s+addBT(curr->right);
	 return p;
}
int main() 
{ 
    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
  
    int sum = addBT(root); 
    cout << "Sum of all the elements is: " << sum << endl; 
  
    return 0; 
} 

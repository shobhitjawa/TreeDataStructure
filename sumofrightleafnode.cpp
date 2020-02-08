 #include <bits/stdc++.h> 
using namespace std;  
struct Node{ 
    int data; 
    Node *left, *right; 
};  
Node *addNode(int data){ 
    Node *temp = new Node(); 
    temp->data = data; 
    temp->left = temp->right = NULL; 
}  
void rightLeafSum(Node *root, int *sum){ 
    if(!root)  
        return;  
    if(root->right) 
        if(!root->right->left  &&                       //sum of right leve node.
                     !root->right->right) 
            *sum += root->right->data; 
  
    rightLeafSum(root->left, sum); 
    rightLeafSum(root->right, sum); 
}  
int main(){  
    Node *root = addNode(1); 
    root->left = addNode(2); 
    root->left->left = addNode(4); 
    root->left->right = addNode(5); 
    root->left->left->right = addNode(2); 
    root->right = addNode(3); 
    root->right->right = addNode(8); 
    root->right->right->left = addNode(6); 
    root->right->right->right = addNode(7); 
    int sum = 0; 
    rightLeafSum(root, &sum); 
    cout << sum << endl; 
    return 0; 
} 

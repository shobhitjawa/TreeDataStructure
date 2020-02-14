#include<bits/stdc++.h> 
#include<iostream>
using namespace std; 
  
struct Node 
{ 
    int data; 
    struct Node *left, *right; 
};  
Node* newNode(int data) 
{ 
    Node *temp = new Node; 
    temp->data = data; 
    temp->left = temp->right = NULL;          //vertical sum of binary tree.
    return temp; 
}  
void verticalSumUtil(Node *node, int hd, 
                     map<int, int> &Map) 
{  
    if (node == NULL) return;  
    verticalSumUtil(node->left, hd-1, Map);  
    Map[hd] += node->data;  
    verticalSumUtil(node->right, hd+1, Map); 
}  
void verticalSum(Node *root) 
{  
    map < int, int> Map; 
    map < int, int> :: iterator it;  
    int x=0;
    verticalSumUtil(root, x, Map);  
    for (it = Map.begin(); it != Map.end(); ++it) 
    { 
        cout << it->first << ": "
             << it->second << endl; 
    } 
}  
int main() 
{  
    Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
    root->right->right->right = newNode(9); 
  
    cout << "Following are the values of vertical"
            " sums with the positions of the "
            "columns with respect to root\n"; 
    verticalSum(root); 
  
    return 0; 
} 

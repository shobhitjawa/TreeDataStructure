#include<bits/stdc++.h> 
using namespace std; 
 
struct Node 
{ 
    int data;  
    int hd;  
    Node *left, *right;  
   
//    Node(int key) 
//    { 
//        data = key; 
//        hd = INT_MAX; 
//        left = right = NULL; 
//    } 
};  

Node* newNode(int data)
{
struct Node* temp;
temp=new(struct Node);
temp->data=data;
temp->left=NULL;
temp->right=NULL;
return temp;
 } 
void bottomView(Node *root) 
{ 
    if (root == NULL) 
        return;   
    int hd = 0;  
    map<int, int> m;  
    queue<Node *> q;   
    root->hd = hd; 
    q.push(root);   
       map<int,int>::iterator itr;
    while (!q.empty()) 
    { 
        Node *temp = q.front(); 
        q.pop();                                        //bottom view of binary tree.cpp
        hd = temp->hd; 
  
       
        m[hd] = temp->data;  
        if (temp->left != NULL) 
        { 
            temp->left->hd = hd-1; 
            q.push(temp->left); 
        }  
        if (temp->right != NULL) 
        { 
            temp->right->hd = hd+1; 
            q.push(temp->right); 
        } 
    }   
      for (itr = m.begin(); itr != m.end(); ++itr) { 
      
              cout<< itr->second<<" ";
    } 
}  
//int main() 
//{ 
//    Node *root = new Node(20); 
//    root->left = new Node(8); 
//    root->right = new Node(22); 
//    root->left->left = new Node(5); 
//    root->left->right = new Node(3); 
//    root->right->left = new Node(4); 
//    root->right->right = new Node(25); 
//    root->left->right->left = new Node(10); 
//    root->left->right->right = new Node(14); 
//    cout << "Bottom view of the given binary tree :\n";
//    bottomView(root); 
//    return 0; 
//} 

int main() 
{ 
    Node *root = newNode(20); 
    root->left = newNode(8); 
    root->right = newNode(22); 
    root->left->left = newNode(5); 
    root->left->right = newNode(3); 
    root->right->left = newNode(4); 
    root->right->right = newNode(25); 
    root->left->right->left = newNode(10); 
    root->left->right->right = newNode(14); 
    cout << "Bottom view of the given binary tree :\n";
    bottomView(root); 
    return 0; 
} 

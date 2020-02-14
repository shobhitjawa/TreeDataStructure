#include <bits/stdc++.h> 
#include<iostream>
using namespace std; 
  
# define N 6  
struct Node 
{ 
    int data; 
    Node *left, *right; 
};  
Node* newNode(int data) 
{ 
    Node* node = new Node; 
    node->data = data; 
    node->left = node->right = NULL;                //construct a binary tree form ancestor matrix.
    return (node); 
}  
Node* ancestorTree(int mat[][N]) 
{  
    int parent[N] = {0};
//	cout<<N<<" and ";   
//    cout<<parent[5];
    Node* root = NULL;  
    multimap<int, int> mm; 
    multimap<int, int>::iterator itr; 
  
    for (int i = 0; i < N; i++) 
    { 
        int sum = 0;  
        for (int j = 0; j < N; j++) 
            sum += mat[i][j];  
        mm.insert(pair<int, int>(sum, i)); 
    }  
//    
//     for (itr = mm.begin(); itr != mm.end(); ++itr) 
//    {
//    	    cout << '\t' << itr->first 
//             << '\t' << itr->second << '\n'; 
//    }
    
    Node* node[N];  
    for (itr = mm.begin(); itr != mm.end(); ++itr) 
    {  
      node[itr->second] = newNode(itr->second);  
      root = node[itr->second];  
      if (itr->first != 0) 
      {  
        for (int i = 0; i < N; i++) 
        {  
           if (parent[i]==0 && mat[itr->second][i]==1) 
           {  
             if (node[itr->second]->left==NULL) 
               node[itr->second]->left = node[i]; 
             else
               node[itr->second]->right = node[i]; 
  
             parent[i] = 1; 
           } 
        } 
      } 
    } 
    return root; 
}  
void printInorder(Node* node) 
{ 
    if (node == NULL) 
        return; 
    printInorder(node->left); 
      cout<<node->data<<" ";
    printInorder(node->right); 
}  
int main() 
{ 
    int mat[N][N] = {{ 0, 0, 0, 0, 0, 0 }, 
        { 1, 0, 0, 0, 1, 0 }, 
        { 0, 0, 0, 1, 0, 0 }, 
        { 0, 0, 0, 0, 0, 0 }, 
        { 0, 0, 0, 0, 0, 0 }, 
        { 1, 1, 1, 1, 1, 0 } 
    }; 
  
    Node* root = ancestorTree(mat); 
  
    cout << "Inorder traversal of tree is \n"; 
    printInorder(root); 
  
    return 0; 
} 

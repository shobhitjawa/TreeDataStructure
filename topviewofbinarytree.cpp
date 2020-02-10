 #include <iostream>  
#include<queue>  
#include<map> 
using namespace std;  
struct Node 
{ 
    Node * left; 
    Node* right; 
    int hd; 
    int data; 
};  
Node* newNode(int key) 
{ 
    Node* node=new Node(); 
    node->left = node->right = NULL; 
    node->data=key; 
    return node; 
}  
void topview(Node* root) 
{   
      if(root==NULL)
      return;
      queue<Node*>q1;
      map<int,int>m;
        map<int,int>::iterator itr;
      int hd=0;
      root->hd=hd;
       q1.push(root);
	   while(q1.empty()==false)               //top view of binary tree.
	   {
	    hd=root->hd;
		if(m.count(hd)==0)
		{
			m[hd]=root->data;
			}	
			if(root->left!=NULL)
			{
				root->left->hd=hd-1;
				q1.push(root->left);
			}
			if(root->right!=NULL)
			{
				root->right->hd=hd+1;
				q1.push(root->right);
			}
			q1.pop();
			root=q1.front();
	   }
   for (itr = m.begin(); itr != m.end(); ++itr) { 
      
              cout<< itr->second<<" ";
    } 
  
    
}  
int main() 
{ 
    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->right = newNode(4); 
    root->left->right->right = newNode(5); 
    root->left->right->right->right = newNode(6); 
    cout<<"Following are nodes in top view of Binary Tree\n";  
    topview(root); 
    return 0; 
}

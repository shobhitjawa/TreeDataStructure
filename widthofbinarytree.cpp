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
void width(Node *root ){ 
  if(root==NULL)
  return ;
  queue<Node*>q1;
  q1.push(root);
  int count=0;
  struct Node* curr;
  int max=0;
  while(q1.empty()==false)
  {
   int width = q1.size();
        if (max < width)
           max = width;
  while(width>0)
  {
  curr=q1.front();
  cout<<curr->data<<" ";
  	q1.pop();
  	if(curr->left!=NULL)                    //maximum width of binary tree.
  	{
  		q1.push(curr->left);
	  }
	  if(curr->right!=NULL)
	  {
	  	q1.push(curr->right);
	  }
	  width--;
  } 
}
cout<<endl<<max;
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
    width(root); 
   
    return 0; 
} 

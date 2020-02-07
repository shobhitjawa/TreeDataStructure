#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node* right=NULL;
	struct node* left=NULL;
}; 
node* createnode(int data)
{
	struct node*p;
	p=new (struct node);                                       
	p->data=data;
	p->right=NULL;
	p->left=NULL;
	return p;
}
int  search(int in[],int x,int n)
{
	for(int i=0;i<n;i++)
	if(in[i]==x)
	{
		return i;
	}
	return -1;
}
void postusingprein(int in[],int pre[],int n)
{
	int a=pre[0];                           //post order using pre and in order traversals.
	int root=search(in,a,n);
	if(root!=0)
	postusingprein(in,pre+1,root);
	if(root!=n-1)
	{
		postusingprein(in+root+1,pre+root+1,n-root-1);
	}
	cout<<pre[0]<<" ";
}
int main()
{
	struct node* root;
int in[] = { 4, 2, 5, 1, 3, 6 }; 
    int pre[] = { 1, 2, 4, 5, 3, 6 }; 
    int n=sizeof(in) / sizeof(in[0]); 
    cout<<"postorder traversal"<<endl;
     postusingprein(in,pre,n);
	return 0;
}

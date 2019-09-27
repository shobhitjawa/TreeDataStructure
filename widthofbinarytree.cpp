#include<stdio.h>
#include<iostream>
#include<queue>
#include<list>
using namespace std;
struct node{
	int data;
	struct node* left;
	struct node* right;
};
node* createnode(int data)
{
	struct node* p;
	p=new (struct node);
	p->data=data;
	p->left=NULL;
	p->right=NULL;
	return p;
}
void width(node* root)
{

    if (root == NULL)
        return;
    list<node*> l1;
    l1.push_back(root);
    node* curr = NULL;
    int max = 0;
    while (l1.empty()==false)                         //maximum width of binary tree.
    {
        int width = l1.size();
        if (max < width)
           max = width;
        while (width--)
        {
           curr = l1.front();
           l1.pop_front();

           if (curr->left)
                l1.push_back(curr->left);

           if (curr->right)
                l1.push_back(curr->right);
        }
    }

    cout << "Maximum width is " << max;
}

int main()
{
struct node* root=createnode(1);
root->left=createnode(2);
root->right=createnode(3);
root->left->left=createnode(4);
root->left->right=createnode(5);
root->right->left=createnode(6);
root->right->right=createnode(7);
width(root);
return 0;	
}

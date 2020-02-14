#include<bits/stdc++.h> 
#include<iostream>
using namespace std; 
char tree[10]; 
int root(char k) 
{ 
    if(tree[0] != '\0') 
        cout << "Tree already had root"; 
    else
        tree[0] = k; 
    return 0; 
} 
  
int set_left(char k, int parent)         //array represasentation of binary tree.
{  
    if(tree[parent] != '\0') 
        
         tree[(parent * 2) + 1] = k; 
 
    else
      cout << "\nCan't set child"; 
    return 0; 
} 
  
int set_right(char k, int parent) 
{ 
    if(tree[parent] != '\0') 
         tree[(parent * 2) + 2] = k; 
    else
      cout << "\nCan't set child"; 
    return 0; 
} 
  
int print_tree() 
{ 
    cout << "\n"; 
    for(int i = 0; i < 10; i++) 
    { 
        if(tree[i] != '\0') 
            cout << tree[i]; 
        else
            cout << "-"; 
    } 
    return 0; 
}  
int main() 
{ 
    root('A');  
    set_right('C', 0); 
    set_left('D', 1); 
    set_right('E', 1); 
    set_right('F', 2); 
    print_tree(); 
    return 0; 
} 
  

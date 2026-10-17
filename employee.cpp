#include <iostream>
using namespace std;
struct Node
{ 
int data; 
Node *left,*right; 
Node(int d)
{
  data=d; 
  left=right=NULL;
} 
};
Node* insert(Node* root,int d)
{ 
  if(!root) 
    return new Node(d); 
  if(d<root->data)
    root->left=insert(root->left,d);
  else
    root->right=insert(root->right,d);
  return root; 
}
void inorder(Node* r)
{
  if(r)
  { 
    inorder(r->left); 
    cout<<r->data<<" "; 
    inorder(r->right); 
  }
}
void preorder(Node* r)
{ 
  if(r)
  {
    cout<<r->data<<" ";
    preorder(r->left); 
    preorder(r->right); 
  } 
}
int main()
{
  Node* root=NULL; 
  int arr[]={50,30,70,20,40,60,80};
  for(int x:arr)
    root=insert(root,x); 
  cout<<"Inorder: "; 
  inorder(root); 
  cout<<"\nPreorder: "; 
  preorder(root); 
  return 0; 
}

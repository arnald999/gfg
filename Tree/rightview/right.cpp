#include <iostream>
#include <list>
using namespace std;

class Node
{
	public:
		int data;
		Node *left, *right;
};

Node* newnode(int n)
{
	Node *temp = new Node();
	temp->data = n;
	temp->left = temp->right = NULL;
	return temp;
}

void rightUtil(Node *root, int level, int &max_level)
{
	if(root==NULL)
		return;
		
	if(max_level<level)
	{
		cout<<root->data<<" ";
		max_level = level; 
	}
	
	rightUtil(root->right,level+1,max_level);
	rightUtil(root->left,level+1,max_level);
}

void rightview(Node *root)
{
	int max_level = 0;
	rightUtil(root,1,max_level);
}

int main()
{
	Node *root = newnode(12);  
	root->left = newnode(10);  
	root->right = newnode(30);  
	root->right->left = newnode(25);  
	root->right->right = newnode(40);  

	rightview(root);  
	return 0;
}

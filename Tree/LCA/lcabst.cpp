#include <iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *left, *right;
};

Node *newnode(int key)
{
	Node *temp = new Node();
	temp->data = key;
	temp->left = temp->right = NULL;
	return temp;
}

Node *insert(Node *root, int key)
{
	if(root == NULL)
		return newnode(key);
		
	if(key < root->data)
		root->left = insert(root->left, key);
	
	else
		root->right = insert(root->right, key);
	
	return root;
}
/*
Node *lca(Node *root, int n1, int n2)
{
	if(root == NULL)
		return NULL;
		
	if(root->data>n1 && root->data>n2)
		return lca(root->left, n1, n2);
	
	if(root->data<n1 && root->data<n2)
		return lca(root->right,n1 ,n2);
	return root;
}
*/
Node *lca(Node *root, int n1, int n2)
{
	while(root != NULL)
	{
		if(root->data>n1 && root->data>n2)
			root = root->left;
		
		else if(root->data<n1 && root->data<n2)
			root = root->right;
			
		else
			break;
	}
	return root;
}

int main()
{
	Node* root = nullptr;
	int keys[] = { 15, 10, 20, 8, 12, 16, 25 };

	for (int key : keys)
		root = insert(root, key);

	// swap nodes
	//swap(root->left, root->right);
	Node *temp = lca(root,16,25);
	cout<<temp->data<<endl;
	
	return 0;
}

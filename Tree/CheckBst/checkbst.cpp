#include <iostream>
#include <climits>
using namespace std;

class Node
{
	public:
		int data;
		Node *left, *right;
}

Node* newnode(int n)
{
	Node *temp = new Node();
	temp->data = n;
	temp->left = temp->right = NULL;
	return temp;
}

Node* insert(Node *root, int key)
{
	if(root == NULL)
		return newnode(key);
	
	if(key < root->data)
		root->left = insert(root->left, key);
	
	else if(key > root->data)
		root->right = insert(root->right, key);
	
	return root;
}

bool checkbst(Node *node, int min, int max)
{
	if(node == NULL)
		return true;
	
	if(node->data<min || node->data>max)
		return false;
		
	else
		return checkbst(node->left,min,node->data) && checkbst(node->right,node->data,max);
}

void isBST(Node *root)
{
	if(checkbst(root, INT_MIN, INT_MAX))
		cout<<"BST"<<endl;
	else
		cout<<"Not BST"<<endl;
}

int main()
{
	Node* root = NULL;
	int keys[] = { 15, 10, 20, 8, 12, 16, 25 };

	for (int key : keys)
		root = insert(root, key);

	// swap nodes
	//swap(root->left, root->right);
	isBST(root);

	return 0;
}	

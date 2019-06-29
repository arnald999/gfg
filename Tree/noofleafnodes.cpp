#include <iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *left, *right;
		
		Node(int key)
		{
			this->data = key;
			this->left = this->right;
		}
};


int leafcount(Node *root)
{
	if(root == NULL)
		return 0;
		
	if(root->left == NULL && root->right == NULL)
		return 1;
		
	return leafcount(root->left) + leafcount(root->right);
}

int main()
{
	Node *root = NULL;
	root = new Node(0);
	root->left = new Node(1);
	root->right = new Node(2);
	root->left->left = new Node(3);
	root->left->right = new Node(4);
	
	cout<<leafcount(root)<<endl;
	
	return 0;
}

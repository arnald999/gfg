#include <iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *left, *right;
		
		Node(int n)
		{
			this->data = n;
			this->left = this->right = NULL;
		}
};


bool printlevellefttoright(Node *root, int level)
{
	if(root == NULL)
		return false;
	
	if(level == 1)
	{
		cout<<root->data<<" ";
		return true;
	}
	
	bool left = printlevellefttoright(root->left, level - 1);
	bool right = printlevellefttoright(root->right, level - 1);

	return left || right;
}


bool printlevelrighttoleft(Node *root, int level)
{
	if(root == NULL)
		return false;
	
	if(level == 1)
	{
		cout<<root->data<<" ";
		return true;
	}
		
	bool right = printlevelrighttoleft(root->right, level - 1);
	bool left = printlevelrighttoleft(root->left, level - 1);

	return right || left;
}


void spiralordertraversal(Node *root)
{
	if(root==NULL)
		return;
	
	int level = 1;
	
	while (printlevellefttoright(root, level++) && printlevelrighttoleft(root, level++));
}


int main()
{
	Node* root = nullptr;

	root = new Node(15);
	root->left = new Node(10);
	root->right = new Node(20);
	root->left->left = new Node(8);
	root->left->right = new Node(12);
	root->right->left = new Node(16);
	root->right->right = new Node(25);

	spiralordertraversal(root);

	return 0;
}

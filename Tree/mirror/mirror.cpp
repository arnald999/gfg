//postorder traversal

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


void preorder(Node *root)
{
	if(root==NULL)
		return;
	
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

bool converttomirror(Node *root)
{
	if(root == NULL)
		return true;
		
	converttomirror(root->left);
	converttomirror(root->right);
	swap(root->left, root->right);
}


int main()
{
	Node* root = nullptr;
	root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	preorder(root);
	cout<<endl;
	converttomirror(root);
	preorder(root);
	cout<<endl;

    return 0;
}

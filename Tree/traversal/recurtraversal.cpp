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
			this->left = this->right = nullptr;
		}
};

void inorder(Node *root)
{
	if(root == NULL)
		return;
	
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void preorder(Node *root)
{
	if(root == NULL)
		return;
	
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(Node *root)
{
	if(root == NULL)
		return;
	
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
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

	cout<<"inorder : ";
	inorder(root);
	cout<<endl<<"preorder : ";
	preorder(root);
	cout<<endl<<"postorder : ";
	postorder(root);
	cout<<endl;

	return 0;
}

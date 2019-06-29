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

int height(Node *root)
{
	if(root == NULL)
		return 0;
	
	return 1+max(height(root->left), height(root->right));
}

bool isBalanced(Node *root)
{
	if(root == NULL)
		return true;
		
	int lh = height(root->left);
	int rh = height(root->right);
	
	if(abs(lh-rh)<=1 && (isBalanced(root->left)) && (isBalanced(root->right)))
		return true;
	
	return false;
}


int main()
{
	Node* root = nullptr;
    
	root = new Node(15);
	root->left = new Node(10);
	root->right = new Node(20);
	//root->left->left = new Node(8);
	//root->left->right = new Node(12);
	//root->right->left = new Node(16);
	root->right->right = new Node(25);
	root->right->right->left = new Node(5);

	if(isBalanced(root))
		cout<<"Height balanced"<<endl;
	else
		cout<<"Not balanced"<<endl;

	return 0;
}

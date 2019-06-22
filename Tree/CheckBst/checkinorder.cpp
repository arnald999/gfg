#include <iostream>
#include <climits>
using namespace std;

class Node
{
	public:
		int data;
		Node *left, *right;
};

Node* newNode(int key)
{
	Node* node = new Node;
	node->data = key;
	node->left = node->right = nullptr;

	return node;
}

Node* insert(Node* root, int key)
{
	if (root == nullptr)
		return newNode(key);
		
	if (key < root->data)
		root->left = insert(root->left, key);
	else
		root->right = insert(root->right, key);

	return root;
}


bool isBST(Node* root, Node* &prev)
{
	if (root == nullptr)
		return true;

	bool left = isBST(root->left, prev);

	if (root->data <= prev->data)
		return false;

	prev = root;
	return left && isBST(root->right, prev);
}

void isBST(Node* node)
{
	Node* prev = newNode(INT_MIN);

	if (isBST(node, prev))
		printf("This is a BST.");
	else
		printf("This is NOT a BST!");
}


int main()
{
	Node* root = nullptr;
	int keys[] = { 15, 10, 20, 8, 12, 16, 25 };

	for (int key : keys)
		root = insert(root, key);

	// swap nodes
	//swap(root->left, root->right);
	isBST(root);

	return 0;
}

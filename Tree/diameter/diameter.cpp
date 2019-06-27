//postorder
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

int diameter(Node *root, int &dia)
{
	if(root==NULL)
		return 0;
	
	int left_ht = diameter(root->left , dia);
	int right_ht = diameter(root->right, dia);
	
	int max_dia = left_ht + right_ht + 1;
	
	dia = max(dia, max_dia);
	
	return max(left_ht, right_ht) + 1;
}

int getDiameter(Node *root)
{
	int dia = 0;
	diameter(root, dia);
	return dia;
}

int main()
{
	Node* root = nullptr;

	root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->right = new Node(4);
	root->right->left = new Node(5);
	root->right->right = new Node(6);
	root->right->left->left = new Node(7);
	root->right->left->right = new Node(8);

	cout << "The diameter of the tree is " << getDiameter(root)<<endl;

	return 0;
}

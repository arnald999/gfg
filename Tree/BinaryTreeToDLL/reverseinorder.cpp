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
			this->left = this->right =NULL;
		}
};

void printDLL(Node *&head)
{
	Node *temp = head;
	while(temp)
	{
		cout<<temp->data<<" ";
		temp = temp->right;
	}
}

void convert(Node *root, Node *&head)
{
	if(root == NULL)
		return;
		
	convert(root->right, head);
	
	root->right = head;
	if(head != NULL)
		head->left = root;
	
	head = root;
	
	convert(root->left, head);
}

void convert(Node *root)
{
	Node *head = NULL;
	
	convert(root, head);
	printDLL(head);
}

int main()
{
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	convert(root);

}

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


void printDLL(Node *&head)
{
	Node *curr = head;
	while(curr!=NULL)
	{
		cout<<curr->data<<" ";
		curr = curr->right;
	}
}

void convert(Node *root, Node *&head)
{
	if(root == NULL)
		return;
		
	convert(root->left, head);
	
	Node *right = root->right;
	root->right = head;
	if(head != NULL)
		head->left = root;
	
	head = root;

	convert(right, head);
}

void reverse(Node *&head)
{
	Node *prev = NULL;
	Node *curr = head;
	
	while(curr)
	{
		swap(curr->left, curr->right);
		prev = curr;
		curr = curr->left;
	}
	
	if(prev != NULL)
		head = prev;
}

void convert(Node *root)
{
	Node *head = NULL;
	convert(root, head);
	reverse(head);
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

	return 0;
}

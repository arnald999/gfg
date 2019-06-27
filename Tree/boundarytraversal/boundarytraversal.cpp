#include <iostream>
#include <list>
using namespace std;

class Node
{
	public:
		int data;
		Node *left, *right;
		
		Node(int n)
		{
			this->data = n;
			this->left =this->right = NULL;
		}
};


void printLeft(Node *p, bool print)
{
	if(!p)
		return;
	
	if(print || (!p->left && !p->right))
		cout<<p->data<<" ";
	
	printLeft(p->left, print);
	printLeft(p->right, false);
}

void printRight(Node *p, bool print)
{
	if(!p)
		return;
		
	printRight(p->left, false);
	printRight(p->right, print);
	
	if(print || (!p->left && !p->right))
		cout<<p->data<<" ";	
}

void printOuter(Node *root)
{
	if(!root)
		return;
	
	cout<<root->data<<" ";
	printLeft(root->left, true);
	printRight(root->right, true);
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

    printOuter(root);

    return 0;
}

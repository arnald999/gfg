#include <iostream>
#include <list>
using namespace std;

class Node
{
	public:
		int data;
		Node *left, *right;
		
		Node(int data)
		{
			this->data = data;
			this->left = this->right = NULL;
		}
};


int height(Node *root)
{
	if(root==NULL)
		return 0;
	
	list<Node*> queue;
	queue.push_back(root);
	
	
	int ht = 0;
	Node *curr = NULL;
	while(!queue.empty())
	{
		int size = queue.size();
		
		while(size--)
		{
			curr = queue.front();
			queue.pop_front();
			
			if(curr->left)
				queue.push_back(curr->left);
			
			if(curr->right)
				queue.push_back(curr->right);
		}
		ht++;
	}
	return ht;
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

	cout << "The height of the binary tree is " << height(root)<<endl;

	return 0;
}

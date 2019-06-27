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
			this->left = this->right = NULL;
		}
};

void nextnode(Node *root, Node *curr)
{
	if(root == NULL)
		return;
	
	list<Node*> queue;
	queue.push_back(root);
	
	Node *temp = NULL;
	
	while(!queue.empty())
	{
		int size = queue.size();
		int i = 0;
		
		while(i++ < size)
		{
			temp = queue.front();
			queue.pop_front();
			
			if(temp == curr)
			{
				if(i!=size)
				{
					Node *t = queue.front();
					queue.pop_front();
					cout<<t->data<<endl;
					return;
				}
				else
				{
					cout<<"NULL"<<endl;
					return;
				}
			}
			
			if(temp->left)
				queue.push_back(temp->left);
			
			if(temp->right)
				queue.push_back(temp->right);
		}
	}
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

	nextnode(root,root->right->right);

	return 0;
}

#include <iostream>
#include <queue>
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
	//vector<Node*> vec;
	queue<Node*> q;
	q.push(root);
	
	bool flag = false;
	while(!q.empty() && !flag)
	{
		int size = q.size();
		while(size--)
		{
			Node *ncurr = q.front();
			q.pop();
			
			if(ncurr->left==curr || ncurr->right==curr)
			{
				flag = true;    
				continue;
			}
			if(ncurr->left)
				q.push(ncurr->left);
			if(ncurr->right)
				q.push(ncurr->right);
		}
	}
	
	while(!q.empty())
	{
		Node *ncurr = q.front();
		q.pop();
		
		cout<<ncurr->data<<endl;
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
	
	
	//root->left->left->left = new Node(8);
	root->left->right->left = new Node(12);
	root->left->left->right = new Node(8);
	root->left->right->right = new Node(12);
	root->right->left->left = new Node(16);
	root->right->left->right = new Node(16);
	root->right->right->left = new Node(25);
	root->right->right->right = new Node(25);

	
	nextnode(root,root->right->right->right);

	return 0;
}

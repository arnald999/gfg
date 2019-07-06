#include <iostream>
#include <list>
using namespace std;

class Node
{
	public:
		int data;
		Node *left, *right;
};

Node* newnode(int n)
{
	Node *temp = new Node();
	temp->data = n;
	temp->left = temp->right = NULL;
	return temp;
}

void rightview(Node *root)
{
	if(root == NULL)
		return;
	
	list<Node*> queue;
	queue.push_back(root);
	
	Node *curr;
	while(!queue.empty())
	{
		int size = queue.size();
		int i = 0;
		
		while(i++ < size)
		{
			curr = queue.front();
			queue.pop_front();
			
			if(i == size)
				cout<<curr->data<<" ";
				
			if(curr->left)
				queue.push_back(curr->left);
			
			if(curr->right)
				queue.push_back(curr->right);
		}
	}
	cout<<endl;
}

int main()
{
	Node *root = newnode(12);  
	root->left = newnode(10);  
	root->right = newnode(30);  
	root->right->left = newnode(25);  
	root->right->right = newnode(40);  

	rightview(root);  
	return 0;
}

#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Node
{
	public:
		int data;
		Node *left, *right;
		
		Node(int key)
		{
			this->data = key;
			this->left = this->right = nullptr;
		}
};

void inorder(Node *root)
{
	stack<Node*> stk;
	Node *curr = root;
	
	while(!stk.empty() || curr != NULL)
	{
		if(curr!=NULL)
		{
			stk.push(curr);
			curr = curr->left;
		}
		else
		{
			curr = stk.top();
			stk.pop();
			cout<<curr->data<<" ";
			curr = curr->right;
		}
	}
}

void preorder(Node *root)
{
	if(root == NULL)
		return;
		
	stack<Node*> stk;
	stk.push(root);
	Node *curr = NULL;
	
	while(!stk.empty())
	{
		curr = stk.top();
		stk.pop();
		
		cout << curr->data << " ";
		
		if (curr->right)
			stk.push(curr->right);
		
		if (curr->left)
			stk.push(curr->left);

	}
}

void postorder(Node *root)
{
	stack<Node*> stk;
	stk.push(root);

	stack<int> out;

	while (!stk.empty())
	{
		Node *curr = stk.top();
		stk.pop();

		out.push(curr->data);

		if (curr->left)
			stk.push(curr->left);

		if (curr->right)
			stk.push(curr->right);
	}

	while (!out.empty())
	{
		cout << out.top() << " ";
		out.pop();
	}
}

void levelorder(Node *root)
{
	list<Node*> queue;
	queue.push_back(root);

	
	Node* curr = nullptr;

	while (queue.size())
	{
	
		curr = queue.front();
		queue.pop_front();

		cout << curr->data << " ";

		if (curr->left)
		   	queue.push_back(curr->left);

		if (curr->right)
		   	queue.push_back(curr->right);
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

	cout<<"inorder : ";
	inorder(root);
	cout<<endl<<"preorder : ";
	preorder(root);
	cout<<endl<<"postorder : ";
	postorder(root);
	cout<<endl<<"levelorder : ";
	levelorder(root);
	cout<<endl;

	return 0;
}

#include <iostream>
#include <stack>
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

bool isIdentical(Node *x, Node *y)
{
	if (x == nullptr && y == nullptr)
		return true;

	if (x == nullptr)
		return false;

	if (y == nullptr)
		return false;

	stack<pair<Node*, Node*>> stack;
	stack.push({x, y});

	while (!stack.empty())
	{
		Node *x = stack.top().first;
		Node *y = stack.top().second;
		stack.pop();

		if (x->data != y->data)
			return false;

		if (x->left && y->left)
		   	stack.push({x->left, y->left});
		else if (x->left || y->left)
		   	return false;

		if (x->right && y->right)
		   	stack.push({x->right, y->right});
		else if (x->right || y->right)
		   	return false;
	}

	return true;
}

int main()
{
	// construct first tree
	Node* x = nullptr;

	x = new Node(15);
	x->left = new Node(10);
	x->right = new Node(20);
	x->left->left = new Node(8);
	x->left->right = new Node(12);
	x->right->left = new Node(16);
	x->right->right = new Node(25);

	// construct second tree
	Node* y = nullptr;

	y = new Node(15);
	y->left = new Node(10);
	y->right = new Node(20);
	y->left->left = new Node(8);
	y->left->right = new Node(12);
	y->right->left = new Node(16);
	y->right->right = new Node(25);

	if (isIdentical(x, y))
	cout << "Given binary Trees are identical"<<endl;
	else
	cout << "Given binary Trees are not identical"<<endl;

	return 0;
}

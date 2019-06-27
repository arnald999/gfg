#include <iostream>
#include <map>
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


void printbottom(Node *root)
{
	if (!root) return;
	map<int, int> mp;
	queue<pair <Node *, int >> q;
	mp[0] = root->data;
	q.push({root, 0});

	while (!q.empty())
	{
		int size = q.size();
		while (size--)
		{
			root = q.front().first;
			int level = q.front().second;
			q.pop();
			mp[level] = root->data;
			if (mp.find(level) == mp.end())
  				cout<< root->data<<endl;
			if (root->left) q.push({root->left, level - 1});
			if (root->right) q.push({root->right, level + 1});
		}
	}

	map<int, int>::iterator itr;
	for (itr = mp.begin(); itr != mp.end(); itr++)
	{
		cout << itr->second << " ";
	}
	cout << endl;
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

	printbottom(root);

	return 0;
}

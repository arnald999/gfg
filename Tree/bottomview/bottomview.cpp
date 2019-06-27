#include <iostream>
#include <map>
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


void printbottom(Node *node, int dist, int level, auto &map)
{
	if(node==NULL)
		return;
	
	if(level >= map[dist].second)
	{
		map[dist] = {node->data, level};
	}
	printbottom(node->left, dist - 1, level + 1, map);
	printbottom(node->right, dist + 1, level + 1, map);
}

void printbottom(Node *root)
{
	map<int, pair<int,int>> map;
	printbottom(root,0,0,map);
	for(auto it:map)
		cout<<it.second.first<<" ";
	cout<<endl;
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

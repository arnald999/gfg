//Inorder is necessary to construct tree

#include <iostream>
#include <vector>
#include <unordered_map>
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

void inorder(Node *root)
{
	if(root==NULL)
		return;
		
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right); 
}

void preorder(Node *root)
{
	if(root==NULL)
		return;
	
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

Node *construct(int start, int end, vector<int> const &preorder, int &pindex, unordered_map<int,int> &map)
{
	if(start > end)
		return NULL;
	
	Node *root = new Node(preorder[pindex++]);
	
	int index = map[root->data];
	root->left = construct(start, index-1, preorder, pindex, map);
	root->right = construct(index+1, end, preorder, pindex, map);
	
	return root;
}

Node *construct(vector<int> const &inorder, vector<int> const &preorder)
{
	int n = inorder.size();
	
	unordered_map<int, int> map;
	for(int i = 0; i<n ;i++)
		map[inorder[i]] = i;
	
	int pIndex = 0;
	return construct(0,n-1,preorder,pIndex,map);
}

int main()
{
	vector<int> inord = { 4, 2, 1, 7, 5, 8, 3, 6 };
	vector<int> preord = { 1, 2, 4, 3, 5, 7, 8, 6 };

	Node* root = construct(inord, preord);

	// traverse the constructed tree
	cout << "Inorder  : ";
	inorder(root);
	cout << "\nPreorder : "; 
	preorder(root);
	cout<<endl;

	return 0;
}



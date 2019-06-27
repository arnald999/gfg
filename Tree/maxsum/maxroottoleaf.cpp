//postorder bottom up
//O(n)
#include <iostream>
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

bool printpath(Node *root, int sum)
{
	if(sum==0)
		return true;
	
	if(root == NULL)
		return false;
		
	bool left = printpath(root->left, sum-(root->data));
	bool right = printpath(root->right, sum-(root->data));
	
	if (left || right)
        	cout << root->data << " ";

	return left || right;
}


int roottoleafsum(Node *root)
{
	if(root == NULL)
		return 0;
	
	int left = roottoleafsum(root->left);
	int right = roottoleafsum(root->right);
	
	return (left > right ? left : right) + root->data;
}


void findmaxpath(Node *root)
{
	int sum = roottoleafsum(root);
	cout<<"Max sum is :"<<sum<<endl;
	cout<<"Max sum path : ";
	printpath(root, sum);
	cout<<endl;
}

int main()
{
	Node* root = nullptr;
   
    	root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(8);
	root->left->right = new Node(4);
	root->right->left = new Node(5);
	root->right->right = new Node(6);
	root->left->right->left = new Node(10);
	root->right->left->left = new Node(7);
	root->right->left->right = new Node(9);
	root->right->right->right = new Node(5);

    	findmaxpath(root);

    	return 0;
}

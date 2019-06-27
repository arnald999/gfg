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

Node *LCA(Node *root, Node *A, Node *B)
{
	if(root == NULL)
		return NULL;
		
	if(root == A || root == B)
		return root;
		
	Node *left = LCA(root->left, A, B);
	Node *right = LCA(root->right, A, B);
	
	if(left != NULL && right !=NULL)
		return root;
		
	if(left == NULL)
		return right;
		
	else
		return left; 
}

int main()  
{  
    Node *root = new Node(12);  
    root->left = new Node(10);  
    root->right = new Node(30);  
    root->right->left = new Node(25);  
    root->right->right = new Node(40);  
  
    Node *temp = LCA(root, root->right, root->right->left);
    cout<<temp->data<<endl;  
  
    return 0;  
}

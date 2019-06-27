#include <iostream>
#include <list>
using namespace std;

class BinaryTree
{
	public:
		int data;
		BinaryTree *left, *right;
		
		BinaryTree(int n)
		{
			this->data = n;
			this->left = this->right = NULL;
		}
];


void traverse(BinaryTree *root)
{
  if (!root) return;
  cout << p->data << " ";
  if (root->left ) traverseL(root->left ); //special function for outer left
  if (root->right) traverseR(root->right); //special function for outer right
}

void traverseL(BinaryTree *p)
{
  cout << p->data << " ";
  if (root->left ) traverseL(root->left ); //still in outer left
  if (root->right) traverseC(root->right); 
}

void traverseR(BinaryTree *p)
{
  if (root->left ) traverseC(root->left );
  if (root->right) traverseR(root->right); //still in outer right
  cout << p->data << " ";
}

void traverseC(BinaryTree *p)
{
  if (!root->left && !root->right) //bottom reached
    cout << p->data << " ";
  else
  {
    if (root->left ) traverseC(root->left );
    if (root->right) traverseC(root->right);
  }
}

int main()
{
    BinaryTree* root = nullptr;
    
    root = new BinaryTree(15);
    root->left = new BinaryTree(10);
    root->right = new BinaryTree(20);
    root->left->left = new BinaryTree(8);
    root->left->right = new BinaryTree(12);
    root->right->left = new BinaryTree(16);
    root->right->right = new BinaryTree(25);

    traverse(root);

    return 0;
}

int main()

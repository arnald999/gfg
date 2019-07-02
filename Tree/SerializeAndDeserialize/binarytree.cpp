//BST 				-> 	Only Preorder or Only postorder
//Complete Binary Tree/Heaps 	-> 	Level order traversal
//Full Binary Tree		->	Preorder traversal

//General Binary Tree		->	Inorder and Preorder 	or 	PreOrder and marker for NULL pointer


#include <iostream>
#include <stdio.h> 
#define MARKER -1
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


void serialize(Node *root, FILE *fp)
{
	if(root == NULL)
	{
		fprintf(fp,"%d ", MARKER);
		return;
	}
	
	fprintf(fp,"%d ",root->data);
	serialize(root->left, fp);
	serialize(root->right, fp);
}


void deserialize(Node *&root, FILE *fp)
{
	int val;
	if(!fscanf(fp, "%d ", &val) || val == MARKER)
		return;
		
	root = new Node(val);
	deserialize(root->left, fp);
	deserialize(root->right, fp);
}


void inorder(Node *root)
{
	if(root==NULL)
		return;
		
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right); 
}

int main()
{
	Node *root = NULL;
	root = new Node(5);
	root->left = new Node(1);
	root->right = new Node(2);
	root->left->left = new Node(3);
	root->left->right = new Node(4);
	
	FILE *fp = fopen("tree.txt","w");
	if (fp == NULL) 
	{ 
		puts("Could not open file"); 
		return 0; 
	}
	inorder(root);
	serialize(root, fp); 
    	fclose(fp);
	
	cout<<endl;
	
	Node *root1 = NULL;
	
	fp = fopen("tree.txt", "r"); 
    	deserialize(root1, fp);
    	inorder(root1);
    	cout<<endl;
	return 0;
}



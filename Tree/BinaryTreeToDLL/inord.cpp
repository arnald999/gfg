#include <iostream>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

// Helper function to print given doubly linked list
void printDLL(Node* &head)
{
    Node* curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->right;
    }
}

// Function to in-place convert given Binary Tree to a Doubly Linked List

// root -> current node
// head -> head of the doubly linked list (Passed by reference)
// prev -> previous processed node (Passed by reference)
void convert(Node* curr, Node*& head, Node* &prev)
{
    // base case: tree is empty
    if (curr == nullptr)
        return;

    // recursively convert left subtree first
    convert(curr->left, head, prev);

    // adjust pointers
    if (prev != nullptr)
    {
        // set current node's left child to prev
        curr->left = prev;

        // make prev's right child as curr
        prev->right = curr;
    }

    // if prev is null, then update head of DLL as this is first node in inorder
    else
        head = curr;

    // after current node is visited, update previous pointer to current node
    prev = curr;

    // recursively convert right subtree
    convert(curr->right, head, prev);
}

// in-place convert given Binary Tree to a Doubly Linked List
void convert(Node* root)
{
    // to keep track of previous processed node in inorder traversal
    Node* prev = nullptr;

    // convert above binary tree to DLL (using inorder traversal)
    convert(root, root, prev);

    // root is now head of doubly linked list

    // print list
    printDLL(root);
}

// main function
int main()
{
    /* Construct below tree
			  1
		   /     \
		  2       3
		 / \     / \
		4   5   6   7
    */

    Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

    convert(root);

    return 0;
}

#include <iostream>
#include <queue>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
    int key;
    Node *left, *right;

    Node(int key)
    {
        this->key = key;
        this->left = this->right = nullptr;
    }
};

// Recursive function to delete given binary tree
void deleteBinaryTree(Node* &root)
{
    // empty tree
    if (root == nullptr)
        return;

    // create an empty queue and enqueue root node
    queue<Node*> queue;
    queue.push(root);

    Node *front = nullptr;

    // run till queue is not empty
    while (!queue.empty())
    {
        // delete each node in the queue one by one after pushing their
        // non-empty left and right child to the queue
        front = queue.front();
        queue.pop();

        if (front->left)
           queue.push(front->left);

        if (front->right)
           queue.push(front->right);

        // Important - delete front node ONLY after enqueuing its children
        delete front;
    }

    // set root as NULL before returning
    root = nullptr;
}


// main function
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

    // delete entire tree
    deleteBinaryTree(root);

    if (root == nullptr)
        cout << "Tree Successfully Deleted";

    return 0;
}

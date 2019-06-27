#include <iostream>
#include <list>
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

// Function to find maximum width of the tree using level order
// traversal of given binary tree
void maxWidth(Node* root)
{
    // return if tree is empty
    if (root == nullptr)
        return;

    // create an empty queue and enqueue root node
    list<Node*> queue;
    queue.push_back(root);

    // pointer to store current node
    Node* curr = nullptr;

    // stores maximum width
    int max = 0;

    // run till queue is not empty
    while (!queue.empty())
    {
        // calculate number of nodes in current level
        // This is equal to width of current level
        int width = queue.size();

        // update maximum width if number of nodes in current level
        // is more than maximum width found so far
        if (max < width)
           max = width;

        // process every node of current level and enqueue their
        // non-empty left and right child to queue
        while (width--)
        {
           curr = queue.front();
           queue.pop_front();

           if (curr->left)
                queue.push_back(curr->left);

           if (curr->right)
                queue.push_back(curr->right);
        }
    }

    cout << "Maximum width is " << max;
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

    maxWidth(root);

    return 0;
}

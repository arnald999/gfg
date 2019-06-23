#include <iostream>
#include <list>
using namespace std;

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

void spiralOrderTraversal(Node* root)
{
    if (root == nullptr)
        return;

    list<Node*> deque;     // or use deque
    deque.push_front(root);

    bool flag = false;

    while (!deque.empty())
    {
        int nodeCount = deque.size();

	//print left to right
        if (flag)
        {
           while (nodeCount)
           {
                Node* curr = deque.front();
                deque.pop_front();

                cout << curr->key << " ";


                if (curr->left != nullptr)
                    deque.push_back(curr->left);

                if (curr->right != nullptr)
                    deque.push_back(curr->right);

                nodeCount--;
           }
        }

        // print right to left
        else
        {
           while (nodeCount)
           {
                Node* curr = deque.back();
                deque.pop_back();

                cout << curr->key << " ";   // print front node

                if (curr->right != nullptr)
                    deque.push_front(curr->right);

                if (curr->left != nullptr)
                    deque.push_front(curr->left);

                nodeCount--;
           }
        }

        // flip the flag for next level
        flag = !flag;
        cout << endl;
    }
}

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

    spiralOrderTraversal(root);

    return 0;
}

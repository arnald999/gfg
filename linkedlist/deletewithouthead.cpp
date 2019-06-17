#include <iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
};

void push(Node **rehead, int n)
{
	Node *temp = new Node();
	temp->data = n;
	temp->next = *rehead;
	*rehead = temp;
}

void print(Node *head)
{
	Node *temp = head;
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

void deletenode(Node *node_ptr)  
{  
    Node *temp = node_ptr->next;  
    node_ptr->data = temp->data;  
    node_ptr->next = temp->next;  
    delete temp;  
}  

int main()
{
	Node *head =NULL;
	for(int i=1;i<=5; i++)
	{
		push(&head,i);
	}
	print(head);
	deletenode(head->next);
	print(head);
	return 0;
}

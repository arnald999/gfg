#include <iostream>
using namespace std;

class Node 
{
	public:
		int data;
		Node* next;
};

void push(Node **rehead, int n)
{
	Node *temp = new Node();
	
	temp->data = n;
	temp->next = (*rehead);
	
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


void rotate(Node **rehead, int k)
{
	Node *temp = *rehead;
	
	for(int i=1; i<k; i++)
	{
		temp = temp->next;
	}
	
	Node *newhead = temp->next;
	Node *curr = temp->next;
	temp->next = NULL;
	
	while(newhead->next != NULL)
	{
		newhead = newhead->next;
	}
	
	newhead->next = *rehead;
	*rehead = curr;
}

int main()
{
	Node *head =NULL;
	for(int i=1;i<=5; i++)
	{
		push(&head,i);
	}
	print(head);
	rotate(&head,2);
	print(head);
	return 0;
}


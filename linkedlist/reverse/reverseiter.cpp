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


void reverse(Node **rehead)
{
	Node *prev = NULL;
	Node *curr = NULL;
	Node *next = *rehead;
	
	while(next != NULL)
	{
		curr = next;
		next = curr->next;
		
		curr->next = prev;
		prev = curr;
	}
	
	*rehead = curr;
}

int main()
{
	Node *head = NULL;
	for(int i =0; i<=5; i++)
	{
		push(&head,i);
	}
	print(head);
	reverse(&head);
	print(head);
	return 0;
}

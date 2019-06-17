#include <iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
};

Node *head = NULL;

void push(Node **rehead, int n)
{
	Node *temp = new Node();
	temp->data = n;
	temp->next = (*rehead);
	
	(*rehead) = temp; 
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

void reverse(Node *curr)
{	
	if(curr == NULL)
		return;
	
	if(curr->next == NULL)
	{
		head = curr;
		return;
	}
	
	reverse(curr->next);
	
	curr->next->next = curr;
	curr->next = NULL;
}

int main()
{
	for(int i = 0; i<=5 ; i++)
	{
		push(&head,i);
	}
	print(head);
	reverse(head);
	print(head);
	return 0;
}


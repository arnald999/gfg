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

void swap(int *a, int *b) 
{ 
	int temp; 
	temp = *a; 
	*a = *b; 
	*b = temp; 
}

void pairwiseswap(Node *head)
{
	Node *temp = head;
	
	while(temp != NULL && temp->next != NULL)
	{
		swap(&temp->data, &temp->next->data);
		temp = temp->next->next;
	}
}


int main()
{
	Node *head = NULL;
	for(int i= 0; i< 10; i++)
	{
		push(&head, i);
	}
	print(head);
	pairwiseswap(head);
	print(head);
	
	return 0;
}

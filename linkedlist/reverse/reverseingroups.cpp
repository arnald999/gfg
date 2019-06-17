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


void reverse(Node **recurr)
{
	Node *curr = NULL;
	Node *prev = NULL;
	Node *next = *recurr;
	
	while(next != NULL)
	{
		curr = next;
		next = curr->next;
		
		curr->next = prev;
		prev = curr; 
	}
	
	*recurr = curr;
}

void reversekthnode(Node **rehead, int k)
{
	Node *temp = *rehead;
	Node *curr1 = *rehead;
	for(int i=1; i<k; i++)
	{
		temp = temp->next;
	}
	
	Node *curr2 = temp->next;
	temp->next = NULL;
	
	//print(curr1);
	//print(curr2);
	reverse(&curr1);
	//print(curr1);
	reverse(&curr2);
	//print(curr2);
	
	Node *tot = curr1;
	while(curr1->next != NULL)
	{
		curr1 = curr1->next;
	}
	curr1->next = curr2;
	
	*rehead = tot;
}

int main()
{
	Node *head = NULL;
	
	for(int i=1; i<=10; i++)
	{
		push(&head,i);
	}
	
	print(head);
	reverse(&head);
	print(head);
	reversekthnode(&head,3);
	print(head);
	return 0;
}

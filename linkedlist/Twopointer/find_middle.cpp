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
	Node *tmp = head;
	
	while(tmp != NULL)
	{
		cout<<tmp->data<<" ";
		tmp = tmp->next;
	}
	cout<<endl;
}

void findmiddle(Node *head)
{
	Node *fast = head;
	Node *slow = head;
	
	while(fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	
	cout<<slow->data<<endl;
}


int main()
{
	Node *head = NULL;
	
	for(int i=1; i<=6; i++)
	{
		push(&head,i);
		//findmiddle(head);
	}
	
	print(head);
	findmiddle(head);
	return 0;
}

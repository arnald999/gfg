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
	
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

Node *nlastnode(Node **rehead, int n)
{
	Node *curr = *rehead;
	Node *last = *rehead;
	
	for(int i=1; i<=n; i++)
	{
		last = last->next;
	}
	
	while(last!=NULL)
	{
		last = last->next;
		curr = curr->next;
	}
	
	return curr;
	//cout<<"N th node from last : "<<curr->data<<endl;
}

int main()
{
	Node *head = NULL;
	
	for(int i=10; i>0; i--)
	{
		push(&head,i);
	}
	
	print(head);
	cout<<"N th last node : "<<nlastnode(&head,3)->data<<endl;
	return 0;
}

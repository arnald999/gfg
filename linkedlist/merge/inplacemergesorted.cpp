#include <iostream>
#include <time.h>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
};


void push(Node **rehead, int k)
{
	Node *temp = new Node();
	temp->data = k;
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


Node *merge(Node *a, Node *b)
{
	if(a==NULL)
		return b;
		
	if(b==NULL)
		return a;
	
	//Node *result;
	if(a->data < b->data)
	{
		a->next = merge(a->next,b);
		return a;
	}
	
	else
	{
		b->next = merge(a,b->next);
		return b;
	}
	//return result;
}


int main()
{
	Node *newnode;
	
	Node *head1 = new Node();
	head1->data = 10;
	
	Node *head2 = new Node();
	head2->data = 3;
	
	newnode = new Node();
	newnode->data = 6;
	head2->next = newnode;
	
	newnode = new Node();
	newnode->data = 9;
	head2->next->next = newnode;
	
	newnode = new Node();
	newnode->data = 7;
	head1->next = newnode;
	//head2->next->next->next = newnode;
	
	newnode = new Node();
	newnode->data = 2;
	head1->next->next = newnode;
	//head2->next->next->next->next = newnode;
	
	print(head1);
	print(head2);
	
	Node *res = merge(head1, head2);
	print(res);
	return 0; 
}



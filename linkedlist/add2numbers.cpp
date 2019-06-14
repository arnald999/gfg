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

void reverse(Node **rehead)
{
	Node *curr = NULL;
	Node *prev = NULL;
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

void add2numbers(Node *a, Node *b)
{
	reverse(&a);
	reverse(&b);
	
	int result,carry;
	carry = 0;
	result = 0;
	Node *newhead = NULL;
	//Node *result;
	while(a!=NULL || b!=NULL)
	{
		//result = new Node();
		result = (a->data + b->data + carry)%10;
		carry = (a->data + b->data + carry)/10;
		//result->next = NULL;
		push(&newhead,result);
		if(a!=NULL)
			a = a->next;
		if(b!=NULL)
			b = b->next;
	}
	
	if(carry)
		push(&newhead,carry);
	
	print(newhead);
}


int main()
{
	Node *newnode;
	
	Node *head1 = new Node();
	head1->data = 5;
	
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
	
	add2numbers(head1, head2);
	//print(res);
	return 0; 
}

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

int count(Node *head)
{
	int cnt = 0;
	Node *temp = head;
	while(temp!=NULL)
	{
		cnt++;
		temp = temp->next;
	}
	return cnt;
} 

void intersection(Node *head1, Node *head2)
{
	int cnt1 = count(head1);
	int cnt2 = count(head2);
	int diff;
	
	cout<<cnt1<<endl;
	cout<<cnt2<<endl;
	
	Node *temp;
	Node *temp2;
	
	if(cnt1>cnt2)
	{
		diff = cnt1-cnt2;
		temp = head1;
		temp2 = head2;
	}
	else if(cnt2>cnt1)
	{
		diff = cnt2-cnt1;
		temp = head2;
		temp2 = head1;
	}
	
	for(int i=1; i<=diff; i++)
	{
		temp = temp->next;
	}
	
	while(temp != NULL && temp2 != NULL)
	{
		if(temp->data == temp2->data)
		{
			cout<<"Intersection point is : "<<temp->data<<endl;
			break;
		}
		temp = temp->next;
		temp2 = temp2->next;
	}
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
	head2->next->next->next = newnode;
	
	newnode = new Node();
	newnode->data = 2;
	head1->next->next = newnode;
	head2->next->next->next->next = newnode;
	
	print(head1);
	print(head2);
	
	intersection(head1,head2);
	
	return 0;
}

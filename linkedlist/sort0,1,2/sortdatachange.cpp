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


void sortlist(Node **rehead)
{
	Node *temp = *rehead;
	int count[3]={0,0,0};
	
	while(temp!=NULL)
	{
		if(temp->data == 0)
		{
			count[0] = count[0]+1;
		
		}
		else if(temp->data == 1)
		{
			count[1] = count[1]+1;
		}
		else if(temp->data == 2)
		{
			count[2] = count[2]+1;
		}
		temp = temp->next;
	}
	
	Node *newhead = NULL;
	for(int i=2; i>=0; i--)
	{
		while(count[i]--)
		{
			push(&newhead,i);
		}
	}
	*rehead = newhead;
}


int main()
{
	Node *head = NULL;
	
	for(int i=10; i>0; i--)
	{
		push(&head,i%3);
	}
	
	print(head);
	//cout<<"N th last node : "<<nlastnode(&head,3)->data<<endl;
	sortlist(&head);
	print(head);
	return 0;
}


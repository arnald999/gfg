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

void detectloop(Node **rehead)
{	
	Node *slow = *rehead;
	Node *fast = *rehead;
	
	if(slow ==  NULL || slow->next == NULL)
		return;
		
	int flag = 0;
	
	while(slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)
		{
			flag = 1;
			break;
		}
	}
	
	if(flag == 0)
	{
		cout<<"No loop detected"<<endl;
	}
	else if(flag == 1)
	{
		cout<<"FLAG Detected"<<endl;
		
		slow = *rehead;
		
		while(slow->next != fast->next)
		{
			slow = slow->next;
			fast = fast->next;
		}
		
		cout<<"Starting node of loop is : "<<slow->next->data<<endl;
		
		//Remove loop(break it)
		fast->next = NULL;
	}
}

int main()
{
	Node *newnode;
	Node *loop;
	
	Node *head = new Node();
	head->data = 10;
	
	newnode = new Node();
	newnode->data = 2;
	head->next = newnode;
	
	newnode = new Node();
	newnode->data = 4;
	head->next->next = newnode;
	loop = newnode;
	
	newnode = new Node();
	newnode->data = 7;
	head->next->next->next = newnode;
	
	newnode = new Node();
	newnode->data = 8;
	head->next->next->next->next = newnode;
	
	newnode->next = loop;
	
	//print(head);
	detectloop(&head);
	print(head);
	
	return 0;
}

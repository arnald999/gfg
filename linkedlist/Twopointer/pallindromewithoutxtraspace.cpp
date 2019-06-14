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


void checkpallindrome(Node *head)
{
	Node *temp1 = head;
	Node *slow = head;
	Node *fast = head;
	
	while(fast->next !=NULL && fast->next->next !=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	
	Node *temp2 = slow->next;
	slow->next = NULL;
	
	reverse(&temp2);
	
	
	print(temp1);
	print(temp2);
	
	int flag = 1;
	while(temp2 != NULL)
	{
		if(temp1->data != temp2->data)
		{
			flag=0;
			break;
		}
		
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	
	if(flag == 1)
	{
		cout<<"Pallindrome"<<endl;
	}
	else if(flag == 0)
	{
		cout<<"Not a Pallindrome"<<endl;
	}
}

int main()
{
	Node *newnode;
	
	Node *head1 = new Node();
	head1->data = 5;

	
	newnode = new Node();
	newnode->data = 3;
	head1->next = newnode;
	
	newnode = new Node();
	newnode->data = 1;
	head1->next->next = newnode;
	
	newnode = new Node();
	newnode->data = 2;
	head1->next->next->next = newnode;
	//head2->next->next->next = newnode;
	
	newnode = new Node();
	newnode->data = 5;
	head1->next->next->next->next = newnode;
	
	print(head1);
	
	checkpallindrome(head1);
	//print(res);
	return 0; 
}
